int *__fastcall ipa3_fast_replenish_rx_cache(int *result)
{
  int *v1; // x19
  int v2; // w21
  unsigned int v3; // w22
  unsigned int v4; // w8
  __int64 v5; // x1
  __int64 v6; // x9
  _QWORD *v7; // x11
  __int64 v8; // x10
  __int64 v9; // x13
  int v10; // w0
  int v11; // w0
  _DWORD *v12; // x8
  unsigned int v13; // w10
  int v14; // w11
  unsigned int v15; // w9
  int v16; // w8
  __int64 v17; // x9
  int v18; // w20
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  int v22; // w20
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  _QWORD s[109]; // [xsp+8h] [xbp-368h] BYREF

  s[108] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)(result[41] - *result) < 0x14 )
    goto LABEL_38;
  v1 = result;
  memset(s, 0, 0x360u);
  raw_spin_lock_bh(v1 + 421);
  v2 = *v1;
  v3 = *(_DWORD *)(*((_QWORD *)v1 + 46) + 8LL);
  v4 = v1[41];
  if ( *v1 >= v4 )
  {
    v5 = 0;
  }
  else
  {
    v5 = 0;
    do
    {
      v6 = *((_QWORD *)v1 + 46);
      if ( v3 == *(_DWORD *)(v6 + 12) )
        break;
      if ( (unsigned int)v5 > 0x23 )
        __break(1u);
      v7 = &s[3 * (unsigned int)v5];
      v5 = (unsigned int)(v5 + 1);
      ++v2;
      v8 = *(_QWORD *)(*(_QWORD *)v6 + 8LL * v3);
      v9 = *(_QWORD *)(v8 + 24);
      *((_WORD *)v7 + 4) = v1[40];
      *((_WORD *)v7 + 5) = 1792;
      *((_DWORD *)v7 + 3) = 0;
      *v7 = v9;
      v7[2] = v8;
      if ( v3 + 1 == *(_DWORD *)(v6 + 16) )
        v3 = 0;
      else
        ++v3;
      if ( (_DWORD)v5 == 36 )
      {
        v10 = gsi_queue_xfer(*(_QWORD *)(*((_QWORD *)v1 + 203) + 8LL), v5, s, 0);
        if ( v10 )
        {
          v22 = v10;
          printk(&unk_3D5757, "ipa3_fast_replenish_rx_cache");
          v23 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v24 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v24 )
            {
              ipc_log_string(v24, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_fast_replenish_rx_cache", 3746, v22);
              v23 = ipa3_ctx;
            }
            v25 = *(_QWORD *)(v23 + 34160);
            if ( v25 )
              ipc_log_string(v25, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_fast_replenish_rx_cache", 3746, v22);
          }
          v5 = 36;
          __break(0x800u);
          break;
        }
        v4 = v1[41];
        v5 = 0;
      }
    }
    while ( v2 < v4 );
  }
  v11 = gsi_queue_xfer(*(_QWORD *)(*((_QWORD *)v1 + 203) + 8LL), v5, s, 1);
  if ( v11 )
  {
    v18 = v11;
    printk(&unk_3D5757, "ipa3_fast_replenish_rx_cache");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_fast_replenish_rx_cache", 3763, v18);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
        ipc_log_string(v21, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_fast_replenish_rx_cache", 3763, v18);
    }
    __break(0x800u);
  }
  else
  {
    __dsb(0xFu);
    *(_DWORD *)(*((_QWORD *)v1 + 46) + 8LL) = v3;
    *v1 = v2;
  }
  result = (int *)raw_spin_unlock_bh(v1 + 421);
  v12 = *((_DWORD **)v1 + 46);
  if ( !v12[5] )
  {
    v13 = v12[4];
    v14 = *(_DWORD *)(*((_QWORD *)v1 + 203) + 4LL);
    v15 = (v12[3] - v12[2]) % v13;
    if ( (v14 == 95 || v14 == 35) && *(_BYTE *)(ipa3_ctx + 45386) == 1 )
    {
      if ( v15 >= *(_DWORD *)(ipa3_ctx + 48792) / 2 )
        goto LABEL_24;
    }
    else if ( v15 >= v13 >> 1 )
    {
      goto LABEL_24;
    }
    v12[5] = 1;
    result = (int *)queue_work_on(32, *((_QWORD *)v1 + 220), v1 + 82);
  }
LABEL_24:
  if ( v2 <= 32 )
  {
    v16 = *(_DWORD *)(*((_QWORD *)v1 + 203) + 4LL);
    if ( v16 > 104 )
    {
      if ( v16 == 105 )
      {
        v17 = 32872;
        goto LABEL_36;
      }
      if ( v16 == 121 )
      {
        v17 = 32852;
        goto LABEL_36;
      }
      if ( v16 != 127 )
      {
LABEL_37:
        result = (int *)queue_delayed_work_on(32, *((_QWORD *)v1 + 219), v1 + 56, 1);
        goto LABEL_38;
      }
    }
    else if ( v16 != 33 )
    {
      if ( v16 != 35 && v16 != 95 )
        goto LABEL_37;
      v17 = 32840;
      goto LABEL_36;
    }
    v17 = 32860;
LABEL_36:
    ++*(_DWORD *)(ipa3_ctx + v17);
    goto LABEL_37;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
