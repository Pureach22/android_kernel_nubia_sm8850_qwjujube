__int64 __fastcall update_wptr_1(_QWORD *a1, char a2, char a3)
{
  __int64 v3; // x23
  __int64 v7; // x21
  int v8; // w0
  __int64 v9; // x1
  int v10; // w0
  _BOOL4 v11; // w22
  __int64 v12; // x24
  __int64 result; // x0
  unsigned int v20; // w9

  v3 = a1[2455];
  v7 = raw_spin_lock_irqsave(v3 + 1292);
  if ( (a3 & 1) != 0 )
  {
    v8 = kgsl_regmap_read(a1 + 1650);
    v9 = *(unsigned int *)(v3 + 20);
    if ( v8 != (_DWORD)v9 )
    {
      kgsl_regmap_write(a1 + 1650, v9);
LABEL_7:
      v11 = 0;
      goto LABEL_8;
    }
LABEL_6:
    if ( (a2 & 1) == 0 )
      return raw_spin_unlock_irqrestore(v3 + 1292, v7);
    goto LABEL_7;
  }
  if ( *(_BYTE *)(v3 + 1296) != 1 )
    goto LABEL_6;
  v10 = gen8_fenced_write(a1, 2055, *(_DWORD *)(v3 + 20), 1);
  *(_BYTE *)(v3 + 1296) = 0;
  v11 = v10 != 0;
LABEL_8:
  v12 = jiffies;
  *(_QWORD *)(v3 + 1248) = _msecs_to_jiffies((unsigned int)adreno_drawobj_timeout) + v12;
  result = raw_spin_unlock_irqrestore(v3 + 1292, v7);
  if ( (a3 & 1) == 0 && v11 )
  {
    gmu_core_fault_snapshot(a1, 0);
    _X8 = (unsigned int *)(a1 + 3056);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 | 0x80, _X8) );
    __dmb(0xAu);
    return kthread_queue_work(a1[3050], a1 + 3051);
  }
  return result;
}
