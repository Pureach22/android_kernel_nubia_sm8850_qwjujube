__int64 __fastcall sde_dbg_debugfs_open(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // t1
  unsigned int v11; // w8

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    *(_DWORD *)(a2 + 12) &= 0xFFFFFFE3;
    *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 696);
    mutex_lock(&unk_2942D0);
    dword_2945D0 = 0;
    _X9 = (unsigned int *)(sde_dbg_base + 786444);
    __asm { PRFM            #0x11, [X9] }
    do
      v11 = __ldxr(_X9);
    while ( __stlxr(v11, _X9) );
    __dmb(0xBu);
    v5 = sde_dbg_base;
    *(_DWORD *)(sde_dbg_base + 786432) = v11 + 1;
    *(_DWORD *)(v5 + 786436) = v11 + 8193;
    mutex_unlock(&unk_2942D0);
    return 0;
  }
  return result;
}
