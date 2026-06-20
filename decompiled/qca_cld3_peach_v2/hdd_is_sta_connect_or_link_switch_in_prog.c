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
  int v16; // w27
  __int64 v17; // x21
  __int64 v18; // x8
  bool is_connecting; // w22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w23
  int is_sta_key_exchange_in_progress; // w0
  __int64 v30; // x8
  __int64 v31; // x9
  __int64 v32; // x10
  unsigned __int64 v33; // [xsp+0h] [xbp-20h]
  __int64 v34; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v35[2]; // [xsp+10h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35[0] = 0;
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
    goto LABEL_50;
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
  hdd_get_front_adapter_no_lock(a1, v35);
  if ( v35[0] )
  {
    hdd_adapter_dev_hold_debug(v35[0], 5);
    v13 = v35[0];
  }
  else
  {
    v13 = 0;
  }
  hdd_get_next_adapter_no_lock(a1, v13, &v34);
  if ( v34 )
    hdd_adapter_dev_hold_debug(v34, 5);
  v15 = *(_QWORD *)(a1 + 40);
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    result = v35[0];
    if ( !v35[0] )
      goto LABEL_50;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    result = v35[0];
    if ( !v35[0] )
      goto LABEL_50;
  }
  v16 = 0;
  v33 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (*(_DWORD *)(result + 40) | 2) == 2 )
    {
      if ( (*(_QWORD *)(result + 1640) & 1) != 0 )
      {
        v17 = result + 52840;
        if ( result != -52840 )
          break;
      }
      if ( (*(_QWORD *)(result + 1640) & 2) != 0 )
      {
        v17 = result + 58928;
        if ( result != -58928 )
          break;
      }
      if ( (*(_QWORD *)(result + 1640) & 4) != 0 )
      {
        v17 = result + 65016;
        if ( result != -65016 )
          break;
      }
    }
LABEL_22:
    hdd_adapter_dev_put_debug(result, 5);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v33 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
    }
    v35[0] = v34;
    hdd_get_next_adapter_no_lock(a1, v34, &v34);
    hdd_validate_next_adapter(v35, &v34, 5);
    if ( v34 )
      hdd_adapter_dev_hold_debug(v34, 5);
    v18 = *(_QWORD *)(a1 + 40);
    if ( (v18 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v18 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      result = v35[0];
      if ( !v35[0] )
        goto LABEL_50;
    }
    else
    {
      raw_spin_unlock(a1 + 32);
      result = v35[0];
      if ( !v35[0] )
        goto LABEL_50;
    }
  }
  while ( 1 )
  {
    is_connecting = hdd_cm_is_connecting(v17);
    if ( !is_connecting )
      break;
    v28 = 1;
    if ( a2 == 3 )
      goto LABEL_37;
LABEL_34:
    LOBYTE(is_sta_key_exchange_in_progress) = 0;
    if ( (v28 & 1) != 0 )
      goto LABEL_47;
LABEL_38:
    result = v35[0];
    if ( v35[0] )
    {
      if ( (unsigned __int8)(73 * ((unsigned int)(v17 - *(_DWORD *)v17 - 52840) >> 3) + 1) > 2u )
        goto LABEL_22;
      v30 = (unsigned __int8)(73 * ((unsigned int)(v17 - *(_DWORD *)v17 - 52840) >> 3) + 1);
      v17 = 0;
      v31 = v35[0] + 6088LL * (unsigned int)v30 + 52840;
      do
      {
        if ( v17 )
          break;
        v32 = *(_QWORD *)(v35[0] + 1640LL) >> v30++;
        v17 = (v32 << 63 >> 63) & v31;
        v31 += 6088;
      }
      while ( v30 != 3 );
    }
    if ( !v17 )
      goto LABEL_22;
  }
  v28 = wlan_hdd_is_link_switch_in_progress(v17) | v16;
  v16 = v28;
  if ( a2 != 3 )
    goto LABEL_34;
LABEL_37:
  is_sta_key_exchange_in_progress = sme_is_sta_key_exchange_in_progress(
                                      *(_QWORD *)(a1 + 16),
                                      *(unsigned __int8 *)(v17 + 8));
  if ( ((v28 | is_sta_key_exchange_in_progress) & 1) == 0 )
    goto LABEL_38;
LABEL_47:
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
    v16 & 1,
    is_sta_key_exchange_in_progress & 1,
    v33);
  hdd_adapter_dev_put_debug(v35[0], 5);
  if ( v34 )
    hdd_adapter_dev_put_debug(v34, 5);
  result = 1;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
