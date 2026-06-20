__int64 __fastcall hdd_get_sap_operating_band(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x1
  __int64 v4; // x8
  __int64 v5; // x0
  unsigned int v6; // w20
  unsigned __int64 v7; // x23
  _DWORD *v8; // x8
  unsigned int v9; // w20
  __int64 v10; // x8
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13[0] = 0;
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
  hdd_get_front_adapter_no_lock(a1, v13);
  if ( v13[0] )
  {
    hdd_adapter_dev_hold_debug(v13[0], 3);
    v3 = v13[0];
  }
  else
  {
    v3 = 0;
  }
  hdd_get_next_adapter_no_lock(a1, v3, &v12);
  if ( v12 )
    hdd_adapter_dev_hold_debug(v12, 3);
  v4 = *(_QWORD *)(a1 + 40);
  if ( (v4 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 32);
    v5 = v13[0];
    if ( v13[0] )
      goto LABEL_12;
LABEL_37:
    v6 = 0;
    goto LABEL_38;
  }
  *(_QWORD *)(a1 + 40) = v4 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 32);
  v5 = v13[0];
  if ( !v13[0] )
    goto LABEL_37;
LABEL_12:
  v6 = 0;
  v7 = _ReadStatusReg(SP_EL0);
  do
  {
    while ( 1 )
    {
      if ( *(_DWORD *)(v5 + 40) == 1 )
      {
        v8 = *(_DWORD **)(v5 + 52832);
        if ( (*(_DWORD *)(*(_QWORD *)v8 + 40LL) & 0xFFFFFFFD) == 1 )
        {
          v9 = v8[606];
          if ( wlan_reg_is_24ghz_ch_freq(v9) )
          {
            v6 = 1;
          }
          else if ( wlan_reg_is_5ghz_ch_freq(v9) )
          {
            v6 = 2;
          }
          else if ( wlan_reg_is_6ghz_chan_freq(v9) )
          {
            v6 = 2;
          }
          else
          {
            v6 = 3;
          }
        }
        else
        {
          v6 = 3;
        }
        v5 = v13[0];
      }
      hdd_adapter_dev_put_debug(v5, 3);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v7 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 32);
      }
      else
      {
        raw_spin_lock_bh(a1 + 32);
        *(_QWORD *)(a1 + 40) |= 1uLL;
      }
      v13[0] = v12;
      hdd_get_next_adapter_no_lock(a1, v12, &v12);
      hdd_validate_next_adapter(v13, &v12, 3);
      if ( v12 )
        hdd_adapter_dev_hold_debug(v12, 3);
      v10 = *(_QWORD *)(a1 + 40);
      if ( (v10 & 1) != 0 )
        break;
      raw_spin_unlock(a1 + 32);
      v5 = v13[0];
      if ( !v13[0] )
        goto LABEL_38;
    }
    *(_QWORD *)(a1 + 40) = v10 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    v5 = v13[0];
  }
  while ( v13[0] );
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v6;
}
