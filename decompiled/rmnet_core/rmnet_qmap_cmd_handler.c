__int64 __fastcall rmnet_qmap_cmd_handler(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  char *v3; // x20
  __int64 lock; // x0
  __int64 v5; // x8
  char v6; // w8
  char v7; // w9
  _BYTE *v8; // x20
  unsigned __int8 v9; // w1
  char v10; // t1
  __int64 v11; // x0

  if ( result )
  {
    v1 = result;
    v2 = *(unsigned int *)(result + 112);
    if ( (unsigned int)v2 < 0xC )
      return sk_skb_reason_drop(0, v1, 2);
    v3 = *(char **)(result + 224);
    if ( (*v3 & 0x80000000) == 0 || (bswap32(*((unsigned __int16 *)v3 + 1)) >> 16) + 4LL != v2 )
      return sk_skb_reason_drop(0, v1, 2);
    lock = _rcu_read_lock();
    v5 = (unsigned __int8)v3[4];
    if ( (unsigned int)v5 <= 0x2C )
    {
      if ( ((1LL << v5) & 0x1F0180000000LL) != 0 )
      {
        lock = rmnet_module_hook_perf_cmd_ingress(v1);
LABEL_21:
        _rcu_read_unlock(lock);
        return sk_skb_reason_drop(0, v1, 2);
      }
      if ( ((1LL << v5) & 0x6000000) != 0 )
      {
        lock = ll_qmap_cmd_handler(v1);
        goto LABEL_14;
      }
      if ( v5 == 34 )
      {
        lock = rmnet_module_hook_aps_data_report(v1);
        goto LABEL_21;
      }
    }
    if ( (unsigned int)(v5 - 10) >= 5 )
    {
      v6 = v3[5];
      if ( (v6 & 3) != 0 )
        goto LABEL_21;
      v7 = 2;
      goto LABEL_17;
    }
    lock = dfc_qmap_cmd_handler(v1);
LABEL_14:
    if ( (_DWORD)lock == -2 )
    {
      v10 = v3[5];
      v8 = v3 + 5;
      v6 = v10;
      v9 = 0;
      v7 = 1;
      goto LABEL_19;
    }
    if ( (_DWORD)lock == -1 )
      goto LABEL_21;
    v6 = v3[5];
    v7 = lock & 3;
LABEL_17:
    v8 = v3 + 5;
    v9 = -1;
LABEL_19:
    *v8 = v6 & 0xFC | v7;
    v11 = rmnet_qmap_send(v1, v9, 0);
    return _rcu_read_unlock(v11);
  }
  return result;
}
