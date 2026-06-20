__int64 __fastcall lim_notify_channel_switch_started(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  int v6; // w8
  double v7; // d0
  int v8; // w0
  unsigned int v9; // w1
  unsigned int v10; // w2
  __int64 v11; // x0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int128 v19; // kr00_16
  __int64 (__fastcall *v20)(__int64, __int64 *); // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _BYTE v29[24]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v30; // [xsp+18h] [xbp-38h] BYREF
  __int64 v31; // [xsp+20h] [xbp-30h]
  __int64 v32; // [xsp+28h] [xbp-28h]
  __int64 v33; // [xsp+30h] [xbp-20h]
  __int64 v34; // [xsp+38h] [xbp-18h]
  __int64 v35; // [xsp+40h] [xbp-10h]
  __int64 v36; // [xsp+48h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  memset(&v29[4], 0, 20);
  result = _qdf_mem_malloc(0x34u, "lim_notify_channel_switch_started", 11125);
  if ( result )
  {
    v5 = result;
    *(_DWORD *)result = 3413155;
    *(_BYTE *)(result + 4) = *(_BYTE *)(a2 + 10);
    v6 = *(_DWORD *)(a2 + 7204);
    *(_DWORD *)(result + 44) = 0;
    *(_DWORD *)(result + 8) = v6;
    qdf_mem_copy((void *)(result + 36), (const void *)(a2 + 24), 6u);
    v7 = wma_chan_phy_mode(*(unsigned int *)(a2 + 7204), *(unsigned int *)(a2 + 7212), *(unsigned __int8 *)(a2 + 154));
    *(_DWORD *)(v5 + 48) = v8;
    v9 = *(_DWORD *)(a2 + 7204);
    v10 = *(unsigned __int8 *)(a2 + 7211);
    v11 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 216LL);
    *(_DWORD *)v29 = *(_DWORD *)(a2 + 7212);
    wlan_reg_set_channel_params_for_pwrmode(v11, v9, v10, (__int64)v29, 0, v7, v12, v13, v14, v15, v16, v17, v18);
    v19 = *(_OWORD *)&v29[8];
    *(_QWORD *)(v5 + 12) = *(_QWORD *)v29;
    *(_OWORD *)(v5 + 20) = v19;
    LOWORD(v30) = 5283;
    v20 = *(__int64 (__fastcall **)(__int64, __int64 *))(a1 + 12416);
    v31 = v5;
    if ( *((_DWORD *)v20 - 1) != -1829016265 )
      __break(0x8228u);
    result = v20(a1, &v30);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: channel switch started notify failed",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_notify_channel_switch_started");
      result = _qdf_mem_free(v5);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
