__int64 __fastcall gunyah_trace_open(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  unsigned int v18; // w9

  v3 = *(_QWORD *)(a1 + 696);
  __asm { HVC             #0 }
  printk(&unk_7692, 3321921599LL, 0, 1);
  v9 = _kmalloc_cache_noprof(strim, 3264, 16);
  if ( !v9 )
    return 4294967284LL;
  v10 = _kmalloc_noprof(12LL * *(unsigned __int16 *)(v3 + 60), 3264);
  *(_QWORD *)(v9 + 8) = v10;
  if ( !v10 )
  {
    kfree(v9);
    return 4294967284LL;
  }
  if ( *(_WORD *)(v3 + 60) )
  {
    v11 = 0;
    v12 = 0;
    v13 = 8;
    do
    {
      ++v12;
      *(_DWORD *)(*(_QWORD *)(v9 + 8) + v11 + 8) = 0;
      v14 = *(_QWORD *)(*(_QWORD *)(v3 + 104) + v13);
      v13 += 32;
      *(_DWORD *)(*(_QWORD *)(v9 + 8) + v11 + 4) = *(_DWORD *)(v14 + 48);
      *(_DWORD *)(*(_QWORD *)(v9 + 8) + v11) = *(_DWORD *)(v14 + 40);
      v11 += 12;
    }
    while ( v12 < *(unsigned __int16 *)(v3 + 60) );
  }
  *(_QWORD *)(a2 + 32) = v9;
  _X8 = &dword_7E08;
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr((unsigned int *)&dword_7E08);
  while ( __stxr(v18 + 1, (unsigned int *)&dword_7E08) );
  return 0;
}
