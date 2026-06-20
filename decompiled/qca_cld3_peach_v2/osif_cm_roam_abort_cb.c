__int64 __fastcall osif_cm_roam_abort_cb(__int64 a1)
{
  __int64 v1; // x8
  void (__fastcall *v2)(_QWORD); // x9
  __int64 v3; // x20
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x8

  v1 = osif_cm_legacy_ops;
  if ( !osif_cm_legacy_ops )
    return 0;
  v2 = *(void (__fastcall **)(_QWORD))(osif_cm_legacy_ops + 32);
  if ( v2 )
  {
    v3 = a1;
    if ( *((_DWORD *)v2 - 1) != 2029277559 )
      __break(0x8229u);
    v2(0);
    v1 = osif_cm_legacy_ops;
    a1 = v3;
    if ( !osif_cm_legacy_ops )
      return 0;
  }
  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v1 + 24);
  if ( !v4 )
    return 0;
  if ( *((_DWORD *)v4 - 1) != 1372361862 )
    __break(0x8228u);
  return v4(a1, 3, 1);
}
