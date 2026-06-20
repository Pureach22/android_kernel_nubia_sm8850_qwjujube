__int64 __fastcall hdd_sysfs_dp_stc_logmask_show(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 *context; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int logmask; // w20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  int v40; // w0
  int v41; // w20
  double v42; // d0
  int v43; // w0
  int v44; // w20
  double v45; // d0
  int v46; // w0
  int v47; // w20
  int v48; // w0
  __int64 v49; // x19
  __int64 v50; // [xsp+0h] [xbp-10h] BYREF
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dp_stc_logmask_show", a1, a2, a3, a4, a5, a6, a7, a8);
  LODWORD(result) = _wlan_hdd_validate_context(
                      (__int64)context,
                      (__int64)"hdd_sysfs_dp_stc_logmask_show",
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20);
  if ( (_DWORD)result
    || (LODWORD(result) = _osif_psoc_sync_op_start(
                            *(_QWORD *)(context[3] + 488),
                            &v50,
                            (__int64)"hdd_sysfs_dp_stc_logmask_show"),
        (_DWORD)result) )
  {
    result = (int)result;
  }
  else
  {
    if ( wlan_hdd_validate_modules_state((__int64)context, v22, v23, v24, v25, v26, v27, v28, v29) )
    {
      logmask = ucfg_dp_stc_get_logmask(*context);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: STC log mask: 0x%x",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__hdd_sysfs_dp_stc_logmask_show",
        logmask,
        v50,
        v51);
      v39 = scnprintf(a11, 4096, "Current logmask: 0x%x\n", logmask);
      v41 = v40;
      v42 = scnprintf(a11 + v40, 4096LL - v40, "\nLogmask Details:\n", v39);
      v44 = v43 + v41;
      v45 = scnprintf(a11 + v44, 4096LL - v44, "BIT(0) - Enable Flow stats logging\n", v42);
      v47 = v44 + v46;
      scnprintf(a11 + v47, 4096LL - v47, "BIT(1) - Enable Classified Flow stats logging\n", v45);
      v49 = v47 + v48;
    }
    else
    {
      v49 = -22;
    }
    _osif_psoc_sync_op_stop(v50, (__int64)"hdd_sysfs_dp_stc_logmask_show");
    result = v49;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
