__int64 __fastcall win_count_config_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x2
  int v7; // w8
  char v8; // w8
  __int64 v9; // x0
  __int64 v10; // x0
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v12 = 0;
  if ( !(unsigned int)kstrtoint(a3, 0, &v12) )
  {
    if ( v12 < 0 )
    {
      printk(&unk_AB45, "win_count_config_store", v6);
      a4 = -22;
      goto LABEL_12;
    }
    mutex_lock(v5 + 192);
    v7 = *(unsigned __int8 *)(v5 + 52);
    if ( v7 == 1 && *(_BYTE *)(v5 + 53) == 1 )
    {
      *(_BYTE *)(v5 + 53) = 0;
      cancel_delayed_work_sync(v5 + 88);
      v8 = *(_BYTE *)(v5 + 52);
      *(_DWORD *)(v5 + 260) = v12;
      if ( (v8 & 1) == 0 )
        goto LABEL_11;
    }
    else
    {
      *(_DWORD *)(v5 + 260) = v12;
      if ( !v7 )
      {
LABEL_11:
        mutex_unlock(v5 + 192);
        goto LABEL_12;
      }
    }
    if ( (*(_BYTE *)(v5 + 53) & 1) == 0 )
    {
      v9 = *(unsigned int *)(v5 + 80);
      *(_BYTE *)(v5 + 53) = 1;
      v10 = _msecs_to_jiffies(v9);
      queue_delayed_work_on(32, system_wq, v5 + 88, v10);
    }
    goto LABEL_11;
  }
  a4 = -22;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return a4;
}
