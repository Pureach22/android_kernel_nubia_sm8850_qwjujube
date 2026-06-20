__int64 __fastcall gen7_complete_rpmh_votes(__int64 a1, int a2)
{
  int v4; // w12
  int v5; // w13
  int v6; // w25
  unsigned int v7; // w8
  int v8; // w26
  int v9; // w27
  int v10; // w28
  int v11; // w23
  int v12; // w21
  int v13; // w24
  int v14; // w1
  unsigned int v15; // w8
  unsigned __int64 v16; // t2
  int v17; // w22
  int v18; // w22
  int v19; // w21
  int v20; // w22
  int v21; // w21
  int v22; // w21
  int v23; // w22
  int v24; // w21
  int v25; // w21
  __int64 result; // x0
  __int64 v27; // x8
  unsigned int v28; // w19
  int v29; // [xsp+8h] [xbp-8h]
  int v30; // [xsp+Ch] [xbp-4h]

  v4 = 2354;
  v5 = 2186;
  v6 = 2018;
  v7 = **(_DWORD **)(a1 + 16040);
  v8 = 1850;
  v9 = 1682;
  v10 = 1514;
  v11 = 1346;
  v12 = 1178;
  v13 = 1010;
  v14 = 842;
  if ( v7 - 459264 >= 2 && v7 != 460288 && v7 >> 1 != 230528 )
  {
    HIDWORD(v16) = v7 - 461568;
    LODWORD(v16) = v7 - 461568;
    v15 = v16 >> 8;
    if ( v15 > 6 )
    {
      v4 = 2350;
      v5 = 2182;
      v6 = 2014;
      v8 = 1846;
      v9 = 1678;
      v10 = 1510;
      v11 = 1342;
      v12 = 1174;
      v13 = 1006;
      v14 = 838;
    }
    else
    {
      v14 = dword_157C50[v15];
      v13 = dword_157C6C[v15];
      v12 = dword_157C88[v15];
      v11 = dword_157CA4[v15];
      v10 = dword_157CC0[v15];
      v9 = dword_157CDC[v15];
      v8 = dword_157CF8[v15];
      v6 = dword_157D14[v15];
      v5 = dword_157D30[v15];
      v4 = dword_157D4C[v15];
    }
  }
  v29 = v5;
  v30 = v4;
  v17 = gen7_timed_poll_check_rscc(a1, v14, 1, a2, 1);
  v18 = gen7_timed_poll_check_rscc(a1, v13, 1, a2, 1) | v17;
  v19 = gen7_timed_poll_check_rscc(a1, v12, 1, a2, 1);
  v20 = gen7_timed_poll_check_rscc(a1, v11, 1, a2, 1) | v19 | v18;
  v21 = gen7_timed_poll_check_rscc(a1, v10, 1, a2, 1);
  v22 = gen7_timed_poll_check_rscc(a1, v9, 1, a2, 1) | v21;
  v23 = gen7_timed_poll_check_rscc(a1, v8, 1, a2, 1) | v22 | v20;
  v24 = gen7_timed_poll_check_rscc(a1, v6, 1, a2, 1);
  v25 = gen7_timed_poll_check_rscc(a1, v29, 1, a2, 1) | v24;
  result = (unsigned int)gen7_timed_poll_check_rscc(a1, v30, 1, a2, 1) | v25 | v23;
  if ( (_DWORD)result )
  {
    v27 = *(_QWORD *)(a1 + 3320);
    v28 = result;
    dev_err(v27 + 16, "RPMH votes timedout: %d\n", result);
    return v28;
  }
  return result;
}
