__int64 __fastcall hdd_suspend_wlan(
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
  __int64 v25; // x19
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
  unsigned __int64 v74; // x26
  __int64 v75; // x21
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
  unsigned int *v92; // x8
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x8
  __int64 v102; // x8
  __int64 v103; // x9
  __int64 v104; // x10
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 v107; // [xsp+0h] [xbp-20h] BYREF
  __int64 v108; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v109[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v110; // [xsp+18h] [xbp-8h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v107 = 0;
  v108 = 0;
  qdf_trace_msg(0x33u, 4u, "%s: WLAN being suspended by OS", a1, a2, a3, a4, a5, a6, a7, a8, "hdd_suspend_wlan");
  context = _cds_get_context(51, (__int64)"hdd_suspend_wlan", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( !context )
    goto LABEL_11;
  v25 = (__int64)context;
  if ( (cds_get_driver_state(v17, v18, v19, v20, v21, v22, v23, v24) & 8) != 0
    || (cds_get_driver_state(v26, v27, v28, v29, v30, v31, v32, v33) & 0x10) != 0 )
  {
    driver_state = cds_get_driver_state(v26, v27, v28, v29, v30, v31, v32, v33);
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Recovery in Progress. State: 0x%x Ignore suspend!!!",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "hdd_suspend_wlan",
      driver_state);
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v25 + 32);
  }
  else
  {
    raw_spin_lock_bh(v25 + 32);
    *(_QWORD *)(v25 + 40) |= 1uLL;
  }
  hdd_get_front_adapter_no_lock(v25, &v108);
  if ( v108 )
  {
    hdd_adapter_dev_hold_debug(v108, 0x32u, v35, v36, v37, v38, v39, v40, v41, v42, v43);
    v44 = v108;
  }
  else
  {
    v44 = 0;
  }
  hdd_get_next_adapter_no_lock(v25, v44, &v107);
  if ( v107 )
    hdd_adapter_dev_hold_debug(v107, 0x32u, v55, v56, v57, v58, v59, v60, v61, v62, v63);
  v64 = *(_QWORD *)(v25 + 40);
  if ( (v64 & 1) != 0 )
  {
    *(_QWORD *)(v25 + 40) = v64 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v25 + 32);
    v73 = v108;
    if ( v108 )
    {
LABEL_18:
      v74 = _ReadStatusReg(SP_EL0);
      do
      {
        while ( 1 )
        {
          if ( (*(_QWORD *)(v73 + 1640) & 1) != 0 && (v75 = v73 + 52840, v73 != -52840)
            || (*(_QWORD *)(v73 + 1640) & 2) != 0 && (v75 = v73 + 58928, v73 != -58928)
            || (*(_QWORD *)(v73 + 1640) & 4) != 0 && (v75 = v73 + 65016, v73 != -65016) )
          {
            do
            {
              if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                                    *(_BYTE *)(v75 + 8),
                                    (__int64)"hdd_suspend_wlan",
                                    v65,
                                    v66,
                                    v67,
                                    v68,
                                    v69,
                                    v70,
                                    v71,
                                    v72) )
              {
                v105 = *(_QWORD *)(v75 + 32);
                if ( v105 )
                {
                  if ( (ucfg_pmo_is_vdev_connected(v105) & 1) != 0 )
                  {
                    if ( !*(_DWORD *)(v108 + 40) )
                      ((void (__fastcall *)(__int64, _QWORD))hdd_enable_default_pkt_filters)(
                        v25,
                        *(unsigned __int8 *)(v75 + 8));
                    if ( (unsigned int)ucfg_pmo_enable_gtk_offload_in_fwr(*(_QWORD *)(v75 + 32)) )
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: Failed to enable gtk offload",
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        v70,
                        v71,
                        v72,
                        "hdd_enable_gtk_offload");
                  }
                }
              }
              v73 = v108;
              if ( v108 )
              {
                if ( (unsigned __int8)(73 * ((unsigned int)(v75 - *(_DWORD *)v75 - 52840) >> 3) + 1) > 2u )
                  break;
                v102 = (unsigned __int8)(73 * ((unsigned int)(v75 - *(_DWORD *)v75 - 52840) >> 3) + 1);
                v75 = 0;
                v103 = v108 + 6088LL * (unsigned int)v102 + 52840;
                do
                {
                  if ( v75 )
                    break;
                  v104 = *(_QWORD *)(v108 + 1640) >> v102++;
                  v75 = (v104 << 63 >> 63) & v103;
                  v103 += 6088;
                }
                while ( v102 != 3 );
              }
            }
            while ( v75 );
          }
          hdd_enable_host_offloads(v73, 0, v65, v66, v67, v68, v69, v70, v71, v72);
          hdd_adapter_dev_put_debug(v108, 0x32u, v76, v77, v78, v79, v80, v81, v82, v83);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v74 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v74 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v25 + 32);
          }
          else
          {
            raw_spin_lock_bh(v25 + 32);
            *(_QWORD *)(v25 + 40) |= 1uLL;
          }
          v108 = v107;
          hdd_get_next_adapter_no_lock(v25, v107, &v107);
          hdd_validate_next_adapter(&v108, &v107, 0x32u, v84, v85, v86, v87, v88, v89, v90, v91);
          if ( v107 )
            hdd_adapter_dev_hold_debug(v107, 0x32u, v92, v93, v94, v95, v96, v97, v98, v99, v100);
          v101 = *(_QWORD *)(v25 + 40);
          if ( (v101 & 1) != 0 )
            break;
          raw_spin_unlock(v25 + 32);
          v73 = v108;
          if ( !v108 )
            goto LABEL_52;
        }
        *(_QWORD *)(v25 + 40) = v101 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v25 + 32);
        v73 = v108;
      }
      while ( v108 );
    }
  }
  else
  {
    raw_spin_unlock(v25 + 32);
    v73 = v108;
    if ( v108 )
      goto LABEL_18;
  }
LABEL_52:
  if ( (unsigned int)ucfg_pmo_psoc_user_space_suspend_req(*(_QWORD *)v25, 0) )
  {
    result = 4294967285LL;
  }
  else
  {
    v106 = *(_QWORD *)v25;
    *(_BYTE *)(v25 + 185) = 1;
    ucfg_dp_suspend_wlan(v106);
    hdd_configure_sar_sleep_index(v25);
    v109[0] = 0;
    qdf_mem_set(v109, 1u, 0);
    v109[0] = 0;
    host_diag_event_report_payload(2743, 1, v109);
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
