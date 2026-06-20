__int64 __fastcall btfmcodec_dev_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x21
  __int64 v4; // x22
  int v7; // w20
  unsigned __int64 v8; // x0
  unsigned int v9; // w9
  void *v10; // x0
  const void *v11; // x21
  __int64 v12; // x0
  __int64 v13; // x20
  void *v14; // x0

  v3 = *(_QWORD *)(a1 + 32);
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 976)) == 0 || *(_DWORD *)(v4 + 136) == 1 )
  {
    v9 = (unsigned __int8)log_lvl;
    _ReadStatusReg(SP_EL0);
    if ( v9 < 8 )
      v10 = &unk_D856;
    else
      v10 = &unk_C2E8;
    printk(v10, "btfmcodec_dev_write");
    return -22;
  }
  if ( !(unsigned int)mutex_lock_interruptible(v4 + 144) )
  {
    if ( a3 <= 8 )
    {
      printk(&unk_DD84, "btfmcodec_dev_write");
    }
    else
    {
      if ( !*(_DWORD *)(*(_QWORD *)(v3 + 976) + 136LL) )
      {
        printk(&unk_CA0F, "btfmcodec_dev_write");
        v7 = -102;
        goto LABEL_17;
      }
      if ( (unsigned __int8)log_lvl >= 4u )
        printk(&unk_DC53, "btfmcodec_dev_write");
      v8 = memdup_user(a2, a3);
      if ( v8 >= 0xFFFFFFFFFFFFF001LL )
      {
        v7 = v8;
        goto LABEL_17;
      }
      v11 = (const void *)v8;
      v12 = _alloc_skb((unsigned int)(8 * a3), 3264, 0, 0xFFFFFFFFLL);
      if ( !v12 )
      {
        printk(&unk_C224, "btfmcodec_dev_write");
        v7 = -12;
        goto LABEL_17;
      }
      v13 = v12;
      v14 = (void *)skb_put(v12, (unsigned int)a3);
      memcpy(v14, v11, (unsigned int)a3);
      skb_queue_tail(v4 + 320, v13);
      queue_work_on(32, system_wq, v4 + 368);
      kfree(v11);
    }
    v7 = 0;
    goto LABEL_17;
  }
  v7 = -512;
LABEL_17:
  mutex_unlock(v4 + 144);
  if ( (unsigned __int8)log_lvl >= 4u )
    printk(&unk_C190, "btfmcodec_dev_write");
  if ( v7 >= 0 )
    return a3;
  else
    return v7;
}
