__int64 __fastcall cache_station_stats_cb(
        _QWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 *v10; // x8
  __int64 v11; // x20
  int v12; // w22
  unsigned __int64 StatusReg; // x8
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x1
  __int64 result; // x0
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int64 v44; // x26
  __int64 v45; // x21
  __int64 v46; // x9
  __int64 v47; // x10
  __int64 v48; // x11
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int *v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // [xsp+8h] [xbp-18h] BYREF
  __int64 v84[2]; // [xsp+10h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (unsigned __int8 *)a1[12];
  v83 = 0;
  v84[0] = a2;
  if ( v10 && a1[16] && a1[7] && a1[1] )
  {
    v11 = *(_QWORD *)(a2 + 24);
    v12 = *v10;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v11 + 32);
    }
    else
    {
      raw_spin_lock_bh(v11 + 32);
      *(_QWORD *)(v11 + 40) |= 1uLL;
    }
    hdd_get_front_adapter_no_lock(v11, v84);
    if ( v84[0] )
    {
      hdd_adapter_dev_hold_debug(v84[0], 0x3Au, v15, v16, v17, v18, v19, v20, v21, v22, v23);
      v24 = v84[0];
    }
    else
    {
      v24 = 0;
    }
    hdd_get_next_adapter_no_lock(v11, v24, &v83);
    if ( v83 )
      hdd_adapter_dev_hold_debug(v83, 0x3Au, v26, v27, v28, v29, v30, v31, v32, v33, v34);
    v35 = *(_QWORD *)(v11 + 40);
    if ( (v35 & 1) != 0 )
    {
      *(_QWORD *)(v11 + 40) = v35 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v11 + 32);
      result = v84[0];
      if ( !v84[0] )
        goto LABEL_12;
    }
    else
    {
      raw_spin_unlock(v11 + 32);
      result = v84[0];
      if ( !v84[0] )
        goto LABEL_12;
    }
    v44 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (*(_QWORD *)(result + 1640) & 1) != 0 )
      {
        v45 = result + 52840;
        if ( result != -52840 )
          break;
      }
      if ( (*(_QWORD *)(result + 1640) & 2) != 0 )
      {
        v45 = result + 58928;
        if ( result != -58928 )
          break;
      }
      if ( (*(_QWORD *)(result + 1640) & 4) != 0 )
      {
        v45 = result + 65016;
        if ( result != -65016 )
          break;
      }
LABEL_33:
      hdd_adapter_dev_put_debug(result, 0x3Au, v36, v37, v38, v39, v40, v41, v42, v43);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v44 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v44 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v11 + 32);
      }
      else
      {
        raw_spin_lock_bh(v11 + 32);
        *(_QWORD *)(v11 + 40) |= 1uLL;
      }
      v84[0] = v83;
      hdd_get_next_adapter_no_lock(v11, v83, &v83);
      hdd_validate_next_adapter(v84, &v83, 0x3Au, v49, v50, v51, v52, v53, v54, v55, v56);
      if ( v83 )
        hdd_adapter_dev_hold_debug(v83, 0x3Au, v57, v58, v59, v60, v61, v62, v63, v64, v65);
      v66 = *(_QWORD *)(v11 + 40);
      if ( (v66 & 1) != 0 )
      {
        *(_QWORD *)(v11 + 40) = v66 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v11 + 32);
        result = v84[0];
        if ( !v84[0] )
          goto LABEL_12;
      }
      else
      {
        raw_spin_unlock(v11 + 32);
        result = v84[0];
        if ( !v84[0] )
          goto LABEL_12;
      }
    }
    while ( *(unsigned __int8 *)(v45 + 8) != v12 )
    {
      if ( (unsigned __int8)(73 * ((unsigned int)(v45 - *(_DWORD *)v45 - 52840) >> 3) + 1) <= 2u )
      {
        v46 = (unsigned __int8)(73 * ((unsigned int)(v45 - *(_DWORD *)v45 - 52840) >> 3) + 1);
        v45 = 0;
        v47 = result + 52840 + 6088LL * (unsigned int)v46;
        do
        {
          if ( v45 )
            break;
          v48 = *(_QWORD *)(result + 1640) >> v46++;
          v45 = (v48 << 63 >> 63) & v47;
          v47 += 6088;
        }
        while ( v46 != 3 );
        if ( v45 )
          continue;
      }
      goto LABEL_33;
    }
    copy_station_stats_to_adapter(v45, (__int64)a1);
    wlan_hdd_get_peer_rx_rate_stats(v45);
    hdd_adapter_dev_put_debug(v84[0], 0x3Au, v67, v68, v69, v70, v71, v72, v73, v74);
    result = v83;
    if ( v83 )
      result = hdd_adapter_dev_put_debug(v83, 0x3Au, v75, v76, v77, v78, v79, v80, v81, v82);
  }
  else
  {
    result = qdf_trace_msg(0x33u, 8u, "%s: Invalid stats", a3, a4, a5, a6, a7, a8, a9, a10, "cache_station_stats_cb");
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
