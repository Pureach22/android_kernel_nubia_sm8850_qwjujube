__int64 __fastcall swr_remove_from_group(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  void (__fastcall *v4)(__int64, __int64); // x8

  if ( !a1 )
    return 4294967277LL;
  v3 = *(_QWORD *)(a1 + 32);
  if ( !v3 )
    return 4294967274LL;
  if ( !*(_BYTE *)(a1 + 992) )
    return 0;
  if ( *(unsigned __int8 *)(v3 + 8411) != (unsigned __int8)a2 )
    return 0;
  v4 = *(void (__fastcall **)(__int64, __int64))(v3 + 8480);
  if ( !v4 )
    return 0;
  if ( *((_DWORD *)v4 - 1) != -2098199502 )
    __break(0x8228u);
  v4(v3, a2);
  return 0;
}
