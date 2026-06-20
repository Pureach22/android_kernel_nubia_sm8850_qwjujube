__int64 qdf_recovery_reason_update()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))update_recovery_reason_cb;
  if ( update_recovery_reason_cb )
  {
    if ( *((_DWORD *)update_recovery_reason_cb - 1) != 1514819199 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
