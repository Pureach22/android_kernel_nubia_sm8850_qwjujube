__int64 __fastcall qdss_enable_debug_inface_show(__int64 a1, __int64 a2)
{
  const char *v2; // x3

  if ( *(_BYTE *)(*(_QWORD *)(a1 + 176) + 280LL) )
    v2 = "Enabled";
  else
    v2 = "Disabled";
  return (int)scnprintf(a2, 4096, "%s\n", v2);
}
