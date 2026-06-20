__int64 cds_scan_flush_on_recovery()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))cds_scan_flush_recovery_callback;
  if ( cds_scan_flush_recovery_callback )
  {
    if ( *((_DWORD *)cds_scan_flush_recovery_callback - 1) != -440107680 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
