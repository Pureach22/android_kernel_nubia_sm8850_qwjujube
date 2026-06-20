__int64 __fastcall wlan_hdd_bus_resume(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char driver_state; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  _QWORD *v45; // x0
  __int64 v46; // x19
  unsigned int v47; // w0
  unsigned int v48; // w22
  const char *v49; // x2
  const char *v50; // x2
  unsigned int v51; // w1
  unsigned int v52; // w0
  unsigned int v53; // w0
  unsigned int v54; // w0
  unsigned int v55; // w0
  unsigned int v56; // w0
  _QWORD *v57; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w0
  unsigned int v67; // w0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // [xsp+Ch] [xbp-14h] BYREF
  int v93; // [xsp+14h] [xbp-Ch]
  __int64 v94; // [xsp+18h] [xbp-8h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"wlan_hdd_bus_resume", a2, a3, a4, a5, a6, a7, a8, a9);
  v93 = 0;
  driver_state = cds_get_driver_state(v11, v12, v13, v14, v15, v16, v17, v18);
  result = 0;
  if ( (driver_state & 8) == 0 )
  {
    qdf_trace_msg(0x33u, 4u, "%s: starting bus resume", v20, v21, v22, v23, v24, v25, v26, v27, "wlan_hdd_bus_resume");
    if ( !context )
    {
      result = 4294967277LL;
      goto LABEL_12;
    }
    if ( *((_DWORD *)context + 366) == 1 )
    {
      result = _wlan_hdd_validate_context(context, "wlan_hdd_bus_resume");
      if ( (_DWORD)result )
        goto LABEL_12;
      v45 = _cds_get_context(61, (__int64)"wlan_hdd_bus_resume", v37, v38, v39, v40, v41, v42, v43, v44);
      if ( !v45 )
      {
        result = 4294967274LL;
        goto LABEL_12;
      }
      v46 = (__int64)v45;
      v92 = 3;
      ucfg_dp_bbm_apply_independent_policy(*context, (__int64)&v92);
      v47 = hif_bus_resume(v46);
      if ( v47 )
      {
        v48 = v47;
        v49 = "%s: Failed hif bus resume";
LABEL_22:
        qdf_trace_msg(0x33u, 2u, v49, v29, v30, v31, v32, v33, v34, v35, v36, "wlan_hdd_bus_resume");
        _hif_system_pm_set_state(v46, 3);
        if ( (cds_get_driver_state(v68, v69, v70, v71, v72, v73, v74, v75) & 8) == 0
          && (cds_get_driver_state(v76, v77, v78, v79, v80, v81, v82, v83) & 0x10) == 0 )
        {
          if ( cds_is_fw_down(v84, v85, v86, v87, v88, v89, v90, v91) )
            result = 0;
          else
            result = v48;
          goto LABEL_12;
        }
LABEL_11:
        result = 0;
        goto LABEL_12;
      }
      _hif_system_pm_set_state(v46, 1);
      v52 = ucfg_pmo_psoc_bus_resume_req(*context, a1);
      v53 = qdf_status_to_os_return(v52);
      if ( v53 )
      {
        v48 = v53;
        v49 = "%s: Failed pmo bus resume";
        goto LABEL_22;
      }
      v54 = ucfg_pmo_core_txrx_resume(*context);
      v55 = qdf_status_to_os_return(v54);
      if ( v55 )
      {
        v48 = v55;
        v49 = "%s: Failed to resume TXRX";
        goto LABEL_22;
      }
      _hif_system_pm_set_state(v46, 0);
      v56 = hif_bus_late_resume(v46);
      if ( v56 )
      {
        v48 = v56;
        v49 = "%s: Failed hif bus late resume";
        goto LABEL_22;
      }
      v57 = _cds_get_context(71, (__int64)"wlan_hdd_bus_resume", v29, v30, v31, v32, v33, v34, v35, v36);
      v66 = ucfg_dp_bus_resume((__int64)v57, v58, v59, v60, v61, v62, v63, v64, v65);
      v67 = qdf_status_to_os_return(v66);
      if ( v67 )
      {
        v48 = v67;
        v49 = "%s: Failed cdp bus resume";
        goto LABEL_22;
      }
      v50 = "%s: bus resume succeeded";
      v51 = 4;
    }
    else
    {
      v50 = "%s: Driver Module closed; return success";
      v51 = 8;
    }
    qdf_trace_msg(0x33u, v51, v50, v29, v30, v31, v32, v33, v34, v35, v36, "wlan_hdd_bus_resume");
    goto LABEL_11;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
