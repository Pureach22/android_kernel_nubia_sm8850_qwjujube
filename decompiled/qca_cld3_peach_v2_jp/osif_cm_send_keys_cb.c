__int64 __fastcall osif_cm_send_keys_cb(__int64 a1, __int64 a2, char a3)
{
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x2

  if ( !osif_cm_legacy_ops )
    return 16;
  v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(osif_cm_legacy_ops + 48);
  if ( !v3 )
    return 16;
  v4 = a3 & 1;
  if ( *((_DWORD *)v3 - 1) != 1939102687 )
    __break(0x8228u);
  return v3(a1, a2, v4);
}
