__int64 osif_cm_roam_cmpl_cb()
{
  __int64 (__fastcall *v0)(_QWORD); // x8

  if ( !osif_cm_legacy_ops )
    return 0;
  v0 = *(__int64 (__fastcall **)(_QWORD))(osif_cm_legacy_ops + 32);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != 2029277559 )
    __break(0x8228u);
  return v0(0);
}
