__int64 __fastcall hdd_mlo_channel_switch_notify(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  int v32; // w9
  unsigned __int64 StatusReg; // x8
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x1
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  __int64 v62; // x0
  unsigned __int64 v63; // x23
  __int64 v64; // x8
  __int64 v65; // x9
  __int64 v66; // x21
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int *v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x8
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 result; // x0
  __int64 v95; // [xsp+0h] [xbp-20h] BYREF
  __int64 v96[3]; // [xsp+8h] [xbp-18h] BYREF

  v96[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_mlo_channel_switch_notify", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( a1 )
  {
    v19 = *a1;
    v20 = a1[1];
    v21 = a1[2];
    v22 = a1[5];
  }
  else
  {
    v21 = 0;
    v19 = 0;
    v20 = 0;
    v22 = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Standby Link CSA: BSSID %02x:%02x:%02x:**:**:%02x",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "hdd_mlo_channel_switch_notify",
    v19,
    v20,
    v21,
    v22);
  v31 = *(_DWORD *)a1;
  v32 = *((unsigned __int16 *)a1 + 2);
  v95 = 0;
  v96[0] = 0;
  if ( v31 | v32 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(context + 4);
    }
    else
    {
      raw_spin_lock_bh(context + 4);
      context[5] |= 1uLL;
    }
    hdd_get_front_adapter_no_lock((__int64)context, v96);
    if ( v96[0] )
    {
      hdd_adapter_dev_hold_debug(v96[0], 0x3Eu, v34, v35, v36, v37, v38, v39, v40, v41, v42);
      v43 = v96[0];
    }
    else
    {
      v43 = 0;
    }
    hdd_get_next_adapter_no_lock((__int64)context, v43, &v95);
    if ( v95 )
      hdd_adapter_dev_hold_debug(v95, 0x3Eu, v52, v53, v54, v55, v56, v57, v58, v59, v60);
    v61 = context[5];
    if ( (v61 & 1) != 0 )
    {
      context[5] = v61 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(context + 4);
      v62 = v96[0];
      if ( !v96[0] )
        goto LABEL_42;
    }
    else
    {
      raw_spin_unlock(context + 4);
      v62 = v96[0];
      if ( !v96[0] )
        goto LABEL_42;
    }
    v63 = _ReadStatusReg(SP_EL0);
    do
    {
      while ( 1 )
      {
        v64 = v62 + 52840;
        if ( v62 != -52840 )
        {
          v65 = 0;
          v66 = v62 + 58848;
          while ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v65 >> 3)) <= 2 )
          {
            if ( *(_DWORD *)a1 == *(_DWORD *)(v64 + 308)
              && *((unsigned __int16 *)a1 + 2) == *(unsigned __int16 *)(v64 + 312) )
            {
              hdd_adapter_dev_put_debug(v62, 0x3Eu, v44, v45, v46, v47, v48, v49, v50, v51);
              if ( v95 )
                hdd_adapter_dev_put_debug(v95, 0x3Eu, v86, v87, v88, v89, v90, v91, v92, v93);
              *(_DWORD *)(v66 - 4) = 1;
              queue_work_on(32, system_wq, v66);
              result = 0;
              goto LABEL_43;
            }
            v64 += 6088;
            v66 += 6088;
            v65 += 6088;
            if ( !v64 )
              break;
          }
        }
        hdd_adapter_dev_put_debug(v62, 0x3Eu, v44, v45, v46, v47, v48, v49, v50, v51);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v63 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v63 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(context + 4);
        }
        else
        {
          raw_spin_lock_bh(context + 4);
          context[5] |= 1uLL;
        }
        v96[0] = v95;
        hdd_get_next_adapter_no_lock((__int64)context, v95, &v95);
        hdd_validate_next_adapter(v96, &v95, 0x3Eu, v68, v69, v70, v71, v72, v73, v74, v75);
        if ( v95 )
          hdd_adapter_dev_hold_debug(v95, 0x3Eu, v76, v77, v78, v79, v80, v81, v82, v83, v84);
        v85 = context[5];
        if ( (v85 & 1) != 0 )
          break;
        raw_spin_unlock(context + 4);
        v62 = v96[0];
        if ( !v96[0] )
          goto LABEL_42;
      }
      context[5] = v85 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(context + 4);
      v62 = v96[0];
    }
    while ( v96[0] );
  }
  else
  {
    qdf_trace_msg(0x33u, 8u, "%s: Invalid bssid", v23, v24, v25, v26, v27, v28, v29, v30, "hdd_get_link_info_by_bssid");
  }
LABEL_42:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: hdd link info is NULL",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    "hdd_mlo_channel_switch_notify",
    v95);
  result = 16;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
