__int64 __fastcall trig_show(__int64 a1, int a2, char *s)
{
  unsigned __int8 *v3; // x21
  __int64 v5; // x23
  __int64 v6; // x23

  v3 = *(unsigned __int8 **)(a1 + 152);
  v5 = snprintf(
         s,
         0x1000u,
         "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%"
         "d, trig_bst=%d\n",
         1,
         v3[1343],
         v3[1344],
         v3[1345],
         v3[1347],
         v3[1346],
         v3[1348],
         v3[1341],
         v3[1342]);
  v6 = v5
     + snprintf(
         &s[v5],
         4096 - v5,
         "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%"
         "d, trig_bst=%d\n",
         2,
         v3[1356],
         v3[1357],
         v3[1358],
         v3[1360],
         v3[1359],
         v3[1361],
         v3[1354],
         v3[1355]);
  return v6
       + snprintf(
           &s[v6],
           4096 - v6,
           "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk"
           "=%d, trig_bst=%d\n",
           3,
           v3[1369],
           v3[1370],
           v3[1371],
           v3[1373],
           v3[1372],
           v3[1374],
           v3[1367],
           v3[1368]);
}
