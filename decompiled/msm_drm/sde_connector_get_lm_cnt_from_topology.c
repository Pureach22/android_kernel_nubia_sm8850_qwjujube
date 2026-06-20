__int64 __fastcall sde_connector_get_lm_cnt_from_topology(__int64 a1)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  if ( !a1 )
    return 4294967274LL;
  if ( *(_DWORD *)(a1 + 2736) != 16 )
    return 4294967274LL;
  v1 = *(__int64 (__fastcall **)(_QWORD))(a1 + 3216);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 2760);
  if ( *((_DWORD *)v1 - 1) != -1701015645 )
    __break(0x8228u);
  return v1(v2);
}
