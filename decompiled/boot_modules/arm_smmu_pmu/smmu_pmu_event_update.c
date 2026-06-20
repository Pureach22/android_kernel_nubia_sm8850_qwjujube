unsigned __int64 __fastcall smmu_pmu_event_update(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x25
  __int64 v8; // x24
  unsigned int *v9; // x0
  __int64 v10; // x8
  unsigned __int64 result; // x0
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v22; // x10

  v1 = *(_DWORD *)(a1 + 396);
  v3 = *(_QWORD *)(a1 + 152);
  v4 = (unsigned int)(8 * v1);
  v5 = (unsigned int)(4 * v1);
  v6 = (unsigned __int16)*(_QWORD *)(a1 + 224);
  v7 = *(_QWORD *)(a1 + 224) & 0xFF80LL;
  do
  {
    v8 = *(_QWORD *)(a1 + 488);
    if ( v7 )
    {
      v9 = (unsigned int *)(*(_QWORD *)(v3 + 344) + v6 + 1280);
    }
    else
    {
      v10 = *(_QWORD *)(v3 + 328);
      if ( *(_BYTE *)(v3 + 376) != 1 )
      {
        result = readq_relaxed(v10 + v4);
        goto LABEL_8;
      }
      v9 = (unsigned int *)(v10 + v5);
    }
    result = (unsigned int)readl_relaxed(v9);
LABEL_8:
    _X9 = (unsigned __int64 *)(a1 + 488);
    __asm { PRFM            #0x11, [X9] }
    while ( 1 )
    {
      v18 = __ldxr(_X9);
      if ( v18 != v8 )
        break;
      if ( !__stlxr(result, _X9) )
      {
        __dmb(0xBu);
        break;
      }
    }
  }
  while ( v18 != v8 );
  v19 = *(_QWORD *)(v3 + 368) & (result - v8);
  _X9 = (unsigned __int64 *)(a1 + 176);
  __asm { PRFM            #0x11, [X9] }
  do
    v22 = __ldxr(_X9);
  while ( __stxr(v22 + v19, _X9) );
  return result;
}
