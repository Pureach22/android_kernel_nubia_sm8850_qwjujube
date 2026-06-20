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
  unsigned __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w9
  const char *v29; // x2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w4
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w0
  __int64 v48; // x22
  __int64 v49; // x0
  int v50; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v50 = 0;
  tsf_ptp_options = ucfg_fwol_get_tsf_ptp_options(v17, &v50);
  if ( !(_DWORD)tsf_ptp_options && (v50 & 4) != 0 )
    v19 = ktime_get(tsf_ptp_options);
  else
    v19 = ktime_get_with_offset(0);
  v28 = *(_BYTE *)(a1 + 39344);
  *(_QWORD *)(a1 + 52816) = 1000 * (v14 - v19 / 0x3E8);
  if ( (v28 & 1) == 0 )
  {
    v29 = "%s: Periodic TSF sync feature not enabled";
LABEL_25:
    qdf_trace_msg(0x33u, 8u, v29, v20, v21, v22, v23, v24, v25, v26, v27, "hdd_tsf_sync_init");
    if ( *(_DWORD *)(a1 + 39384) )
      goto LABEL_26;
LABEL_37:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Host Target sync has not initialized",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "__hdd_start_tsf_sync");
    result = 0;
    goto LABEL_16;
  }
  if ( *(_DWORD *)(a1 + 39384) )
  {
    v29 = "%s: Host Target sync has been initialized!!";
    goto LABEL_25;
  }
  v47 = qdf_mc_timer_init(a1 + 39176, 0, (__int64)hdd_capture_tsf_timer_expired_handler, a1);
  if ( v47 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to init target timer, ret: %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "hdd_tsf_sync_init",
      v47);
    *(_DWORD *)(a1 + 39384) = 0;
    goto LABEL_15;
  }
  v48 = *(_QWORD *)(a1 + 32);
  if ( v48 )
  {
    v49 = *(_QWORD *)v9;
    v50 = 0;
    if ( !(unsigned int)ucfg_fwol_get_tsf_ptp_options(v49, &v50) && (v50 & 8) != 0 )
      device_create_file(v48 + 1376, &dev_attr_tsf);
  }
  *(_DWORD *)(a1 + 39384) = 1;
  if ( !*(_DWORD *)(a1 + 39384) )
    goto LABEL_37;
LABEL_26:
  v38 = qdf_mc_timer_start(a1 + 39176, 0x64u);
  result = 0;
  if ( v38 && v38 != 6 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to start timer, ret: %d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "__hdd_start_tsf_sync");
    goto LABEL_15;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
