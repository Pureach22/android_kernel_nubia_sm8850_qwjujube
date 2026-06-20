__int64 __fastcall ipclite_global_spin_unlock(unsigned int a1, unsigned __int64 *a2)
{
  const char *v4; // x1
  __int64 v5; // x2
  const char *v6; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x9
  unsigned int v9; // w19
  unsigned int v15; // w9
  unsigned int v17; // w9
  unsigned int v18; // w19

  if ( !ipclite )
  {
    printk(&unk_F98D, "ipclite", "ipclite_global_spin_unlock");
    return 4294967284LL;
  }
  if ( a1 > 0xFF )
    return 4294967274LL;
  _X8 = (unsigned int *)(*(_QWORD *)(ipclite + 6448) + 4LL * a1);
  if ( (feature_mask & 8) != 0 )
  {
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v17 = __ldxr(_X8);
      if ( v17 != 1 )
        break;
      if ( !__stlxr(0, _X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    v18 = v17 - 1;
    if ( v17 == 1 )
      goto LABEL_11;
    if ( (ipclite_debug_level & 8) == 0 )
      return 4294967274LL;
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_F28D, "ipclite", "ipclite_global_spin_unlock");
      if ( (ipclite_debug_control & 4) == 0 )
        return 4294967274LL;
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      return 4294967274LL;
    }
    v6 = "APPS:%s:ipclite atomic lock release failed,owner=%d";
    v4 = (const char *)&unk_1039F;
    v5 = v18;
LABEL_30:
    ipclite_inmem_log(v6, v4, v5);
    return 4294967274LL;
  }
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stlxr(v15 & 0xFFFFFFFE, _X8) );
  __dmb(0xBu);
  if ( (v15 & 1) == 0 )
  {
    if ( (ipclite_debug_level & 1) == 0 )
      return 4294967274LL;
    if ( (ipclite_debug_control & 1) != 0 )
    {
      v9 = a1;
      printk(&unk_F2C5, "ipclite", "ipclite_global_spin_unlock");
      a1 = v9;
      if ( (ipclite_debug_control & 4) == 0 )
        return 4294967274LL;
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      return 4294967274LL;
    }
    v4 = "ERR";
    v5 = a1;
    v6 = "APPS:%s:idx %d is not acquired by current core";
    goto LABEL_30;
  }
LABEL_11:
  _WriteStatusReg(DAIF, *a2);
  StatusReg = _ReadStatusReg(SP_EL0);
  v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v8;
  if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
    preempt_schedule();
  return 0;
}
