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
  unsigned __int64 v16; // x22
  _DWORD *v17; // x21
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x10
  const char *v22; // x2
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24[0] = 0;
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
  hdd_get_front_adapter_no_lock(a1, v24);
  if ( v24[0] )
  {
    hdd_adapter_dev_hold_debug(v24[0], 2);
    v5 = v24[0];
  }
  else
  {
    v5 = 0;
  }
  hdd_get_next_adapter_no_lock(a1, v5, &v23);
  if ( v23 )
    hdd_adapter_dev_hold_debug(v23, 2);
  v6 = *(_QWORD *)(a1 + 40);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    result = v24[0];
    if ( !v24[0] )
      goto LABEL_49;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    result = v24[0];
    if ( !v24[0] )
      goto LABEL_49;
  }
  v16 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(_DWORD *)(result + 40) == a2 )
    {
      if ( (*(_QWORD *)(result + 1640) & 1) != 0 )
      {
        v17 = (_DWORD *)(result + 52840);
        if ( result != -52840 )
          break;
      }
      if ( (*(_QWORD *)(result + 1640) & 2) != 0 )
      {
        v17 = (_DWORD *)(result + 58928);
        if ( result != -58928 )
          break;
      }
      if ( (*(_QWORD *)(result + 1640) & 4) != 0 )
      {
        v17 = (_DWORD *)(result + 65016);
        if ( result != -65016 )
          break;
      }
    }
LABEL_20:
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
    v24[0] = v23;
    hdd_get_next_adapter_no_lock(a1, v23, &v23);
    hdd_validate_next_adapter(v24, &v23, 2);
    if ( v23 )
      hdd_adapter_dev_hold_debug(v23, 2);
    v18 = *(_QWORD *)(a1 + 40);
    if ( (v18 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v18 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      result = v24[0];
      if ( !v24[0] )
        goto LABEL_49;
    }
    else
    {
      raw_spin_unlock(a1 + 32);
      result = v24[0];
      if ( !v24[0] )
        goto LABEL_49;
    }
  }
  while ( a2 )
  {
    if ( a2 == 1
      && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 8), v17[606], v7, v8, v9, v10, v11, v12, v13, v14) & 1) != 0 )
    {
      v22 = "%s: SAP running on DFS channel";
      goto LABEL_46;
    }
LABEL_36:
    result = v24[0];
    if ( v24[0] )
    {
      if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v17 - *v17 - 52840) >> 3) + 1) > 2u )
        goto LABEL_20;
      v19 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v17 - *v17 - 52840) >> 3) + 1);
      v17 = nullptr;
      v20 = v24[0] + 6088LL * (unsigned int)v19 + 52840;
      do
      {
        if ( v17 )
          break;
        v21 = *(_QWORD *)(v24[0] + 1640LL) >> v19++;
        v17 = (_DWORD *)((v21 << 63 >> 63) & v20);
        v20 += 6088;
      }
      while ( v19 != 3 );
    }
    if ( !v17 )
      goto LABEL_20;
  }
  if ( (hdd_cm_is_vdev_associated(v17) & 1) == 0
    || (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 8), v17[175], v7, v8, v9, v10, v11, v12, v13, v14) & 1) == 0 )
  {
    goto LABEL_36;
  }
  v22 = "%s: client connected on DFS channel";
LABEL_46:
  qdf_trace_msg(0x33u, 2u, v22, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_hdd_check_dfs_channel_for_adapter");
  hdd_adapter_dev_put_debug(v24[0], 2);
  if ( v23 )
    hdd_adapter_dev_put_debug(v23, 2);
  result = 1;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
