__int64 __fastcall dp_read_sub_sw(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a2 + 8);
  if ( v3 )
    return *(unsigned int *)(v3 + a3);
  else
    return 0;
}
