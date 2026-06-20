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
  unsigned __int64 v44; // x24
  __int64 v45; // x21
  int v46; // w8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
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
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // [xsp+8h] [xbp-18h] BYREF
  __int64 v82[2]; // [xsp+10h] [xbp-10h] BYREF

  v82[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (unsigned __int8 *)a1[12];
  v81 = 0;
  v82[0] = a2;
  if ( !v10 || !a1[16] || !a1[7] || !a1[1] )
  {
    result = qdf_trace_msg(0x33u, 8u, "%s: Invalid stats", a3, a4, a5, a6, a7, a8, a9, a10, "cache_station_stats_cb");
    goto LABEL_12;
  }
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
  hdd_get_front_adapter_no_lock(v11, v82);
  if ( v82[0] )
  {
    hdd_adapter_dev_hold_debug(v82[0], 0x3Au, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    v24 = v82[0];
  }
  else
  {
    v24 = 0;
  }
  hdd_get_next_adapter_no_lock(v11, v24, &v81);
  if ( v81 )
    hdd_adapter_dev_hold_debug(v81, 0x3Au, v26, v27, v28, v29, v30, v31, v32, v33, v34);
  v35 = *(_QWORD *)(v11 + 40);
  if ( (v35 & 1) != 0 )
  {
    *(_QWORD *)(v11 + 40) = v35 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v11 + 32);
    result = v82[0];
    if ( !v82[0] )
      goto LABEL_12;
  }
  else
  {
    raw_spin_unlock(v11 + 32);
    result = v82[0];
    if ( !v82[0] )
      goto LABEL_12;
  }
  v44 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (*(_QWORD *)(result + 1640) & 1) != 0 )
    {
      v45 = result + 52832;
      if ( result != -52832 )
        break;
    }
LABEL_26:
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
    v82[0] = v81;
    hdd_get_next_adapter_no_lock(v11, v81, &v81);
    hdd_validate_next_adapter(v82, &v81, 0x3Au, v47, v48, v49, v50, v51, v52, v53, v54);
    if ( v81 )
      hdd_adapter_dev_hold_debug(v81, 0x3Au, v55, v56, v57, v58, v59, v60, v61, v62, v63);
    v64 = *(_QWORD *)(v11 + 40);
    if ( (v64 & 1) != 0 )
    {
      *(_QWORD *)(v11 + 40) = v64 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v11 + 32);
      result = v82[0];
      if ( !v82[0] )
        goto LABEL_12;
    }
    else
    {
      raw_spin_unlock(v11 + 32);
      result = v82[0];
      if ( !v82[0] )
        goto LABEL_12;
    }
  }
  v46 = *(unsigned __int8 *)(result + 52840);
  if ( v46 != v12 )
  {
    while ( (unsigned __int8)(19 * ((unsigned int)(result - *(_DWORD *)(result + 52832)) >> 4)) == 255
         && (*(_QWORD *)(result + 1640) & 1) != 0 )
    {
      if ( v46 == v12 )
        goto LABEL_38;
    }
    goto LABEL_26;
  }
LABEL_38:
  copy_station_stats_to_adapter(result + 52832, (__int64)a1);
  wlan_hdd_get_peer_rx_rate_stats(v45);
  hdd_adapter_dev_put_debug(v82[0], 0x3Au, v65, v66, v67, v68, v69, v70, v71, v72);
  result = v81;
  if ( v81 )
    result = hdd_adapter_dev_put_debug(v81, 0x3Au, v73, v74, v75, v76, v77, v78, v79, v80);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
