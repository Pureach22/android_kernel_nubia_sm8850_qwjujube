__int64 __fastcall hdd_get_first_connected_sta_cli_vdev_id(
        __int64 a1,
        _DWORD *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x1
  __int64 result; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  unsigned __int64 v19; // x24
  __int64 v20; // x22
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x0
  __int64 v26; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27[0] = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HDD context is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_get_first_connected_sta_cli_vdev_id");
    result = 4;
    goto LABEL_46;
  }
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
  hdd_get_front_adapter_no_lock(a1, v27);
  if ( v27[0] )
  {
    hdd_adapter_dev_hold_debug(v27[0], 61);
    v15 = v27[0];
  }
  else
  {
    v15 = 0;
  }
  hdd_get_next_adapter_no_lock(a1, v15, &v26);
  if ( v26 )
    hdd_adapter_dev_hold_debug(v26, 61);
  v17 = *(_QWORD *)(a1 + 40);
  if ( (v17 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 32);
    v18 = v27[0];
    if ( v27[0] )
      goto LABEL_14;
LABEL_45:
    result = 16;
    goto LABEL_46;
  }
  *(_QWORD *)(a1 + 40) = v17 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 32);
  v18 = v27[0];
  if ( !v27[0] )
    goto LABEL_45;
LABEL_14:
  v19 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(_DWORD *)(v18 + 40) == a3 )
    {
      if ( (*(_QWORD *)(v18 + 1640) & 1) != 0 )
      {
        v20 = v18 + 52840;
        if ( v18 != -52840 )
          break;
      }
      if ( (*(_QWORD *)(v18 + 1640) & 2) != 0 )
      {
        v20 = v18 + 58928;
        if ( v18 != -58928 )
          break;
      }
      if ( (*(_QWORD *)(v18 + 1640) & 4) != 0 )
      {
        v20 = v18 + 65016;
        if ( v18 != -65016 )
          break;
      }
    }
LABEL_22:
    hdd_adapter_dev_put_debug(v18, 61);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v19 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
    }
    v27[0] = v26;
    hdd_get_next_adapter_no_lock(a1, v26, &v26);
    hdd_validate_next_adapter(v27, &v26, 61);
    if ( v26 )
      hdd_adapter_dev_hold_debug(v26, 61);
    v21 = *(_QWORD *)(a1 + 40);
    if ( (v21 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v21 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v18 = v27[0];
      if ( !v27[0] )
        goto LABEL_45;
    }
    else
    {
      raw_spin_unlock(a1 + 32);
      v18 = v27[0];
      if ( !v27[0] )
        goto LABEL_45;
    }
  }
  while ( (hdd_cm_is_vdev_connected(v20) & 1) == 0 )
  {
    v18 = v27[0];
    if ( v27[0] )
    {
      if ( (unsigned __int8)(73 * ((unsigned int)(v20 - *(_DWORD *)v20 - 52840) >> 3) + 1) > 2u )
        goto LABEL_22;
      v22 = (unsigned __int8)(73 * ((unsigned int)(v20 - *(_DWORD *)v20 - 52840) >> 3) + 1);
      v20 = 0;
      v23 = v27[0] + 6088LL * (unsigned int)v22 + 52840;
      do
      {
        if ( v20 )
          break;
        v24 = *(_QWORD *)(v27[0] + 1640LL) >> v22++;
        v20 = (v24 << 63 >> 63) & v23;
        v23 += 6088;
      }
      while ( v22 != 3 );
    }
    if ( !v20 )
      goto LABEL_22;
  }
  v25 = v27[0];
  *a2 = *(unsigned __int8 *)(v20 + 8);
  hdd_adapter_dev_put_debug(v25, 61);
  result = v26;
  if ( v26 )
  {
    hdd_adapter_dev_put_debug(v26, 61);
    result = 0;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
