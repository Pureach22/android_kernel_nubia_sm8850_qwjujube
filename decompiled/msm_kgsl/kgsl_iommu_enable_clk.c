__int64 __fastcall kgsl_iommu_enable_clk(__int64 a1)
{
  unsigned __int64 v2; // x0
  __int64 v3; // x20
  unsigned int v4; // w8
  unsigned int v11; // w10
  unsigned int v12; // w20
  __int64 v13; // x21
  __int64 result; // x0
  unsigned int v17; // w9

  v2 = *(_QWORD *)(a1 + 976);
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL && (unsigned int)regulator_enable() )
    __break(0x800u);
  v3 = *(_QWORD *)(a1 + 952);
  if ( (*(_WORD *)(v3 + 504) & 7) == 0 && (_pm_runtime_resume(v3 + 16, 4) & 0x80000000) != 0 )
  {
    v4 = *(_DWORD *)(v3 + 496);
    do
    {
      if ( !v4 )
        break;
      _X12 = (unsigned int *)(v3 + 496);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v11 = __ldxr(_X12);
        if ( v11 != v4 )
          break;
        if ( !__stlxr(v4 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v11 == v4;
      v4 = v11;
    }
    while ( !_ZF );
    __break(0x800u);
  }
  v12 = *(_DWORD *)(a1 + 936);
  v13 = *(_QWORD *)(a1 + 928);
  result = clk_bulk_prepare(v12, v13);
  if ( (_DWORD)result )
    goto LABEL_20;
  result = clk_bulk_enable(v12, v13);
  if ( (_DWORD)result )
  {
    result = clk_bulk_unprepare(v12, v13);
LABEL_20:
    __break(0x800u);
  }
  _X8 = (unsigned int *)(a1 + 920);
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stxr(v17 + 1, _X8) );
  return result;
}
