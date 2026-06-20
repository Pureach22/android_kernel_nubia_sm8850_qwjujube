__int64 __fastcall mlme_cm_osif_send_keys(__int64 a1, __int64 a2, char a3)
{
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x2

  if ( !glbl_cm_ops )
    return 0;
  v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(glbl_cm_ops + 64);
  if ( !v3 )
    return 0;
  v4 = a3 & 1;
  if ( *((_DWORD *)v3 - 1) != 1939102687 )
    __break(0x8228u);
  return v3(a1, a2, v4);
}
