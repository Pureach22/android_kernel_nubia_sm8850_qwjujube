__int64 __fastcall hdd_stop_tsf_sync(
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
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v21; // x8
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x19
  __int64 v33; // x0
  int v34; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_6;
  if ( !*(_QWORD *)(a1 + 24) )
  {
    qdf_trace_msg(0x33u, 2u, "%s: invalid hdd context", a2, a3, a4, a5, a6, a7, a8, a9, "__hdd_stop_tsf_sync");
    result = 4294967274LL;
    goto LABEL_26;
  }
  if ( !*(_DWORD *)(a1 + 39384) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Host Target sync has not initialized",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__hdd_stop_tsf_sync");
    goto LABEL_9;
  }
  v10 = qdf_mc_timer_stop(a1 + 39176);
  if ( !v10 )
  {
LABEL_9:
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 39160);
      v21 = *(_QWORD *)(a1 + 39168);
    }
    else
    {
      raw_spin_lock_bh(a1 + 39160);
      v21 = *(_QWORD *)(a1 + 39168) | 1LL;
      *(_QWORD *)(a1 + 39168) = v21;
    }
    *(_QWORD *)(a1 + 38944) = 0;
    *(_QWORD *)(a1 + 38952) = 0;
    *(_QWORD *)(a1 + 38936) = 0;
    *(_QWORD *)(a1 + 39352) = 0;
    *(_QWORD *)(a1 + 39360) = 0;
    *(_QWORD *)(a1 + 39368) = 0;
    if ( (v21 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 39168) = v21 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 39160);
      if ( *(_DWORD *)(a1 + 39384) )
        goto LABEL_15;
    }
    else
    {
      raw_spin_unlock(a1 + 39160);
      if ( *(_DWORD *)(a1 + 39384) )
      {
LABEL_15:
        *(_DWORD *)(a1 + 39384) = 0;
        v22 = qdf_mc_timer_destroy(a1 + 39176);
        if ( v22 )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to destroy target timer, ret: %d",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "hdd_tsf_sync_deinit",
            v22);
        v31 = *(_QWORD *)(a1 + 24);
        if ( v31 )
        {
          if ( *(_DWORD *)(v31 + 3236) && *(_QWORD *)(v31 + 3240) == a1 )
          {
            *(_QWORD *)(v31 + 3240) = 0;
            *(_DWORD *)(v31 + 3236) = 0;
          }
          v32 = *(_QWORD *)(a1 + 32);
          if ( v32 )
          {
            v33 = *(_QWORD *)v31;
            v34 = 0;
            if ( !(unsigned int)ucfg_fwol_get_tsf_ptp_options(v33, &v34) && (v34 & 8) != 0 )
              device_remove_file(v32 + 1376, &dev_attr_tsf);
          }
        }
      }
    }
    result = 0;
    goto LABEL_26;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Failed to stop target timer, ret: %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "__hdd_stop_tsf_sync",
    v10);
LABEL_6:
  result = 4294967274LL;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
