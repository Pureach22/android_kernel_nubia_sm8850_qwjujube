__int64 __fastcall kgsl_paged_map_kernel(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w10
  __int64 v4; // x3
  __int64 v5; // x20
  __int64 v6; // x9
  __int64 v7; // x0
  __int64 v8; // x9
  unsigned int v9; // w20
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8

  mutex_lock(&kernel_map_global_lock);
  if ( *(_QWORD *)(a1 + 8) )
    goto LABEL_21;
  v2 = *(_QWORD *)(a1 + 96);
  if ( v2 )
  {
    v3 = (*(_DWORD *)(a1 + 72) >> 26) & 3;
    if ( v3 == 3 )
    {
      if ( arm64_use_ng_mappings )
        v4 = 0x68000000000F03LL;
      else
        v4 = 0x68000000000703LL;
    }
    else if ( v3 == 2 )
    {
      if ( arm64_use_ng_mappings )
        v4 = 0x68000000000F03LL;
      else
        v4 = 0x68000000000703LL;
      if ( (kgsl_paged_map_kernel___already_done & 1) == 0 )
      {
        kgsl_paged_map_kernel___already_done = 1;
        v5 = v4;
        _warn_printk("WRITETHROUGH is deprecated for arm64");
        __break(0x800u);
        v2 = *(_QWORD *)(a1 + 96);
        v4 = v5;
      }
    }
    else
    {
      v6 = 8;
      if ( arm64_use_ng_mappings )
        v6 = 2056;
      v4 = v6 + 0x68000000000703LL;
    }
    v7 = vmap(v2, *(unsigned int *)(a1 + 104), 1, v4);
    *(_QWORD *)(a1 + 8) = v7;
    if ( !v7 )
    {
      v9 = -12;
      goto LABEL_22;
    }
    v8 = *(_QWORD *)(a1 + 40);
    _X10 = &qword_3A8A8;
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v17 = __ldxr((unsigned __int64 *)&qword_3A8A8);
      v18 = v17 + v8;
    }
    while ( __stlxr(v18, (unsigned __int64 *)&qword_3A8A8) );
    __dmb(0xBu);
    if ( v18 > qword_3A8B0 )
      qword_3A8B0 = v18;
  }
  if ( *(_QWORD *)(a1 + 8) )
  {
LABEL_21:
    v9 = 0;
    ++*(_DWORD *)(a1 + 16);
  }
  else
  {
    v9 = 0;
  }
LABEL_22:
  mutex_unlock(&kernel_map_global_lock);
  return v9;
}
