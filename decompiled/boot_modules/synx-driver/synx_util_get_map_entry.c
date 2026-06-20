__int64 __fastcall synx_util_get_map_entry(int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v7; // w20
  __int64 v8; // x8
  unsigned int v9; // w9
  __int64 v10; // x20
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v14; // x8
  unsigned int v15; // w9
  __int64 v16; // x9
  __int64 v17; // x8
  bool v18; // zf
  __int64 v19; // x8
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned int v29; // w9
  unsigned int v31; // w9

  if ( a1 )
  {
    v7 = 1640531527 * a1;
    v8 = *(_QWORD *)(synx_dev + 152);
    if ( (a1 & 0x100000) != 0 )
    {
      raw_spin_lock_bh(v8 + 10256);
      v15 = v7 >> 22;
      v10 = -2;
      v16 = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 8LL * v15 + 10264);
      v17 = v16 - 56;
      if ( v16 )
        v18 = v16 == 56;
      else
        v18 = 1;
      if ( !v18 )
      {
        while ( *(_DWORD *)(v17 + 16) != a1 )
        {
          v19 = *(_QWORD *)(v17 + 56);
          if ( v19 )
          {
            v17 = v19 - 56;
            if ( v17 )
              continue;
          }
          goto LABEL_29;
        }
        _X0 = (unsigned int *)(v17 + 8);
        __asm { PRFM            #0x11, [X0] }
        do
          v31 = __ldxr(_X0);
        while ( __stxr(v31 + 1, _X0) );
        if ( v31 )
        {
          v10 = v17;
          if ( (((v31 + 1) | v31) & 0x80000000) != 0 )
            refcount_warn_saturate(_X0, 1);
        }
        else
        {
          v10 = v17;
          refcount_warn_saturate(_X0, 2);
        }
      }
LABEL_29:
      v21 = synx_dev;
      v22 = 10256;
    }
    else
    {
      raw_spin_lock_bh(v8 + 18456);
      v9 = HIBYTE(v7);
      v10 = -2;
      v11 = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 8LL * v9 + 18464);
      v12 = v11 - 56;
      if ( v11 )
        _ZF = v11 == 56;
      else
        _ZF = 1;
      if ( !_ZF )
      {
        while ( *(_DWORD *)(v12 + 16) != a1 )
        {
          v14 = *(_QWORD *)(v12 + 56);
          if ( v14 )
          {
            v12 = v14 - 56;
            if ( v12 )
              continue;
          }
          goto LABEL_25;
        }
        _X0 = (unsigned int *)(v12 + 8);
        __asm { PRFM            #0x11, [X0] }
        do
          v29 = __ldxr(_X0);
        while ( __stxr(v29 + 1, _X0) );
        if ( v29 )
        {
          v10 = v12;
          if ( (((v29 + 1) | v29) & 0x80000000) != 0 )
            refcount_warn_saturate(_X0, 1);
        }
        else
        {
          v10 = v12;
          refcount_warn_saturate(_X0, 2);
        }
      }
LABEL_25:
      v21 = synx_dev;
      v22 = 18456;
    }
    raw_spin_unlock_bh(*(_QWORD *)(v21 + 152) + v22);
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_27FE8, &unk_29207, "synx_util_get_map_entry", 1073, a5, a6);
    return -22;
  }
  return v10;
}
