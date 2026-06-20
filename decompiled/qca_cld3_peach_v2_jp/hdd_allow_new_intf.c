__int64 __fastcall hdd_allow_new_intf(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned int *v4; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x1
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x0
  unsigned __int8 v25; // w20
  unsigned __int64 v26; // x21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 result; // x0
  __int64 v62; // [xsp+8h] [xbp-18h] BYREF
  __int64 v63[2]; // [xsp+10h] [xbp-10h] BYREF

  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  v63[0] = 0;
  if ( a2 != 1 )
    goto LABEL_32;
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
  hdd_get_front_adapter_no_lock(a1, v63);
  if ( v63[0] )
  {
    hdd_adapter_dev_hold_debug(v63[0], 0x3Fu, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    v13 = v63[0];
  }
  else
  {
    v13 = 0;
  }
  hdd_get_next_adapter_no_lock(a1, v13, &v62);
  if ( v62 )
    hdd_adapter_dev_hold_debug(v62, 0x3Fu, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  v23 = *(_QWORD *)(a1 + 40);
  if ( (v23 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v23 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    v24 = v63[0];
    if ( v63[0] )
      goto LABEL_13;
LABEL_32:
    result = 1;
    goto LABEL_33;
  }
  raw_spin_unlock(a1 + 32);
  v24 = v63[0];
  if ( !v63[0] )
    goto LABEL_32;
LABEL_13:
  v25 = 0;
  v26 = _ReadStatusReg(SP_EL0);
  do
  {
    while ( 1 )
    {
      if ( (hdd_is_interface_up(v24) & 1) != 0 && *(_DWORD *)(v63[0] + 40) == 1 )
        ++v25;
      hdd_adapter_dev_put_debug(v63[0], 0x3Fu, v27, v28, v29, v30, v31, v32, v33, v34);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v26 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v26 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 32);
      }
      else
      {
        raw_spin_lock_bh(a1 + 32);
        *(_QWORD *)(a1 + 40) |= 1uLL;
      }
      v63[0] = v62;
      hdd_get_next_adapter_no_lock(a1, v62, &v62);
      hdd_validate_next_adapter(v63, &v62, 0x3Fu, v35, v36, v37, v38, v39, v40, v41, v42);
      if ( v62 )
        hdd_adapter_dev_hold_debug(v62, 0x3Fu, v43, v44, v45, v46, v47, v48, v49, v50, v51);
      v52 = *(_QWORD *)(a1 + 40);
      if ( (v52 & 1) != 0 )
        break;
      raw_spin_unlock(a1 + 32);
      v24 = v63[0];
      if ( !v63[0] )
        goto LABEL_29;
    }
    *(_QWORD *)(a1 + 40) = v52 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    v24 = v63[0];
  }
  while ( v63[0] );
LABEL_29:
  if ( v25 < 2u )
    goto LABEL_32;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: sap max allowed intf %d, curr %d",
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    "hdd_allow_new_intf",
    2);
  result = 0;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
