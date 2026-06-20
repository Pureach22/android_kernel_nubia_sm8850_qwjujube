__int64 __fastcall twm_enable_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  const char *v5; // x4

  v3 = *(_QWORD *)(a1 + 152);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_BYTE *)(v3 + 4518) )
      v5 = "ENABLED";
    else
      v5 = "DISABLED";
    _drm_dev_dbg(0, 0, 0, "TWM: %s\n", v5);
  }
  return (int)scnprintf(a3, 4096, "%d\n", *(unsigned __int8 *)(v3 + 4518));
}
