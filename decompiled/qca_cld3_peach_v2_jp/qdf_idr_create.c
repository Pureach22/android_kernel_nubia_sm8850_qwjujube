__int64 __fastcall qdf_idr_create(__int64 a1)
{
  if ( !a1 )
    return 4;
  *(_DWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = 0x1000000400000000LL;
  *(_QWORD *)(a1 + 24) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  return 0;
}
