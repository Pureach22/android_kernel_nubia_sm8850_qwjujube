__int64 __fastcall hdd_sysfs_dp_swlm_show(
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
  _QWORD *context; // x20
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
  _QWORD *v30; // x21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x8
  unsigned __int8 (__fastcall *v48)(_QWORD); // x8
  int v49; // w3
  __int64 v50; // x19
  int v51; // w0
  __int64 v52; // [xsp+0h] [xbp-10h] BYREF
  __int64 v53; // [xsp+8h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dp_swlm_show", a1, a2, a3, a4, a5, a6, a7, a8);
  LODWORD(result) = _wlan_hdd_validate_context(
                      (__int64)context,
                      (__int64)"hdd_sysfs_dp_swlm_show",
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20);
  if ( !(_DWORD)result )
  {
    LODWORD(result) = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v52, (__int64)"hdd_sysfs_dp_swlm_show");
    if ( !(_DWORD)result )
    {
      v30 = _cds_get_context(71, (__int64)"__hdd_sysfs_dp_swlm_show", v22, v23, v24, v25, v26, v27, v28, v29);
      if ( !wlan_hdd_validate_modules_state((__int64)context, v31, v32, v33, v34, v35, v36, v37, v38) )
      {
        v50 = -22;
LABEL_17:
        _osif_psoc_sync_op_stop(v52, (__int64)"hdd_sysfs_dp_swlm_show");
        result = v50;
        goto LABEL_4;
      }
      if ( v30 && *v30 && (v47 = *(_QWORD *)(*v30 + 64LL)) != 0 )
      {
        v48 = *(unsigned __int8 (__fastcall **)(_QWORD))(v47 + 272);
        if ( v48 )
        {
          if ( *((_DWORD *)v48 - 1) != 944657148 )
            __break(0x8228u);
          v49 = v48(v30);
          goto LABEL_16;
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "cdp_soc_is_swlm_enabled",
          v52,
          v53);
      }
      v49 = 0;
LABEL_16:
      scnprintf(a11, 4096, "dp_swlm enable: %d\n", v49);
      v50 = v51;
      goto LABEL_17;
    }
  }
  result = (int)result;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
