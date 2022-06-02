# 一个简单的奶茶店管理系统
- 吉林大学大一下学期程序设计基础的课程设计小组作品
## 基本信息
- 每条订单包括顾客信息，饮品信息，价格三部分，除此之外，系统还需包括库存管理部分，该部分需管理原料库存与进出货信息。请自行组织相关信息的存储方式和显示格式；
- 管理系统所管理食品仅有各种饮品；
- 顾客信息包括：顾客姓名、顾客会员信息、顾客会员积分；
- 饮品信息包括：饮品种类、饮品规格、饮品加料、饮品温度、饮品糖度；
- 饮品可在特定情况进行打折销售
- 原料库存信息包括：原料种类、原料数量
- 进出货信息包括：进货原料种类、进货原料数量、进货原料、原料单价、总价。
- 系统内按天数进行计时，每日都需进行一次原料进货，并统计当天营业额与盈利额，并保证总资产不低于0元。
## 简化
- 时间包括月、日（仅是当年）。
- 饮品类型（最多10种），每种饮品可以制作热饮、常温、冷饮、甜度可制作多糖、少糖、无糖，金额精确到元、角，每种饮品有配料最多15种；
- 供应商、客户自行拟定，尽可能符合实际情况。提醒：供应商、客户可能重名。
- 客户购买记录储存在文件中，并根据记录来增加积分以及会员等级。
- 金额要精确到元、角、分，不允许有误差，最高不超过1000元；最大数量不超过int允许最大类型；
- 原料最多15种，原料库存量的单位为克（g），每种原料的最大数量不超过int允许的最大整数；
- 顾客一次性最多可以订购10杯饮品；
- 顾客购买记录储存在文件中；
## 功能
- 开始时，管理系统有运营资本100万元；
- 【增加】能够从文件中录入多条进货/销售记录，也能够随时录入1条进货/销售记录，有冲账功能。（同时考虑各种不规范、不合理或者错误的数据，如输入格式不对、编码位数不对、输入乱码一样）；
- 【增加】能够从文件中读入某位顾客的会员信息。（如果查询到这位顾客已经是会员，则不再录入）；
- 【修改】能够随时修改1条进货/销售记录。按照财务规范，如需修改错误的销售记录，应将当前错误的销售记录予以撤销后，在补充添加正确的销售记录；
- 【修改】如果在饮品还未开始制作前顾客改单，则可随时修改顾客订单；
- 【修改】能够随时增加某位顾客的会员积分；
- 【删除】能够随时删除1条进货/销售记录（能够查询到删除过的记录）;
- 【查询】能够按照合理顺序打印某种原料的进货、饮品的销售信息（按照原料种类检索）；
- 【查询】能够按照合理顺序打印某次历史进货信息（按照日期检索）；
- 【查询】能够按照合理顺序打印某个顾客的历史购买信息（按照客户标识检索）；
- 【查询】历史信息存在于多个记录文件，不同文件的记录
- 【统计】能够统计营业额（销售总额）、盈利额（销售总额减除销售商品的进货总额）；能够生成目前的库存报表；
- 【统计】能够统计所有原料剩余情况（若某饮品原料耗尽，则告知顾客售罄）；
- 【赠品】在给定饮品范围内由客户自主选择赠送的饮品；
- 【错误】若顾客提出的要求超出销售范围，则提示超出销售范围；若顾客没有提出任何要求，则不作处理；
- 【某个时间范围】能够打印某段时间范围内所有销售信息；
- 【某个时间范围】进货价格随时间不同而有所波动，存在价格调整；
- 【储存】能够将当前系统中的所有信息保存到文件中。
- 【储存】历史信息存于多个记录文件，不同文件中的记录可能有重复、冲突；
