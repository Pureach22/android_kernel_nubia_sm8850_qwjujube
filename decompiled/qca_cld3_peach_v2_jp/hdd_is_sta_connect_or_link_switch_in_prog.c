__int64 __fastcall hdd_is_sta_connect_or_link_switch_in_prog(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x1
  __int64 result; // x0
  __int64 v15; // x8
  unsigned __int64 v16; // x26
  __int64 v17; // x21
  __int64 v18; // x8
  _BOOL4 is_connecting; // w22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int is_sta_key_exchange_in_progress; // w0
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30[0] = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HDD context is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_is_sta_connect_or_link_switch_in_prog");
    result = 0;
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
  hdd_get_front_adapter_no_lock(a1, v30);
  if ( v30[0] )
  {
    hdd_adapter_dev_hold_debug(v30[0], 5);
    v13 = v30[0];
  }
  else
  {
    v13 = 0;
  }
  hdd_get_next_adapter_no_lock(a1, v13, &v29);
  if ( v29 )
    hdd_adapter_dev_hold_debug(v29, 5);
  v15 = *(_QWORD *)(a1 + 40);
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    result = v30[0];
    if ( !v30[0] )
      goto LABEL_42;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    result = v30[0];
    if ( !v30[0] )
      goto LABEL_42;
  }
  v16 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (*(_DWORD *)(result + 40) | 2) == 2 && (*(_QWORD *)(result + 1640) & 1) != 0 )
    {
      v17 = result + 52832;
      if ( result != -52832 )
        break;
    }
LABEL_18:
    hdd_adapter_dev_put_debug(result, 5);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v16 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v16 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
    }
    v30[0] = v29;
    hdd_get_next_adapter_no_lock(a1, v29, &v29);
    hdd_validate_next_adapter(v30, &v29, 5);
    if ( v29 )
      hdd_adapter_dev_hold_debug(v29, 5);
    v18 = *(_QWORD *)(a1 + 40);
    if ( (v18 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v18 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      result = v30[0];
      if ( !v30[0] )
        goto LABEL_42;
    }
    else
    {
      raw_spin_unlock(a1 + 32);
      result = v30[0];
      if ( !v30[0] )
        goto LABEL_42;
    }
  }
  while ( 1 )
  {
    is_connecting = hdd_cm_is_connecting(v17);
    if ( a2 != 3 )
      break;
    is_sta_key_exchange_in_progress = sme_is_sta_key_exchange_in_progress(
                                        *(_QWORD *)(a1 + 16),
                                        *(unsigned __int8 *)(v17 + 8));
    if ( ((is_connecting | is_sta_key_exchange_in_progress) & 1) != 0 )
      goto LABEL_39;
LABEL_32:
    result = v30[0];
    if ( v30[0] )
    {
      if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v17 - *(_DWORD *)v17 - 52832) >> 4))
        || (*(_QWORD *)(v30[0] + 1640LL) & 1) == 0 )
      {
        goto LABEL_18;
      }
      v17 = v30[0] + 52832LL;
    }
    if ( !v17 )
      goto LABEL_18;
  }
  LOBYTE(is_sta_key_exchange_in_progress) = 0;
  if ( !is_connecting )
    goto LABEL_32;
LABEL_39:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev_id %d: connecting %d switching link %d key_exchng_in_prog %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "hdd_is_sta_connect_or_link_switch_in_prog",
    *(unsigned __int8 *)(v17 + 8),
    is_connecting,
    0,
    is_sta_key_exchange_in_progress & 1);
  hdd_adapter_dev_put_debug(v30[0], 5);
  if ( v29 )
    hdd_adapter_dev_put_debug(v29, 5);
  result = 1;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
