__int64 __fastcall rmnet_get_ethtool_stats(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 result; // x0
  __int64 v6; // x20
  _QWORD *stats; // x22
  __int64 v8; // x10
  __int64 v9; // x9
  __int64 v10; // x11
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x9
  __int64 v14; // x11
  __int64 v15; // x8
  __int64 v16; // x10
  __int64 v17; // x9
  __int64 v18; // x11
  __int64 v19; // x10
  __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x10
  __int64 v26; // [xsp+0h] [xbp-30h] BYREF
  __int64 v27; // [xsp+8h] [xbp-28h]
  __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h]
  __int64 v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = rmnet_get_port(*(_QWORD *)(a1 + 2696));
  if ( a3 )
  {
    v6 = result;
    if ( result )
    {
      stats = (_QWORD *)rmnet_ll_get_stats();
      memcpy(a3, (const void *)(a1 + 2720), 0x1C0u);
      memcpy(a3 + 56, (const void *)(v6 + 2496), 0xF8u);
      v8 = stats[1];
      v10 = stats[2];
      v9 = stats[3];
      a3[87] = *stats;
      a3[90] = v9;
      a3[89] = v10;
      a3[88] = v8;
      v11 = stats[4];
      v12 = stats[5];
      v26 = 0;
      v14 = stats[6];
      v13 = stats[7];
      v27 = 0;
      v28 = 0;
      a3[91] = v11;
      a3[94] = v13;
      a3[93] = v14;
      a3[92] = v12;
      v15 = stats[8];
      v16 = stats[9];
      v29 = 0;
      v30 = 0;
      v18 = stats[10];
      v17 = stats[11];
      a3[95] = v15;
      a3[98] = v17;
      a3[97] = v18;
      a3[96] = v16;
      v19 = stats[13];
      v21 = stats[14];
      v20 = stats[15];
      a3[99] = stats[12];
      a3[102] = v20;
      a3[101] = v21;
      a3[100] = v19;
      result = rmnet_ctl_get_stats(&v26, 5);
      v22 = v27;
      v23 = v28;
      a3[103] = v26;
      a3[104] = v22;
      v25 = v29;
      v24 = v30;
      a3[105] = v23;
      a3[106] = v25;
      a3[107] = v24;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
