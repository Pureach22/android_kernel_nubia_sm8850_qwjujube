__int64 __fastcall kgsl_iopgtbl_unmap_range(_QWORD *a1, __int64 a2, unsigned __int64 a3, unsigned __int64 a4)
{
  unsigned __int64 v4; // x8

  v4 = *(_QWORD *)(a2 + 40);
  if ( v4 > a3 && a4 + a3 <= v4 )
    return iopgtbl_unmap(a1, *(_QWORD *)(a2 + 24) + a3, a4);
  __break(0x800u);
  return 4294967262LL;
}
