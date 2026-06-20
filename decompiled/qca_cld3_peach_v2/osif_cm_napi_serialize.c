__int64 __fastcall osif_cm_napi_serialize(char a1)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  if ( !osif_cm_legacy_ops )
    return 0;
  v1 = *(__int64 (__fastcall **)(_QWORD))(osif_cm_legacy_ops + 32);
  if ( !v1 )
    return 0;
  v2 = a1 & 1;
  if ( *((_DWORD *)v1 - 1) != 2029277559 )
    __break(0x8228u);
  return v1(v2);
}
