__int64 __fastcall mlme_cm_bss_peer_create_req(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 (__fastcall *v4)(__int64, __int64, __int64, __int64); // x8
  __int64 v5; // x3

  if ( !glbl_ops )
    return 0;
  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(glbl_ops + 144);
  if ( !v4 )
    return 0;
  v5 = a4 & 1;
  if ( *((_DWORD *)v4 - 1) != -607651358 )
    __break(0x8228u);
  return v4(a1, a2, a3, v5);
}
