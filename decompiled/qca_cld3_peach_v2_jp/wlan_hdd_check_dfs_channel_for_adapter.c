__int64 __fastcall wlan_hdd_check_dfs_channel_for_adapter(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x1
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  unsigned __int64 v16; // x25
  _DWORD *v17; // x21
  __int64 v18; // x8
  const char *v19; // x2
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21[0] = 0;
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
  hdd_get_front_adapter_no_lock(a1, v21);
  if ( v21[0] )
  {
    hdd_adapter_dev_hold_debug(v21[0], 2);
    v5 = v21[0];
  }
  else
  {
    v5 = 0;
  }
  hdd_get_next_adapter_no_lock(a1, v5, &v20);
  if ( v20 )
    hdd_adapter_dev_hold_debug(v20, 2);
  v6 = *(_QWORD *)(a1 + 40);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    result = v21[0];
    if ( !v21[0] )
      goto LABEL_44;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    result = v21[0];
    if ( !v21[0] )
      goto LABEL_44;
  }
  v16 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(_DWORD *)(result + 40) == a2 && (*(_QWORD *)(result + 1640) & 1) != 0 )
    {
      v17 = (_DWORD *)(result + 52832);
      if ( result != -52832 )
        break;
    }
LABEL_28:
    hdd_adapter_dev_put_debug(result, 2);
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
    v21[0] = v20;
    hdd_get_next_adapter_no_lock(a1, v20, &v20);
    hdd_validate_next_adapter(v21, &v20, 2);
    if ( v20 )
      hdd_adapter_dev_hold_debug(v20, 2);
    v18 = *(_QWORD *)(a1 + 40);
    if ( (v18 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v18 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      result = v21[0];
      if ( !v21[0] )
        goto LABEL_44;
    }
    else
    {
      raw_spin_unlock(a1 + 32);
      result = v21[0];
      if ( !v21[0] )
        goto LABEL_44;
    }
  }
  while ( a2 )
  {
    if ( a2 == 1
      && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 8), v17[538], v7, v8, v9, v10, v11, v12, v13, v14) & 1) != 0 )
    {
      v19 = "%s: SAP running on DFS channel";
      goto LABEL_41;
    }
LABEL_25:
    result = v21[0];
    if ( v21[0] )
    {
      if ( (unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v17 - *v17 - 52832) >> 4))
        || (*(_QWORD *)(v21[0] + 1640LL) & 1) == 0 )
      {
        goto LABEL_28;
      }
      v17 = (_DWORD *)(v21[0] + 52832LL);
    }
    if ( !v17 )
      goto LABEL_28;
  }
  if ( (hdd_cm_is_vdev_associated(v17) & 1) == 0
    || (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 8), v17[173], v7, v8, v9, v10, v11, v12, v13, v14) & 1) == 0 )
  {
    goto LABEL_25;
  }
  v19 = "%s: client connected on DFS channel";
LABEL_41:
  qdf_trace_msg(0x33u, 2u, v19, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_hdd_check_dfs_channel_for_adapter");
  hdd_adapter_dev_put_debug(v21[0], 2);
  if ( v20 )
    hdd_adapter_dev_put_debug(v20, 2);
  result = 1;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
