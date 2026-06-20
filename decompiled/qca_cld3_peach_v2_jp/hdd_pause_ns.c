__int64 __fastcall hdd_pause_ns(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int64 StatusReg; // x8
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x1
  unsigned int driver_state; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 result; // x0
  unsigned int *v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x8
  unsigned __int64 v66; // x24
  int v67; // w8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x0
  unsigned int v77; // w22
  const char *v78; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int *v95; // x8
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x8
  __int64 v105; // [xsp+8h] [xbp-18h] BYREF
  __int64 v106[2]; // [xsp+10h] [xbp-10h] BYREF

  v106[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v105 = 0;
  v106[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: Pause NS", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_pause_ns");
  if ( (cds_get_driver_state(v10, v11, v12, v13, v14, v15, v16, v17) & 8) != 0
    || (cds_get_driver_state(v18, v19, v20, v21, v22, v23, v24, v25) & 0x10) != 0 )
  {
    driver_state = cds_get_driver_state(v18, v19, v20, v21, v22, v23, v24, v25);
    result = qdf_trace_msg(
               0x33u,
               4u,
               "%s: Recovery in Progress. State: 0x%x Ignore suspend!!!",
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               "hdd_pause_ns",
               driver_state);
  }
  else
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
    }
    hdd_get_front_adapter_no_lock(a1, v106);
    if ( v106[0] )
    {
      hdd_adapter_dev_hold_debug(v106[0], 0x32u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
      v36 = v106[0];
    }
    else
    {
      v36 = 0;
    }
    hdd_get_next_adapter_no_lock(a1, v36, &v105);
    if ( v105 )
      hdd_adapter_dev_hold_debug(v105, 0x32u, v47, v48, v49, v50, v51, v52, v53, v54, v55);
    v56 = *(_QWORD *)(a1 + 40);
    if ( (v56 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v56 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a1 + 32);
      v65 = v106[0];
      if ( !v106[0] )
        goto LABEL_10;
    }
    else
    {
      result = raw_spin_unlock(a1 + 32);
      v65 = v106[0];
      if ( !v106[0] )
        goto LABEL_10;
    }
    v66 = _ReadStatusReg(SP_EL0);
    do
    {
      while ( 1 )
      {
        v67 = _wlan_hdd_validate_vdev_id(
                *(_BYTE *)(*(_QWORD *)(v65 + 52824) + 8LL),
                (__int64)"hdd_pause_ns",
                v57,
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                v64);
        v76 = v106[0];
        if ( !v67 )
        {
          v77 = *(unsigned __int8 *)(*(_QWORD *)(v106[0] + 52824) + 8LL);
          v78 = qdf_opmode_str(*(_DWORD *)(v106[0] + 40));
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev %d Disabling queues for dev mode %s",
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            "hdd_pause_ns",
            v77,
            v78);
          wlan_hdd_netif_queue_control(v106[0], 1, 1);
          v76 = v106[0];
        }
        hdd_adapter_dev_put_debug(v76, 0x32u, v68, v69, v70, v71, v72, v73, v74, v75);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v66 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v66 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 32);
        }
        else
        {
          raw_spin_lock_bh(a1 + 32);
          *(_QWORD *)(a1 + 40) |= 1uLL;
        }
        v106[0] = v105;
        hdd_get_next_adapter_no_lock(a1, v105, &v105);
        hdd_validate_next_adapter(v106, &v105, 0x32u, v87, v88, v89, v90, v91, v92, v93, v94);
        if ( v105 )
          hdd_adapter_dev_hold_debug(v105, 0x32u, v95, v96, v97, v98, v99, v100, v101, v102, v103);
        v104 = *(_QWORD *)(a1 + 40);
        if ( (v104 & 1) != 0 )
          break;
        result = raw_spin_unlock(a1 + 32);
        v65 = v106[0];
        if ( !v106[0] )
          goto LABEL_10;
      }
      *(_QWORD *)(a1 + 40) = v104 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a1 + 32);
      v65 = v106[0];
    }
    while ( v106[0] );
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
