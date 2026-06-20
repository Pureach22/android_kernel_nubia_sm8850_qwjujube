__int64 __fastcall wlan_cm_init_score_config(__int64 a1, unsigned __int8 *a2)
{
  int v4; // w9
  int v5; // w11
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w0
  int v15; // w10
  int v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w9
  int v19; // w8
  unsigned int v20; // w9
  int v21; // w8
  unsigned int v22; // w9
  int v23; // w8
  unsigned int v24; // w9
  int v25; // w8
  unsigned int v26; // w9
  int v27; // w8
  unsigned int v28; // w9
  int v29; // w8
  unsigned int v30; // w9
  int v31; // w8
  unsigned int v32; // w9
  int v33; // w8
  char v34; // w8
  unsigned __int8 v35; // w9
  unsigned int v36; // w9
  int v37; // w8
  __int64 result; // x0
  unsigned int v39; // w9
  unsigned int v40; // w8

  *a2 = *(_DWORD *)(cfg_psoc_get_values(a1) + 868);
  a2[1] = *(_DWORD *)(cfg_psoc_get_values(a1) + 872);
  a2[2] = *(_DWORD *)(cfg_psoc_get_values(a1) + 876);
  a2[3] = *(_DWORD *)(cfg_psoc_get_values(a1) + 880);
  a2[4] = *(_DWORD *)(cfg_psoc_get_values(a1) + 884);
  a2[5] = *(_DWORD *)(cfg_psoc_get_values(a1) + 888);
  a2[6] = *(_DWORD *)(cfg_psoc_get_values(a1) + 892);
  a2[7] = *(_DWORD *)(cfg_psoc_get_values(a1) + 896);
  a2[8] = *(_DWORD *)(cfg_psoc_get_values(a1) + 900);
  a2[9] = *(_DWORD *)(cfg_psoc_get_values(a1) + 904);
  a2[10] = *(_DWORD *)(cfg_psoc_get_values(a1) + 908);
  a2[11] = *(_DWORD *)(cfg_psoc_get_values(a1) + 912);
  a2[12] = *(_DWORD *)(cfg_psoc_get_values(a1) + 916);
  v4 = *(_DWORD *)(cfg_psoc_get_values(a1) + 920);
  a2[14] = 4;
  a2[13] = v4;
  v5 = *(_DWORD *)(cfg_psoc_get_values(a1) + 924);
  v14 = a2[14];
  v15 = a2[10] + a2[11] + a2[12] + a2[13];
  v16 = *a2 + (unsigned __int8)v5 + a2[1] + a2[2] + a2[3] + a2[4] + a2[5] + a2[6] + a2[7] + a2[8] + a2[9];
  a2[15] = v5;
  if ( (unsigned int)(v16 + v15 + v14) >= 0xC9 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Total weight greater than %d, using default weights",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cm_init_score_config",
      200);
    *((_DWORD *)a2 + 2) = 84018442;
    *(_QWORD *)a2 = 0x214020C02010214LL;
    *((_WORD *)a2 + 6) = 7683;
    a2[15] = 20;
  }
  a2[16] = *(_DWORD *)(cfg_psoc_get_values(a1) + 928);
  a2[17] = *(_DWORD *)(cfg_psoc_get_values(a1) + 932);
  a2[18] = *(_DWORD *)(cfg_psoc_get_values(a1) + 936);
  a2[19] = *(_DWORD *)(cfg_psoc_get_values(a1) + 940);
  a2[20] = *(_DWORD *)(cfg_psoc_get_values(a1) + 944);
  a2[21] = *(_DWORD *)(cfg_psoc_get_values(a1) + 948);
  a2[22] = *(_DWORD *)(cfg_psoc_get_values(a1) + 952);
  a2[23] = *(_DWORD *)(cfg_psoc_get_values(a1) + 956);
  a2[24] = *(_DWORD *)(cfg_psoc_get_values(a1) + 960);
  a2[28] = *(_DWORD *)(cfg_psoc_get_values(a1) + 976);
  v17 = *(_DWORD *)(cfg_psoc_get_values(a1) + 980);
  if ( (unsigned __int8)v17 > 0x64u )
    v17 = v17 & 0xFFFFFF00 | 0x64;
  if ( (v17 & 0xFF00) > 0x6400 )
    v17 = v17 & 0xFFFF00FF | 0x6400;
  if ( (v17 & 0xFF0000) > 0x640000 )
    v17 = v17 & 0xFF00FFFF | 0x640000;
  if ( HIBYTE(v17) > 0x64u )
    v17 = v17 & 0xFFFFFF | 0x64000000;
  *((_DWORD *)a2 + 8) = v17;
  v18 = *(_DWORD *)(cfg_psoc_get_values(a1) + 984);
  if ( (unsigned __int8)v18 > 0x64u )
    v18 = v18 & 0xFFFFFF00 | 0x64;
  if ( (v18 & 0xFF00) > 0x6400 )
    v18 = v18 & 0xFFFF00FF | 0x6400;
  if ( (v18 & 0xFF0000) > 0x640000 )
    v18 = v18 & 0xFF00FFFF | 0x640000;
  v19 = v18 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v18) <= 0x64u )
    v19 = v18;
  *((_DWORD *)a2 + 9) = v19;
  v20 = *(_DWORD *)(cfg_psoc_get_values(a1) + 988);
  if ( (unsigned __int8)v20 > 0x64u )
    v20 = v20 & 0xFFFFFF00 | 0x64;
  if ( (v20 & 0xFF00) > 0x6400 )
    v20 = v20 & 0xFFFF00FF | 0x6400;
  if ( (v20 & 0xFF0000) > 0x640000 )
    v20 = v20 & 0xFF00FFFF | 0x640000;
  v21 = v20 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v20) <= 0x64u )
    v21 = v20;
  *((_DWORD *)a2 + 10) = v21;
  v22 = *(_DWORD *)(cfg_psoc_get_values(a1) + 992);
  if ( (unsigned __int8)v22 > 0x64u )
    v22 = v22 & 0xFFFFFF00 | 0x64;
  if ( (v22 & 0xFF00) > 0x6400 )
    v22 = v22 & 0xFFFF00FF | 0x6400;
  if ( (v22 & 0xFF0000) > 0x640000 )
    v22 = v22 & 0xFF00FFFF | 0x640000;
  v23 = v22 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v22) <= 0x64u )
    v23 = v22;
  *((_DWORD *)a2 + 11) = v23;
  a2[48] = *(_DWORD *)(cfg_psoc_get_values(a1) + 996);
  v24 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1000);
  if ( (unsigned __int8)v24 > 0x64u )
    v24 = v24 & 0xFFFFFF00 | 0x64;
  if ( (v24 & 0xFF00) > 0x6400 )
    v24 = v24 & 0xFFFF00FF | 0x6400;
  if ( (v24 & 0xFF0000) > 0x640000 )
    v24 = v24 & 0xFF00FFFF | 0x640000;
  v25 = v24 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v24) <= 0x64u )
    v25 = v24;
  *((_DWORD *)a2 + 13) = v25;
  v26 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1004);
  if ( (unsigned __int8)v26 > 0x64u )
    v26 = v26 & 0xFFFFFF00 | 0x64;
  if ( (v26 & 0xFF00) > 0x6400 )
    v26 = v26 & 0xFFFF00FF | 0x6400;
  if ( (v26 & 0xFF0000) > 0x640000 )
    v26 = v26 & 0xFF00FFFF | 0x640000;
  v27 = v26 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v26) <= 0x64u )
    v27 = v26;
  *((_DWORD *)a2 + 14) = v27;
  v28 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1008);
  if ( (unsigned __int8)v28 > 0x64u )
    v28 = v28 & 0xFFFFFF00 | 0x64;
  if ( (v28 & 0xFF00) > 0x6400 )
    v28 = v28 & 0xFFFF00FF | 0x6400;
  if ( (v28 & 0xFF0000) > 0x640000 )
    v28 = v28 & 0xFF00FFFF | 0x640000;
  v29 = v28 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v28) <= 0x64u )
    v29 = v28;
  *((_DWORD *)a2 + 15) = v29;
  v30 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1012);
  if ( (unsigned __int8)v30 > 0x64u )
    v30 = v30 & 0xFFFFFF00 | 0x64;
  if ( (v30 & 0xFF00) > 0x6400 )
    v30 = v30 & 0xFFFF00FF | 0x6400;
  if ( (v30 & 0xFF0000) > 0x640000 )
    v30 = v30 & 0xFF00FFFF | 0x640000;
  v31 = v30 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v30) <= 0x64u )
    v31 = v30;
  *((_DWORD *)a2 + 16) = v31;
  v32 = *(_DWORD *)(cfg_psoc_get_values(a1) + 972);
  if ( (unsigned __int8)v32 > 0x64u )
    v32 = v32 & 0xFFFFFF00 | 0x64;
  if ( (v32 & 0xFF00) > 0x6400 )
    v32 = v32 & 0xFFFF00FF | 0x6400;
  if ( (v32 & 0xFF0000) > 0x640000 )
    v32 = v32 & 0xFF00FFFF | 0x640000;
  v33 = v32 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v32) <= 0x64u )
    v33 = v32;
  *((_DWORD *)a2 + 19) = v33;
  a2[80] = a2[80] & 0xFE | *(_BYTE *)(cfg_psoc_get_values(a1) + 1016) & 1;
  v34 = *(_BYTE *)(cfg_psoc_get_values(a1) + 1020);
  v35 = a2[80];
  if ( v34 )
    a2[15] = 0;
  a2[80] = v35 & 0xFB | (4 * v34) | 2;
  a2[80] = a2[80] & 0xF7 | (8 * *(_BYTE *)(cfg_psoc_get_values(a1) + 1021));
  *((_DWORD *)a2 + 21) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1024);
  v36 = *(_DWORD *)(cfg_psoc_get_values(a1) + 964);
  if ( (unsigned __int8)v36 > 0x64u )
    v36 = v36 & 0xFFFFFF00 | 0x64;
  if ( (v36 & 0xFF00) > 0x6400 )
    v36 = v36 & 0xFFFF00FF | 0x6400;
  if ( (v36 & 0xFF0000) > 0x640000 )
    v36 = v36 & 0xFF00FFFF | 0x640000;
  v37 = v36 & 0xFFFFFF | 0x64000000;
  if ( v36 <= 0x64FFFFFF )
    v37 = v36;
  *((_DWORD *)a2 + 17) = v37;
  result = cfg_psoc_get_values(a1);
  v39 = *(_DWORD *)(result + 968);
  *((_DWORD *)a2 + 23) = 6566425;
  v40 = v39 & 0xFFFFFF00 | 0x64;
  if ( (unsigned __int8)v39 <= 0x64u )
    v40 = v39;
  if ( (v40 & 0xFF00) > 0x6400 )
    v40 = v40 & 0xFFFF00FF | 0x6400;
  if ( (v40 & 0xFF0000) > 0x640000 )
    v40 = v40 & 0xFF00FFFF | 0x640000;
  if ( v40 > 0x64FFFFFF )
    v40 = v40 & 0xFFFFFF | 0x64000000;
  *((_DWORD *)a2 + 18) = v40;
  return result;
}
