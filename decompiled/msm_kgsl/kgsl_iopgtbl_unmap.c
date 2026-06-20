__int64 __fastcall kgsl_iopgtbl_unmap(__int64 a1, __int64 a2)
{
  int v2; // w10
  unsigned __int64 v3; // x11
  __int64 v4; // x1
  unsigned __int64 v5; // x2

  v2 = *(_DWORD *)(a2 + 48);
  v3 = *(_QWORD *)(a2 + 40);
  v4 = *(_QWORD *)(a2 + 24);
  if ( (v2 & 1) != 0 )
    v5 = (v3 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
  else
    v5 = v3;
  return iopgtbl_unmap(a1, v4, v5);
}
