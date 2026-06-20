__int64 osif_cm_connect_active_notify()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  if ( osif_cm_legacy_ops )
  {
    v0 = *(__int64 (**)(void))osif_cm_legacy_ops;
    if ( *(_QWORD *)osif_cm_legacy_ops )
    {
      if ( *((_DWORD *)v0 - 1) != -1560483463 )
        __break(0x8228u);
      return v0();
    }
  }
  return result;
}
