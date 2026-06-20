__int64 __fastcall osif_cm_roam_start_cb(__int64 a1)
{
  __int64 (__fastcall *v1)(__int64, __int64, __int64); // x8

  if ( !osif_cm_legacy_ops )
    return 0;
  v1 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(osif_cm_legacy_ops + 24);
  if ( !v1 )
    return 0;
  if ( *((_DWORD *)v1 - 1) != 1372361862 )
    __break(0x8228u);
  return v1(a1, 1, 1);
}
