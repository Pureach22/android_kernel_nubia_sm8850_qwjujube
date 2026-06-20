__int64 __fastcall spec_sync_wait_bind_array(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x8
  __int64 v9; // x0
  int v10; // w20
  __int64 result; // x0
  _QWORD v12[6]; // [xsp+0h] [xbp-30h] BYREF

  v12[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (*(_QWORD *)(a1 + 48) & 0x10000) != 0 )
  {
    if ( (*(_QWORD *)(a1 + 48) & 0x20000) != 0 )
      goto LABEL_18;
    v4 = _msecs_to_jiffies(a2);
    v5 = *(_QWORD *)(a1 + 48);
    if ( ((v4 == 0) & ((unsigned int)v5 >> 17)) != 0 )
      v6 = 1;
    else
      v6 = v4;
    if ( (v5 & 0x20000) == 0 && v6 )
    {
      memset(v12, 0, 40);
      v7 = _msecs_to_jiffies(a2);
      init_wait_entry(v12, 0);
      while ( 1 )
      {
        prepare_to_wait_event(&unk_7C00, v12, 2);
        v8 = *(_QWORD *)(a1 + 48);
        v9 = ((v7 == 0) & ((unsigned int)v8 >> 17)) != 0 ? 1LL : v7;
        if ( (v8 & 0x20000) != 0 || !v9 )
          break;
        v7 = schedule_timeout();
      }
      v10 = v9;
      finish_wait(&unk_7C00, v12);
      LODWORD(v6) = v10;
    }
    if ( (_DWORD)v6 )
    {
LABEL_18:
      result = 0;
    }
    else
    {
      printk(&unk_7A43, "spec_sync_wait_bind_array");
      result = 4294967186LL;
    }
  }
  else
  {
    printk(&unk_7839, "spec_sync_wait_bind_array");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
