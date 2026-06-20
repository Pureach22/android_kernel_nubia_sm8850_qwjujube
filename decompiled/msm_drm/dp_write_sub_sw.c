void __fastcall dp_write_sub_sw(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x8

  v4 = *(_QWORD *)(a2 + 8);
  if ( v4 )
    *(_DWORD *)(v4 + a3) = a4;
}
