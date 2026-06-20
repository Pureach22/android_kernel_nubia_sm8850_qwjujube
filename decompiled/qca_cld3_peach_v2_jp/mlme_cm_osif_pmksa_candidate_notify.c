__int64 __fastcall mlme_cm_osif_pmksa_candidate_notify(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 (__fastcall *v4)(__int64, __int64, __int64, __int64); // x8
  __int64 v5; // x3

  if ( !glbl_cm_ops )
    return 0;
  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(glbl_cm_ops + 56);
  if ( !v4 )
    return 0;
  v5 = a4 & 1;
  if ( *((_DWORD *)v4 - 1) != -1705732016 )
    __break(0x8228u);
  return v4(a1, a2, a3, v5);
}
