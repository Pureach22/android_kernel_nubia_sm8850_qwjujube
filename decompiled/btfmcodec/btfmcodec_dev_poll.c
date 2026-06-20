__int64 __fastcall btfmcodec_dev_poll(__int64 a1, void (**a2)(void))
{
  __int64 v2; // x21
  __int64 v4; // x21
  void (*v5)(void); // x8
  __int64 v6; // x1
  unsigned int v7; // w19
  unsigned int v9; // w9
  void *v10; // x0

  v2 = *(_QWORD *)(a1 + 32);
  if ( (unsigned __int8)log_lvl >= 4u )
  {
    printk(&unk_C70A, "btfmcodec_dev_poll");
    if ( !v2 )
      goto LABEL_18;
  }
  else if ( !v2 )
  {
    goto LABEL_18;
  }
  v4 = *(_QWORD *)(v2 + 976);
  if ( !v4 || *(_DWORD *)(v4 + 136) == 1 )
  {
LABEL_18:
    v9 = (unsigned __int8)log_lvl;
    _ReadStatusReg(SP_EL0);
    if ( v9 < 8 )
      v10 = &unk_D856;
    else
      v10 = &unk_C2E8;
    printk(v10, "btfmcodec_dev_poll");
    return (unsigned int)-22;
  }
  if ( a2 )
  {
    v5 = *a2;
    if ( *a2 )
    {
      if ( *((_DWORD *)v5 - 1) != -442429149 )
        __break(0x8228u);
      v5();
      __dmb(0xBu);
    }
  }
  mutex_lock(v4 + 144);
  if ( *(_DWORD *)(v4 + 136) == 1 )
  {
    printk(&unk_C4F5, "btfmcodec_dev_poll");
    mutex_unlock(v4 + 144);
    return 16;
  }
  else
  {
    v6 = raw_spin_lock_irqsave(v4 + 520);
    if ( *(_QWORD *)(v4 + 528) == v4 + 528 )
      v7 = 0;
    else
      v7 = 65;
    raw_spin_unlock_irqrestore(v4 + 520, v6);
    mutex_unlock(v4 + 144);
    if ( (unsigned __int8)log_lvl >= 4u )
      printk(&unk_CCA1, "btfmcodec_dev_poll");
  }
  return v7;
}
