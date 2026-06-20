__int64 __fastcall ipa3_send_nop_desc(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x9
  _QWORD *v3; // x8
  __int64 v4; // x20
  __int64 v5; // x10
  _QWORD *v6; // x21
  __int64 v7; // x2
  _QWORD *v8; // x1
  __int64 v9; // x8
  __int64 v10; // x0
  int v11; // w8
  __int64 v12; // x10
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  __int64 v17; // [xsp+8h] [xbp-18h]
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v1 = result;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v16 = 0;
  if ( ipa3_ctx )
  {
    result = *(_QWORD *)(ipa3_ctx + 34160);
    if ( result )
      result = ipc_log_string(
                 result,
                 "ipa %s:%d gsi send NOP for ch: %lu\n",
                 "ipa3_send_nop_desc",
                 555,
                 *(_QWORD *)(*(_QWORD *)(v1 + 1432) + 8LL));
  }
  if ( !*(_DWORD *)(v1 - 184) )
  {
    raw_spin_lock_bh(v1 + 1492);
    v2 = *(_QWORD **)(v1 + 1472);
    if ( v2 == (_QWORD *)(v1 + 1472) )
    {
      raw_spin_unlock_bh(v1 + 1492);
      v4 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29440), 3520);
      raw_spin_lock_bh(v1 + 1492);
      if ( v4 )
      {
LABEL_10:
        v6 = (_QWORD *)(v4 + 32);
        *(_QWORD *)(v4 + 32) = v4 + 32;
        *(_QWORD *)(v4 + 40) = v4 + 32;
        *(_DWORD *)(v4 + 80) = 1;
        *(_BYTE *)(v4 + 96) = 1;
        *(_QWORD *)(v4 + 72) = v1 - 192;
        if ( (*(_BYTE *)(v1 - 67) & 1) == 0 )
        {
          raw_spin_unlock_bh(v1 + 1492);
          result = kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29440), v4);
          goto LABEL_20;
        }
        v7 = v1 + 1440;
        v8 = *(_QWORD **)(v1 + 1448);
        if ( v6 == (_QWORD *)(v1 + 1440) || v6 == v8 || *v8 != v7 )
        {
          _list_add_valid_or_report(v4 + 32, v8);
        }
        else
        {
          *(_QWORD *)(v1 + 1448) = v6;
          *(_QWORD *)(v4 + 32) = v7;
          *(_QWORD *)(v4 + 40) = v8;
          *v8 = v6;
        }
        v17 = 0x200000000LL;
        v18 = v4;
        v9 = *(_QWORD *)(v1 + 1432);
        WORD1(v17) = 512;
        v10 = *(_QWORD *)(v9 + 8);
        v16 = 0;
        if ( !(unsigned int)gsi_queue_xfer(v10, 1, &v16, 1) )
        {
          v11 = *(_DWORD *)(v1 - 192);
          *(_BYTE *)(v1 - 67) = 0;
          *(_DWORD *)(v1 - 192) = v11 + 1;
          result = raw_spin_unlock_bh(v1 + 1492);
          *(_BYTE *)(ipa3_ctx + 31960) = 1;
          goto LABEL_20;
        }
        _list_del_entry((_QWORD *)(v4 + 32));
        v12 = ipa3_ctx;
        *(_QWORD *)(v4 + 32) = 0xDEAD000000000100LL;
        *(_QWORD *)(v4 + 40) = 0xDEAD000000000122LL;
        kmem_cache_free(*(_QWORD *)(v12 + 29440), v4);
        raw_spin_unlock_bh(v1 + 1492);
        printk(&unk_3FDD63, "ipa3_send_nop_desc");
        v13 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v14 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v14 )
          {
            ipc_log_string(
              v14,
              "ipa %s:%d gsi_queue_xfer for ch:%lu failed\n",
              "ipa3_send_nop_desc",
              598,
              *(_QWORD *)(*(_QWORD *)(v1 + 1432) + 8LL));
            v13 = ipa3_ctx;
          }
          v15 = *(_QWORD *)(v13 + 34160);
          if ( v15 )
            ipc_log_string(
              v15,
              "ipa %s:%d gsi_queue_xfer for ch:%lu failed\n",
              "ipa3_send_nop_desc",
              598,
              *(_QWORD *)(*(_QWORD *)(v1 + 1432) + 8LL));
        }
LABEL_19:
        result = queue_work_on(32, *(_QWORD *)(v1 + 1560), v1);
        goto LABEL_20;
      }
    }
    else
    {
      v3 = (_QWORD *)v2[1];
      v4 = (__int64)(v2 - 4);
      if ( (_QWORD *)*v3 == v2 && (v5 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
      {
        *(_QWORD *)(v5 + 8) = v3;
        *v3 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(v1 + 1472));
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      --*(_DWORD *)(v1 + 1488);
      *(_QWORD *)(v4 + 88) = 0;
      *(_QWORD *)(v4 + 96) = 0;
      *(_QWORD *)(v4 + 72) = 0;
      *(_QWORD *)(v4 + 80) = 0;
      *(_QWORD *)(v4 + 56) = 0;
      *(_QWORD *)(v4 + 64) = 0;
      *(_QWORD *)(v4 + 40) = 0;
      *(_QWORD *)(v4 + 48) = 0;
      *(_QWORD *)(v4 + 24) = 0;
      *(_QWORD *)(v4 + 32) = 0;
      *(_QWORD *)(v4 + 8) = 0;
      *(_QWORD *)(v4 + 16) = 0;
      *(_QWORD *)v4 = 0;
      if ( v4 )
        goto LABEL_10;
    }
    raw_spin_unlock_bh(v1 + 1492);
    goto LABEL_19;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
