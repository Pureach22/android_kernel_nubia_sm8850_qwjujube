__int64 __fastcall global_atomic_store(__int64 result, unsigned int *_X1, char a3, __int64 a4, __int64 a5)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v12; // w5
  __int64 v13; // x19
  int v14; // w9
  __int64 v15; // x4
  unsigned __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x22
  __int64 v19; // x20

  if ( (a3 & 1) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    __asm { PRFM            #0x10, [X1] }
    do
    {
      while ( __ldaxr(_X1) )
        ;
    }
    while ( __stxr(1u, _X1) );
    return result;
  }
  if ( *(_BYTE *)(result + 33520) != 1 )
  {
    do
      v12 = __ldaxr(_X1);
    while ( __stxr(v12 & 0xFFFFFFFE, _X1) );
    __dsb(0xFu);
    v13 = *(_QWORD *)_X1;
    if ( (~msm_hw_fence_debug_level & 0x10080) != 0 )
    {
      if ( (v13 & 2) == 0 )
        goto LABEL_14;
    }
    else
    {
      v18 = result;
      printk(&unk_250BF, "_unlock_vm", 252, v13, a5);
      result = v18;
      if ( (v13 & 2) == 0 )
        goto LABEL_14;
    }
    v14 = msm_hw_fence_debug_level;
    v15 = *(_QWORD *)(result + 592) + 1LL;
    *(_QWORD *)(result + 592) = v15;
    if ( (~v14 & 0x10080) == 0 )
    {
      v19 = result;
      printk(&unk_228C8, "_unlock_vm", 261, v13, v15);
      result = v19;
    }
    result = hw_fence_ipcc_trigger_signal(result, *(_DWORD *)(result + 632), *(_DWORD *)(result + 636), 30);
    goto LABEL_14;
  }
  atomic_store(0, _X1);
  __sev();
LABEL_14:
  v16 = _ReadStatusReg(SP_EL0);
  v17 = *(_QWORD *)(v16 + 16) - 1LL;
  *(_DWORD *)(v16 + 16) = v17;
  if ( !v17 || !*(_QWORD *)(v16 + 16) )
    return preempt_schedule(result);
  return result;
}
