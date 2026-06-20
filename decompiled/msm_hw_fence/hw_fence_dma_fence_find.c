__int64 __fastcall hw_fence_dma_fence_find(__int64 a1, __int64 a2, char a3)
{
  int v6; // w19
  __int64 v7; // x1
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v11; // x22
  __int64 v12; // x8
  __int64 v14; // x23
  const char *v16; // x3
  unsigned int v21; // w9

  v6 = a2 & 0xFFF;
  v7 = raw_spin_lock_irqsave(a1 + 748);
  v8 = *(_QWORD *)(a1 + 8LL * ((unsigned int)(1640531527 * v6) >> 20) + 752);
  v9 = v8 - 184;
  if ( v8 )
    _ZF = v8 == 184;
  else
    _ZF = 1;
  if ( _ZF )
  {
    v11 = 0;
    goto LABEL_16;
  }
  while ( *(_QWORD *)(v9 + 176) != a2 )
  {
    v12 = *(_QWORD *)(v9 + 184);
    v11 = 0;
    if ( v12 )
    {
      v9 = v12 - 184;
      if ( v9 )
        continue;
    }
    goto LABEL_16;
  }
  if ( (a3 & 1) != 0 )
  {
    _X0 = (unsigned int *)(v9 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v21 = __ldxr(_X0);
    while ( __stxr(v21 + 1, _X0) );
    if ( v21 )
    {
      v11 = v9;
      if ( (((v21 + 1) | v21) & 0x80000000) == 0 )
        goto LABEL_16;
      v14 = v7;
    }
    else
    {
      v11 = v9;
      v14 = v7;
    }
    refcount_warn_saturate();
    v7 = v14;
  }
  else
  {
    v11 = v9;
  }
LABEL_16:
  raw_spin_unlock_irqrestore(a1 + 748, v7);
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
  {
    if ( v11 )
      v16 = "found";
    else
      v16 = "not found";
    printk(&unk_27832, "hw_fence_dma_fence_find", 1634, v16, v11);
  }
  return v11;
}
