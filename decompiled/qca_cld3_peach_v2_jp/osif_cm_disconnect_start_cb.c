__int64 __fastcall osif_cm_disconnect_start_cb(__int64 a1, int a2)
{
  __int64 (__fastcall *v2)(__int64, __int64, __int64); // x8

  if ( (a2 & 0xFFFFFFFD) == 0x10 )
    return 0;
  if ( !osif_cm_legacy_ops )
    return 0;
  v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(osif_cm_legacy_ops + 24);
  if ( !v2 )
    return 0;
  if ( *((_DWORD *)v2 - 1) != 1372361862 )
    __break(0x8228u);
  return v2(a1, 4, 1);
}
