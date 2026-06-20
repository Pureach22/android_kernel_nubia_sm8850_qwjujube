__int64 __fastcall hdd_start_tsf_sync(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x23
  const char *v15; // x2
  __int64 result; // x0
  __int64 v17; // x0
  __int64 tsf_ptp_options; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  unsigned __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  char v32; // w9
  const char *v33; // x2
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w4
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w0
  __int64 v52; // x22
  __int64 v53; // x0
  int v54; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+8h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_15;
  v9 = *(_QWORD *)(a1 + 24);
  if ( !v9 )
  {
    v15 = "%s: invalid hdd context";
LABEL_14:
    qdf_trace_msg(0x33u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_tsf_sync_init");
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  if ( !*(_DWORD *)(v9 + 3232) )
  {
    v15 = "%s: TSF feature has NOT been initialized";
    goto LABEL_14;
  }
  *(_DWORD *)(a1 + 39160) = 0;
  *(_QWORD *)(a1 + 39168) = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 39160);
    v12 = *(_QWORD *)(a1 + 39168);
  }
  else
  {
    raw_spin_lock_bh(a1 + 39160);
    v12 = *(_QWORD *)(a1 + 39168) | 1LL;
    *(_QWORD *)(a1 + 39168) = v12;
  }
  *(_QWORD *)(a1 + 38944) = 0;
  *(_QWORD *)(a1 + 38952) = 0;
  *(_QWORD *)(a1 + 38936) = 0;
  *(_QWORD *)(a1 + 39352) = 0;
  *(_QWORD *)(a1 + 39360) = 0;
  *(_QWORD *)(a1 + 39368) = 0;
  if ( (v12 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 39168) = v12 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 39160);
  }
  else
  {
    raw_spin_unlock(a1 + 39160);
  }
  __isb(0xFu);
  v13 = _ReadStatusReg(CNTVCT_EL0);
  if ( 10 * v13 >= v13 )
    v14 = 10 * v13 / 0xC0;
  else
    v14 = 10 * (v13 / 0xC0);
  v17 = *(_QWORD *)v9;
  v54 = 0;
  tsf_ptp_options = ucfg_fwol_get_tsf_ptp_options(v17, &v54);
  if ( !(_DWORD)tsf_ptp_options && (v54 & 4) != 0 )
    v23 = ktime_get(tsf_ptp_options, v19, v20, v21, v22);
  else
    v23 = ktime_get_with_offset(0);
  v32 = *(_BYTE *)(a1 + 39344);
  *(_QWORD *)(a1 + 52808) = 1000 * (v14 - v23 / 0x3E8);
  if ( (v32 & 1) == 0 )
  {
    v33 = "%s: Periodic TSF sync feature not enabled";
LABEL_25:
    qdf_trace_msg(0x33u, 8u, v33, v24, v25, v26, v27, v28, v29, v30, v31, "hdd_tsf_sync_init");
    if ( *(_DWORD *)(a1 + 39384) )
      goto LABEL_26;
LABEL_37:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Host Target sync has not initialized",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "__hdd_start_tsf_sync");
    result = 0;
    goto LABEL_16;
  }
  if ( *(_DWORD *)(a1 + 39384) )
  {
    v33 = "%s: Host Target sync has been initialized!!";
    goto LABEL_25;
  }
  v51 = qdf_mc_timer_init(a1 + 39176, 0, (__int64)hdd_capture_tsf_timer_expired_handler, a1);
  if ( v51 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to init target timer, ret: %d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "hdd_tsf_sync_init",
      v51);
    *(_DWORD *)(a1 + 39384) = 0;
    goto LABEL_15;
  }
  v52 = *(_QWORD *)(a1 + 32);
  if ( v52 )
  {
    v53 = *(_QWORD *)v9;
    v54 = 0;
    if ( !(unsigned int)ucfg_fwol_get_tsf_ptp_options(v53, &v54) && (v54 & 8) != 0 )
      device_create_file(v52 + 1376, &dev_attr_tsf);
  }
  *(_DWORD *)(a1 + 39384) = 1;
  if ( !*(_DWORD *)(a1 + 39384) )
    goto LABEL_37;
LABEL_26:
  v42 = qdf_mc_timer_start(a1 + 39176, 0x64u);
  result = 0;
  if ( v42 && v42 != 6 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to start timer, ret: %d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "__hdd_start_tsf_sync");
    goto LABEL_15;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
