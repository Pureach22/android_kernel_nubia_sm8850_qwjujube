__int64 __fastcall wlan_hdd_listen_offload_start(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  __int64 v12; // x9
  int v13; // w10
  __int64 v14; // x8
  __int64 v15; // x9
  int v16; // w10
  __int64 v17; // x8
  unsigned int v18; // w19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  unsigned int v28; // [xsp+8h] [xbp-38h] BYREF
  __int64 v29; // [xsp+Ch] [xbp-34h]
  int v30; // [xsp+14h] [xbp-2Ch]
  __int64 v31; // [xsp+18h] [xbp-28h]
  int v32; // [xsp+20h] [xbp-20h]
  int v33; // [xsp+24h] [xbp-1Ch]
  __int64 v34; // [xsp+28h] [xbp-18h]
  __int64 v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: null param, adapter:%pK, params:%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_listen_offload_start",
      a1,
      a2);
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  v11 = **(_QWORD **)(a1 + 24);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: psoc is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_listen_offload_start",
      a1,
      a2);
    goto LABEL_7;
  }
  v12 = *(_QWORD *)(a2 + 4);
  v13 = *(_DWORD *)(a2 + 12);
  v28 = *(_DWORD *)a2;
  v29 = v12;
  v14 = *(_QWORD *)(a2 + 16);
  v15 = *(_QWORD *)(a2 + 24);
  v30 = v13;
  v16 = *(_DWORD *)(a2 + 32);
  v31 = v14;
  v17 = *(_QWORD *)(a2 + 40);
  v34 = v15;
  v35 = v17;
  LODWORD(v17) = *(_DWORD *)(a2 + 48);
  v32 = v16;
  v33 = v17;
  v18 = ucfg_p2p_lo_start(v11, &v28, a3, a4, a5, a6, a7, a8, a9, a10);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: p2p listen offload start, status:%d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wlan_hdd_listen_offload_start",
    v18);
  result = qdf_status_to_os_return(v18);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
