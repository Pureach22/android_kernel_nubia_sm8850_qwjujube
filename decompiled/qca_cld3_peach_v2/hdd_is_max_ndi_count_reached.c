__int64 __fastcall hdd_is_max_ndi_count_reached(__int64 *a1)
{
  unsigned __int64 StatusReg; // x8
  unsigned int *v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x1
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  unsigned int v32; // w20
  unsigned __int64 v33; // x21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int *v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 result; // x0
  unsigned int v61; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v62; // [xsp+8h] [xbp-18h] BYREF
  __int64 v63[2]; // [xsp+10h] [xbp-10h] BYREF

  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  if ( !a1 )
    goto LABEL_36;
  v63[0] = 0;
  v61 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 4);
  }
  else
  {
    raw_spin_lock_bh(a1 + 4);
    a1[5] |= 1uLL;
  }
  hdd_get_front_adapter_no_lock((__int64)a1, v63);
  if ( v63[0] )
  {
    hdd_adapter_dev_hold_debug(v63[0], 0x2Fu, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    v12 = v63[0];
  }
  else
  {
    v12 = 0;
  }
  hdd_get_next_adapter_no_lock((__int64)a1, v12, &v62);
  if ( v62 )
    hdd_adapter_dev_hold_debug(v62, 0x2Fu, v13, v14, v15, v16, v17, v18, v19, v20, v21);
  v22 = a1[5];
  if ( (v22 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 4);
    v31 = v63[0];
    if ( v63[0] )
      goto LABEL_13;
LABEL_30:
    v32 = 0;
    goto LABEL_31;
  }
  a1[5] = v22 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 4);
  v31 = v63[0];
  if ( !v63[0] )
    goto LABEL_30;
LABEL_13:
  LOBYTE(v32) = 0;
  v33 = _ReadStatusReg(SP_EL0);
  do
  {
    while ( 1 )
    {
      if ( *(_DWORD *)(v31 + 40) == 11 )
        LOBYTE(v32) = v32 + 1;
      hdd_adapter_dev_put_debug(v31, 0x2Fu, v23, v24, v25, v26, v27, v28, v29, v30);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v33 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 4);
      }
      else
      {
        raw_spin_lock_bh(a1 + 4);
        a1[5] |= 1uLL;
      }
      v63[0] = v62;
      hdd_get_next_adapter_no_lock((__int64)a1, v62, &v62);
      hdd_validate_next_adapter(v63, &v62, 0x2Fu, v34, v35, v36, v37, v38, v39, v40, v41);
      if ( v62 )
        hdd_adapter_dev_hold_debug(v62, 0x2Fu, v42, v43, v44, v45, v46, v47, v48, v49, v50);
      v51 = a1[5];
      if ( (v51 & 1) != 0 )
        break;
      raw_spin_unlock(a1 + 4);
      v31 = v63[0];
      if ( !v63[0] )
        goto LABEL_28;
    }
    a1[5] = v51 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    v31 = v63[0];
  }
  while ( v63[0] );
LABEL_28:
  v32 = (unsigned __int8)v32;
LABEL_31:
  if ( (unsigned int)cfg_nan_get_max_ndi(*a1, (int *)&v61, v23, v24, v25, v26, v27, v28, v29, v30) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s:  Unable to fetch Max NDI",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "hdd_is_max_ndi_count_reached");
LABEL_36:
    result = 1;
    goto LABEL_37;
  }
  if ( v61 <= v32 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Can't allow more than %d NDI adapters",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "hdd_is_max_ndi_count_reached");
    goto LABEL_36;
  }
  result = 0;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
