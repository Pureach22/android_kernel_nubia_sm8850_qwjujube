__int64 __fastcall wlan_hdd_fill_rate_info(__int64 a1, _DWORD *a2)
{
  unsigned int v2; // w8
  unsigned int v5; // w9
  __int64 v6; // x19
  int rate_flags; // w0
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  int v12; // w8
  int v13; // w9
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w8
  int v23; // w9
  int v24; // w0
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v37; // [xsp+0h] [xbp-20h]
  __int64 v38; // [xsp+0h] [xbp-20h]
  int v39; // [xsp+8h] [xbp-18h]
  int v40; // [xsp+10h] [xbp-10h]

  v2 = a2[14];
  *(_DWORD *)(a1 + 48) = v2;
  v5 = a2[15];
  *(_DWORD *)(a1 + 60) = (unsigned __int16)v5 >> 14;
  v6 = a1 + 60;
  *(_BYTE *)(a1 + 66) = (v5 & 0x10000000) != 0;
  *(_BYTE *)(a1 + 64) = (v5 >> 11) & 7;
  *(_BYTE *)(a1 + 52) = BYTE1(v5) & 7;
  *(_BYTE *)(a1 + 53) = ((unsigned __int8)v5 >> 5) + 1;
  *(_BYTE *)(a1 + 54) = v5 & 0x1F;
  rate_flags = hdd_get_rate_flags(v2 / 0x64uLL);
  v8 = *(unsigned int *)(a1 + 48);
  v9 = *(unsigned __int8 *)(v6 + 4);
  v10 = *(unsigned __int8 *)(v6 - 8);
  v11 = *(unsigned __int8 *)(v6 - 7);
  v12 = *(unsigned __int8 *)(v6 - 6);
  v13 = *(unsigned __int8 *)(v6 + 6);
  *(_DWORD *)(v6 - 4) = rate_flags;
  v39 = rate_flags;
  v40 = v13;
  v37 = v12;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: tx rate %d bw %d mode %d nss %d mcs %d flags %x ver %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wlan_hdd_fill_rate_info",
    v8,
    v9,
    v10,
    v11,
    v37,
    v39,
    v40);
  v22 = a2[16];
  *(_DWORD *)(v6 + 8) = v22;
  v23 = a2[17];
  *(_BYTE *)(v6 + 14) = v23 & 0x1F;
  *(_BYTE *)(v6 + 12) = BYTE1(v23) & 7;
  *(_BYTE *)(v6 + 13) = ((unsigned __int8)v23 >> 5) + 1;
  v24 = hdd_get_rate_flags(v22 / 0x64uLL);
  v25 = *(unsigned __int8 *)(v6 + 12);
  v26 = *(unsigned __int8 *)(v6 + 13);
  v27 = *(unsigned __int8 *)(v6 + 14);
  *(_DWORD *)(v6 + 16) = v24;
  LODWORD(v38) = v24;
  return qdf_trace_msg(
           0x33u,
           4u,
           "%s: rx: mode %d nss %d mcs %d rate_flags %x flags %x",
           v28,
           v29,
           v30,
           v31,
           v32,
           v33,
           v34,
           v35,
           "wlan_hdd_fill_rate_info",
           v25,
           v26,
           v27,
           v38);
}
