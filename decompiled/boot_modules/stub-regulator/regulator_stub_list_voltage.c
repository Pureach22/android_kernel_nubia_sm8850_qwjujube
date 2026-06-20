__int64 __fastcall regulator_stub_list_voltage(__int64 a1, unsigned int a2)
{
  __int64 v3; // x8

  if ( a2 > 1 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 1144);
  if ( a2 )
    return *(unsigned int *)(v3 + 12);
  else
    return *(unsigned int *)(v3 + 8);
}
