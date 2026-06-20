unsigned int *__fastcall ipa3_replenish_wlan_rx_cache(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  unsigned int v4; // w26
  __int64 v5; // x8
  __int64 *v6; // x20
  __int64 **v7; // x8
  __int64 *v8; // x27
  int v9; // w9
  __int64 v10; // x9
  __int64 v11; // x8
  int v12; // w0
  unsigned int v13; // w9
  unsigned int *result; // x0
  __int64 v15; // x0
  int v16; // w19
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  __int64 v21; // [xsp+8h] [xbp-18h]
  __int64 *v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v21 = 0;
  v22 = nullptr;
  v20 = 0;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d \n", "ipa3_replenish_wlan_rx_cache", 3243);
      v2 = ipa3_ctx;
    }
  }
  raw_spin_lock_bh(v2 + 34608);
  v4 = *(_DWORD *)a1;
  v5 = ipa3_ctx;
  if ( *(_DWORD *)a1 >= *(_DWORD *)(a1 + 164)
    || (v6 = *(__int64 **)(ipa3_ctx + 34632), v6 == (__int64 *)(ipa3_ctx + 34632)) )
  {
LABEL_16:
    result = (unsigned int *)raw_spin_unlock_bh(v5 + 34608);
    if ( v4 < *(_DWORD *)(a1 + 164) && *(_DWORD *)(ipa3_ctx + 34616) <= 0x383u )
    {
      result = ipa3_replenish_rx_cache((unsigned int *)a1);
      *(_DWORD *)(ipa3_ctx + 34616) += *(_DWORD *)a1 - v4;
    }
  }
  else
  {
    while ( 1 )
    {
      v8 = (__int64 *)*v6;
      v7 = (__int64 **)v6[1];
      if ( *v7 == v6 && (__int64 *)v8[1] == v6 )
      {
        v8[1] = (__int64)v7;
        *v7 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
      }
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      v9 = *(_DWORD *)(ipa3_ctx + 34620);
      if ( v9 )
        *(_DWORD *)(ipa3_ctx + 34620) = v9 - 1;
      *((_DWORD *)v6 + 10) = 0;
      v10 = v6[3];
      v6[10] = a1;
      v11 = *(_QWORD *)(a1 + 1624);
      v21 = 50333696;
      v22 = v6;
      v20 = v10;
      v12 = gsi_queue_xfer(*(_QWORD *)(v11 + 8), 1, &v20, 1);
      if ( v12 )
        break;
      v13 = *(_DWORD *)(a1 + 164);
      v4 = *(_DWORD *)a1 + 1;
      *(_DWORD *)a1 = v4;
      v5 = ipa3_ctx;
      if ( v4 >= v13 )
      {
        v15 = ipa3_ctx + 34608;
        goto LABEL_20;
      }
      v6 = v8;
      if ( v8 == (__int64 *)(ipa3_ctx + 34632) )
        goto LABEL_16;
    }
    v16 = v12;
    printk(&unk_3D5757, "ipa3_replenish_wlan_rx_cache");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_replenish_wlan_rx_cache", 3272, v16);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_replenish_wlan_rx_cache", 3272, v16);
    }
    _list_del_entry(v6);
    *v6 = 0xDEAD000000000100LL;
    v6[1] = 0xDEAD000000000122LL;
    v15 = ipa3_ctx + 34608;
LABEL_20:
    result = (unsigned int *)raw_spin_unlock_bh(v15);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
