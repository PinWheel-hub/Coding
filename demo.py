

class OptimalMix():
    # 定义构造方法
    # (opti_total ,  opti_pb    ,  opti_fesi  ,  opti_casi  ,  opti_ss2)

    def __init__(self, re_batch_objs, x0, selected, optindex):
        self.x0 = np.array(x0)
        self.selected = selected
        self.optindex = optindex

        dat = calcmixindex(None, re_batch_objs)
        self.dat = dat['numpy']

        bl = np.array(x0)
        bu = np.array(x0) + 0.001
        for i in selected:
            bl[i] = 0
            bu[i] = optindex[0]
        self.bounds = Bounds(bl, bu)

        self.linear_constraint = LinearConstraint([[1] * len(x0)], [optindex[0]], [optindex[0]])

    # 定义普通方法
    def lossfun(self, x):
        xx = x / np.sum(x)
        ret = {}
        loss = 0
        ret['pct_pb'] = np.sum(xx * self.dat[:, 2])
        ret['pct_zn'] = np.sum(xx * self.dat[:, 3])
        ret['pct_cu'] = np.sum(xx * self.dat[:, 4])
        ret['pct_fe'] = np.sum(xx * self.dat[:, 5])
        ret['pct_sio2'] = np.sum(xx * self.dat[:, 6])
        ret['pct_cao'] = np.sum(xx * self.dat[:, 7])
        ret['pct_s'] = np.sum(xx * self.dat[:, 8])
        # ret['pct_as'] = np.sum(xx * self.dat[:, 9])
        # ret['pct_sb'] = np.sum(xx * self.dat[:, 10])
        # ret['pct_au'] = np.sum(xx * self.dat[:, 11])
        # ret['pct_ag'] = np.sum(xx * self.dat[:, 12])
        ret['pct_s2'] = np.sum(xx * self.dat[:, 13])
        loss += abs(self.optindex[1] - ret['pct_pb'])
        loss += 5 * abs(self.optindex[2] * ret['pct_sio2'] - ret['pct_fe'] * 1.2865)
        loss += 5 * abs(self.optindex[3] * ret['pct_sio2'] - ret['pct_cao'])

        sloss = ret['pct_s'] * self.optindex[4] - ret['pct_s2']
        if sloss < 0: sloss = 0
        loss += 2.5*sloss
        return loss
        # ret['feo_si'] = ret['pct_fe'] / ret['pct_sio2'] * 1.2865
        # ret['cao_si'] = ret['pct_cao'] / ret['pct_sio2']
        # ret['fe_zn'] = ret['pct_fe'] / ret['pct_zn']
        # ret['s_s2'] = ret['pct_s2'] / ret['pct_s']

    def opticalc(self):
            res = minimize(self.lossfun, self.x0, method='trust-constr',
                        constraints=[self.linear_constraint, ], bounds=self.bounds)
            print(res)
            return res.x