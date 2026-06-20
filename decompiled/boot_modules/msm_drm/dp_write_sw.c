void __fastcall dp_write_sw(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  if ( *(_QWORD *)(a2 + 8) )
    *(_DWORD *)(*(_QWORD *)(a2 + 8) + a3) = a4;
}
