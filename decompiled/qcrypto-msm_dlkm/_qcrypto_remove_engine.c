__int64 __fastcall qcrypto_remove_engine(__int64 *a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  __int64 **v4; // x8
  __int64 v5; // x9
  __int64 *v6; // x10
  int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 result; // x0
  __int64 *v11; // x19
  __int64 *v12; // x20
  __int64 *v13; // t1
  int v14; // w8
  __int64 *v15; // x22
  __int64 **v16; // x8
  __int64 *v17; // x9

  v1 = a1[4];
  v3 = raw_spin_lock_irqsave(v1 + 52);
  v4 = (__int64 **)a1[1];
  v5 = v3;
  if ( *v4 == a1 && (v6 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
  {
    v6[1] = (__int64)v4;
    *v4 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  v7 = *((unsigned __int8 *)a1 + 253);
  *a1 = 0xDEAD000000000100LL;
  a1[1] = 0xDEAD000000000122LL;
  if ( v7 == 1 )
  {
    v8 = *(_QWORD *)(v1 + 112);
    *(_QWORD *)(v1 + 296) = 0;
    if ( v8 )
    {
      *(_BYTE *)(v8 + 253) = 1;
      *(_QWORD *)(v1 + 296) = v8;
    }
  }
  if ( *(__int64 **)(v1 + 184) == a1 )
    *(_QWORD *)(v1 + 184) = 0;
  if ( *(__int64 **)(v1 + 304) == a1 )
    *(_QWORD *)(v1 + 304) = 0;
  raw_spin_unlock_irqrestore(v1 + 52, v5);
  --*(_DWORD *)(v1 + 128);
  cancel_work_sync(a1 + 20);
  cancel_work_sync(a1 + 24);
  timer_delete_sync(a1 + 15);
  if ( a1[5] )
    icc_put();
  v9 = a1[30];
  a1[5] = 0;
  result = kfree_sensitive(v9);
  if ( !*(_DWORD *)(v1 + 128) )
  {
    v13 = *(__int64 **)(v1 + 56);
    v12 = (__int64 *)(v1 + 56);
    v11 = v13;
    if ( v13 != v12 )
    {
      do
      {
        v14 = *((_DWORD *)v11 + 354);
        v15 = (__int64 *)*v11;
        if ( v14 )
        {
          if ( v14 != 1 )
          {
LABEL_22:
            if ( v14 != 2 )
              goto LABEL_24;
LABEL_23:
            crypto_unregister_aead(v11 + 121);
            goto LABEL_24;
          }
        }
        else
        {
          crypto_unregister_skcipher(v11 + 2);
          v14 = *((_DWORD *)v11 + 354);
          if ( v14 != 1 )
            goto LABEL_22;
        }
        crypto_unregister_ahash(v11 + 61);
        if ( *((_DWORD *)v11 + 354) == 2 )
          goto LABEL_23;
LABEL_24:
        v16 = (__int64 **)v11[1];
        if ( *v16 == v11 && (v17 = (__int64 *)*v11, *(__int64 **)(*v11 + 8) == v11) )
        {
          v17[1] = (__int64)v16;
          *v16 = v17;
        }
        else
        {
          _list_del_entry_valid_or_report(v11);
        }
        *v11 = 0xDEAD000000000100LL;
        v11[1] = 0xDEAD000000000122LL;
        result = kfree_sensitive(v11);
        v11 = v15;
      }
      while ( v15 != v12 );
    }
  }
  return result;
}
