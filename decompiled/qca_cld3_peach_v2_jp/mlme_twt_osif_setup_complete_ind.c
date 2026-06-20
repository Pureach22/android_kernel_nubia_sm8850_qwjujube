__int64 __fastcall mlme_twt_osif_setup_complete_ind(__int64 a1, __int64 a2, char a3)
{
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x2

  if ( !glbl_twt_ops )
    return 0;
  v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(glbl_twt_ops + 24);
  if ( !v3 )
    return 0;
  v4 = a3 & 1;
  if ( *((_DWORD *)v3 - 1) != 845393520 )
    __break(0x8228u);
  return v3(a1, a2, v4);
}
