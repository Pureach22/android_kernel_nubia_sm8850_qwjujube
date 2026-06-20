__int64 __fastcall hif_is_driver_unloading(__int64 a1)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  v1 = *(__int64 (__fastcall **)(_QWORD))(a1 + 2496);
  if ( !v1 )
    return 0;
  v2 = *(_QWORD *)(a1 + 2464);
  if ( *((_DWORD *)v1 - 1) != -2091637267 )
    __break(0x8228u);
  return v1(v2) & 1;
}
