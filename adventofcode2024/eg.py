import re

corrupted_memory = """
who()where()don't()]mul(891,277)~mul(160,638)('don't()/@/%{mul(462,975)!^:+mul(317,407){who()/from()/mul(424,628) when()select()mul(415,352)!?[where(){?how()/mul(661^, -mul(141,973)(/where()!#who()(what()#$mul(916,889)when()$ )mul(945,846)why()+#where()@how()mul(147,694)%select()mul(414,149)< when(){)what()&[how()mul(903,731)~#mul(389,694)mul(72,447)mul(490,881)?++from()>+ ^(mul(703,722)mul(622,578)from() }@^)+mul(642,732)>from()where()@>${who()mul(526,211$why()[why()mul(349,908)who(635,389)from()what()*$*>@mul(180,150)//: ^mul(622,131);[-^~-mul(32,430)mul(306,173)~where()how() (mul(292,552)<mul(422,363)^<<!#when(304,583)who()mul(348,963)': #select(875,567)#>'where()!do() why()~] who()@^mul(20,119)?[$+/$^mul(242,536)who()'-&'from()mul(351,640){,]~mul(152,587)@select(140,751)<+mul(387,212)[where()%when())how()& >mul(916,539)~]?[when()>!when()??mul(322,151)!]!]~!;mul(27,537); ##;^}}mul(538,277)why()mul(205,526)mul(412,826)^@?where()'mul(957from(193,394)from(863,680)!@how()mul(771,563)( who()mul(377,655) ]select();who()mul(360,272)-select()$what(){mul(291,618)})from()^when(),how()where()don't()why()+&mul(462,803)^$,mul(788,584)@ %?:![:mul(439,528)mul(129,761)]!~mul(321,102)mul(41,728){&what()how()mul(93,933))[ where()^*@+mul(553,965select() '&{-mul(712,817)/<why()[:>/&mul(482,328)when()'mul(957,978)-}{[>{@what()who()mul(48,186)?]how()$what()&,)mul(33,872)#mul(125,207):;mul(143,386)how(),select()don't()}#when()%]&^@?^mul(107,59)&%?don't()mul(183,332):{}/[(#%-+mul(766,627)from()who() what()-+$^mul(41,791)who()] ;-#select()~mul(939,288)[:(</{$how()%select()mul(624,973) ]%mul(780,706)why(677,630);don't()+mul(3,844)$)$$where(),!why()[:mul(506,60)( <>@what()who()?mul(210,210)?select()why()select()where()-how()^mul(755,497)+?^(mul(860,478)^}+$from()(mul(565,649)}mul(184,450) ;/+%[why()mul(752,488)$how()mul(349,56)#'%,+mul(571,637)(mul(186,674)?how() </~@:%mul(295,276)'~where()-&%!mul(72,565);mul(140,645)%#-#*mul(258,568)!/select()why():&}from()from()don't()mul(458,777)#>,'^#!mul(577,819)mul(767,490)how()@when(359,565)mul(97,67)when()?where()>,'(-mul(267,998)%where()why()where():mul(593,317)<mul(514,327)how()~$[{mul(942,232)how()(who() 'from())mul(752,235)?/!'/*#mul(291,995){who()%!,%mul(873,542)%mul(543,144)from())'select()mul(317,658)+mul(819,545)<&what()who()$#who()how()$*mul(849,792)<;-mul(401,327)select()^}?mul(184,612))(where()what()[where()where()@}'mul(532,791)how()how()from()$*~:mul(963,569)when()%- :}why()^~$mul(520,245))^):{do()!mul(900,510)$ %who(615,822)mul(374,872)''/ mul(808,426)select()mul(268,752)&why(),</%!:!/don't()who(){when()*(where()mul(403,172)^mul(185,447)}mul(233,330)why()/&&%who()#/^mul(705,506)?%from();mul(494,15)['}]-}mul(45,474)who()@who()@why()don't()mul(174,355)?what(),@*$+#&mul(9,768);:^mul(381,691)when()&$/]?what(564,603)^how()mul(468,953)[@when()}mul(702,659) where()?where(){**mul(535,116)~where()$('}^~from()mul(926,18)&who()$when()where()>from(),mul(541,30)/why()${[from()who()  mul(732,465)[<!{mul(794,385)mul(676,776)who()]/mul(45,904)<~+who()@-!)&where()mul(49,63))mul(710,576)+mul(279,872)&<{what()-how(),&how()~
"""

pattern = r"mul\s*\((\d+),(\d+)\)"  # match mul(X,Y) with digits X and Y
dont_pattern = r"don't\(\)"

# Find all positions of "don't()"
dont_positions = [m.end() for m in re.finditer(dont_pattern, corrupted_memory)]

# Find all mul instructions with their positions
mul_instructions = [(m.start(), m.groups()) for m in re.finditer(pattern, corrupted_memory)]

# Filter out mul instructions that follow "don't()"
filtered_mul_instructions = [
    (x, y) for pos, (x, y) in mul_instructions
    if not any(dont_pos < pos for dont_pos in dont_positions)
]

result = sum(int(x) * int(y) for x, y in filtered_mul_instructions)

print(result)