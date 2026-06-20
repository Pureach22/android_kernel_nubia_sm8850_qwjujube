__int64 __fastcall kgsl_contiguous_free(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned __int64 v9; // x10

  if ( *(_QWORD *)(result + 8) && (*(_DWORD *)(result + 48) & 8) == 0 )
  {
    v1 = *(_QWORD *)(result + 40);
    _X9 = &qword_3A8C8;
    __asm { PRFM            #0x11, [X9] }
    do
      v9 = __ldxr((unsigned __int64 *)&qword_3A8C8);
    while ( __stxr(v9 - v1, (unsigned __int64 *)&qword_3A8C8) );
    v2 = result;
    dma_free_attrs(
      *(_QWORD *)(result + 80),
      *(_QWORD *)(result + 40),
      *(_QWORD *)(result + 8),
      *(_QWORD *)(result + 32),
      *(_QWORD *)(result + 88));
    sg_free_table(*(_QWORD *)(v2 + 56));
    result = kfree(*(_QWORD *)(v2 + 56));
    *(_QWORD *)(v2 + 56) = 0;
  }
  return result;
}
