__int64 __fastcall hdd_get_sta_connection_in_progress(
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
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x1
  __int64 v12; // x8
  __int64 v13; // x0
  unsigned __int64 v14; // x23
  unsigned int v15; // w8
  bool v16; // cc
  int v17; // w8
  __int64 v19; // x20
  __int64 v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v30; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v31[2]; // [xsp+10h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31[0] = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HDD context is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_get_sta_connection_in_progress");
    goto LABEL_42;
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
  hdd_get_front_adapter_no_lock(a1, v31);
  if ( v31[0] )
  {
    hdd_adapter_dev_hold_debug(v31[0], 1);
    v11 = v31[0];
  }
  else
  {
    v11 = 0;
  }
  hdd_get_next_adapter_no_lock(a1, v11, &v30);
  if ( v30 )
    hdd_adapter_dev_hold_debug(v30, 1);
  v12 = *(_QWORD *)(a1 + 40);
  if ( (v12 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 32);
    v13 = v31[0];
    if ( v31[0] )
      goto LABEL_14;
LABEL_42:
    v19 = 0;
    goto LABEL_43;
  }
  *(_QWORD *)(a1 + 40) = v12 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 32);
  v13 = v31[0];
  if ( !v31[0] )
    goto LABEL_42;
LABEL_14:
  v14 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v15 = *(_DWORD *)(v13 + 40);
    v16 = v15 > 7;
    v17 = (1 << v15) & 0x85;
    if ( !v16 && v17 != 0 && (*(_QWORD *)(v13 + 1640) & 1) != 0 )
    {
      v19 = v13 + 52832;
      if ( v13 != -52832 )
        break;
    }
LABEL_21:
    hdd_adapter_dev_put_debug(v13, 1);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v14 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
    }
    v31[0] = v30;
    hdd_get_next_adapter_no_lock(a1, v30, &v30);
    hdd_validate_next_adapter(v31, &v30, 1);
    if ( v30 )
      hdd_adapter_dev_hold_debug(v30, 1);
    v20 = *(_QWORD *)(a1 + 40);
    if ( (v20 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v20 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v13 = v31[0];
      if ( !v31[0] )
        goto LABEL_42;
    }
    else
    {
      raw_spin_unlock(a1 + 32);
      v13 = v31[0];
      if ( !v31[0] )
        goto LABEL_42;
    }
  }
  while ( (hdd_cm_is_connecting(v19) & 1) == 0 )
  {
    v13 = v31[0];
    if ( v31[0] )
    {
      if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v19 - *(_DWORD *)v19 - 52832) >> 4))
        || (*(_QWORD *)(v31[0] + 1640LL) & 1) == 0 )
      {
        goto LABEL_21;
      }
      v19 = v31[0] + 52832LL;
    }
    if ( !v19 )
      goto LABEL_21;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev_id %d: Connection is in progress",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "hdd_get_sta_connection_in_progress",
    *(unsigned __int8 *)(v19 + 8));
  hdd_adapter_dev_put_debug(v31[0], 1);
  if ( v30 )
    hdd_adapter_dev_put_debug(v30, 1);
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v19;
}
