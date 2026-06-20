__int64 __fastcall hdd_sysfs_dp_swlm_store(
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
        __int64 a11,
        __int64 a12)
{
  _QWORD *context; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _QWORD *v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  bool v41; // w0
  __int64 v42; // x8
  int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w21
  __int64 v53; // x20
  char *v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x8
  _DWORD *v72; // x8
  __int64 v73; // x1
  __int64 v74; // x19
  __int64 v75; // [xsp+8h] [xbp-48h] BYREF
  unsigned int v76; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v78[4]; // [xsp+20h] [xbp-30h] BYREF
  char v79; // [xsp+40h] [xbp-10h]
  __int64 v80; // [xsp+48h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dp_swlm_store", a1, a2, a3, a4, a5, a6, a7, a8);
  LODWORD(result) = _wlan_hdd_validate_context(
                      (__int64)context,
                      (__int64)"hdd_sysfs_dp_swlm_store",
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22);
  if ( (_DWORD)result
    || (LODWORD(result) = _osif_psoc_sync_op_start(
                            *(_QWORD *)(context[3] + 488LL),
                            &v75,
                            (__int64)"hdd_sysfs_dp_swlm_store"),
        (_DWORD)result) )
  {
    result = (int)result;
  }
  else
  {
    v79 = 0;
    memset(v78, 0, sizeof(v78));
    v76 = 0;
    v32 = _cds_get_context(71, (__int64)"__hdd_sysfs_dp_swlm_store", v24, v25, v26, v27, v28, v29, v30, v31);
    v41 = wlan_hdd_validate_modules_state((__int64)context, v33, v34, v35, v36, v37, v38, v39, v40);
    v42 = -22;
    if ( v41 && v32 )
    {
      v43 = hdd_sysfs_validate_and_copy_buf(v78, 33, a11, a12);
      if ( v43 )
      {
        v52 = v43;
        v53 = jiffies;
        if ( _hdd_sysfs_dp_swlm_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "__hdd_sysfs_dp_swlm_store");
          _hdd_sysfs_dp_swlm_store___last_ticks = v53;
        }
        v42 = v52;
      }
      else
      {
        stringp = (char *)v78;
        v54 = strsep(&stringp, " ");
        if ( v54 && !(unsigned int)kstrtouint(v54, 0, &v76) )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: dp_swlm: %d",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "__hdd_sysfs_dp_swlm_store",
            v76);
          if ( *v32 && (v71 = *(_QWORD *)(*v32 + 64LL)) != 0 )
          {
            v72 = *(_DWORD **)(v71 + 264);
            if ( v72 )
            {
              v73 = v76;
              if ( *(v72 - 1) != 261447488 )
                __break(0x8228u);
              ((void (__fastcall *)(_QWORD *, __int64))v72)(v32, v73);
            }
          }
          else
          {
            qdf_trace_msg(
              0x89u,
              8u,
              "%s: Invalid Instance:",
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              "cdp_soc_set_swlm_enable");
          }
          v42 = a12;
        }
        else
        {
          v42 = -22;
        }
      }
    }
    v74 = v42;
    _osif_psoc_sync_op_stop(v75, (__int64)"hdd_sysfs_dp_swlm_store");
    result = v74;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
