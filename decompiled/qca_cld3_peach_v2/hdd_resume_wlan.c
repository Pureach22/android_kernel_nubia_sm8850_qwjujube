__int64 __fastcall hdd_resume_wlan(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int64 StatusReg; // x8
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x1
  unsigned int driver_state; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 result; // x0
  unsigned int *v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x0
  unsigned __int64 v74; // x24
  __int64 v75; // x21
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int *v84; // x8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x8
  __int64 v94; // x8
  __int64 v95; // x9
  __int64 v96; // x10
  unsigned int v97; // w0
  __int64 v98; // [xsp+0h] [xbp-20h] BYREF
  __int64 v99; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v100[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v101; // [xsp+18h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v98 = 0;
  v99 = 0;
  qdf_trace_msg(0x33u, 4u, "%s: WLAN being resumed by OS", a1, a2, a3, a4, a5, a6, a7, a8, "hdd_resume_wlan");
  context = _cds_get_context(51, (__int64)"hdd_resume_wlan", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( !context )
    goto LABEL_11;
  v25 = context;
  if ( (cds_get_driver_state(v17, v18, v19, v20, v21, v22, v23, v24) & 8) != 0
    || (cds_get_driver_state(v26, v27, v28, v29, v30, v31, v32, v33) & 0x10) != 0 )
  {
    driver_state = cds_get_driver_state(v26, v27, v28, v29, v30, v31, v32, v33);
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Recovery in Progress. State: 0x%x Ignore resume!!!",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "hdd_resume_wlan",
      driver_state);
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  *((_BYTE *)v25 + 185) = 0;
  v100[0] = 0;
  qdf_mem_set(v100, 1u, 0);
  v100[0] = 2;
  host_diag_event_report_payload(2743, 1, v100);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v25 + 4);
  }
  else
  {
    raw_spin_lock_bh(v25 + 4);
    v25[5] |= 1uLL;
  }
  hdd_get_front_adapter_no_lock((__int64)v25, &v99);
  if ( v99 )
  {
    hdd_adapter_dev_hold_debug(v99, 0x33u, v35, v36, v37, v38, v39, v40, v41, v42, v43);
    v44 = v99;
  }
  else
  {
    v44 = 0;
  }
  hdd_get_next_adapter_no_lock((__int64)v25, v44, &v98);
  if ( v98 )
    hdd_adapter_dev_hold_debug(v98, 0x33u, v55, v56, v57, v58, v59, v60, v61, v62, v63);
  v64 = v25[5];
  if ( (v64 & 1) != 0 )
  {
    v25[5] = v64 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v25 + 4);
    v73 = v99;
    if ( v99 )
    {
LABEL_18:
      v74 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (*(_QWORD *)(v73 + 1640) & 1) != 0 )
        {
          v75 = v73 + 52840;
          if ( v73 != -52840 )
            break;
        }
        if ( (*(_QWORD *)(v73 + 1640) & 2) != 0 )
        {
          v75 = v73 + 58928;
          if ( v73 != -58928 )
            break;
        }
        if ( (*(_QWORD *)(v73 + 1640) & 4) != 0 )
        {
          v75 = v73 + 65016;
          if ( v73 != -65016 )
            break;
        }
LABEL_25:
        hdd_adapter_dev_put_debug(v73, 0x33u, v65, v66, v67, v68, v69, v70, v71, v72);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v74 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v74 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v25 + 4);
        }
        else
        {
          raw_spin_lock_bh(v25 + 4);
          v25[5] |= 1uLL;
        }
        v99 = v98;
        hdd_get_next_adapter_no_lock((__int64)v25, v98, &v98);
        hdd_validate_next_adapter(&v99, &v98, 0x33u, v76, v77, v78, v79, v80, v81, v82, v83);
        if ( v98 )
          hdd_adapter_dev_hold_debug(v98, 0x33u, v84, v85, v86, v87, v88, v89, v90, v91, v92);
        v93 = v25[5];
        if ( (v93 & 1) != 0 )
        {
          v25[5] = v93 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v25 + 4);
          v73 = v99;
          if ( !v99 )
            goto LABEL_50;
        }
        else
        {
          raw_spin_unlock(v25 + 4);
          v73 = v99;
          if ( !v99 )
            goto LABEL_50;
        }
      }
      while ( 1 )
      {
        if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                             *(_BYTE *)(v75 + 8),
                             (__int64)"hdd_resume_wlan",
                             v65,
                             v66,
                             v67,
                             v68,
                             v69,
                             v70,
                             v71,
                             v72) )
        {
          v73 = v99;
          if ( !v99 )
            goto LABEL_34;
        }
        else
        {
          hdd_disable_host_offloads(v99, 1u, v65, v66, v67, v68, v69, v70, v71, v72);
          if ( !*(_DWORD *)(v99 + 40) )
            hdd_disable_default_pkt_filters(v25, *(unsigned __int8 *)(v75 + 8));
          hdd_restart_tsf_sync_post_wlan_resume();
          v73 = v99;
          if ( !v99 )
            goto LABEL_34;
        }
        if ( (unsigned __int8)(73 * ((unsigned int)(v75 - *(_DWORD *)v75 - 52840) >> 3) + 1) > 2u )
          goto LABEL_25;
        v94 = (unsigned __int8)(73 * ((unsigned int)(v75 - *(_DWORD *)v75 - 52840) >> 3) + 1);
        v75 = 0;
        v95 = v73 + 6088LL * (unsigned int)v94 + 52840;
        do
        {
          if ( v75 )
            break;
          v96 = *(_QWORD *)(v73 + 1640) >> v94++;
          v75 = (v96 << 63 >> 63) & v95;
          v95 += 6088;
        }
        while ( v94 != 3 );
LABEL_34:
        if ( !v75 )
          goto LABEL_25;
      }
    }
  }
  else
  {
    raw_spin_unlock(v25 + 4);
    v73 = v99;
    if ( v99 )
      goto LABEL_18;
  }
LABEL_50:
  ucfg_ipa_resume(v25[1]);
  ucfg_dp_resume_wlan(*v25);
  v97 = ucfg_pmo_psoc_user_space_resume_req(*v25, 0);
  if ( v97 )
  {
    result = qdf_status_to_os_return(v97);
  }
  else
  {
    hdd_configure_sar_resume_index(v25);
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
