__int64 __fastcall hdd_lookup_ifaddr(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x19
  const char *v11; // x2

  if ( !a1 )
  {
    v11 = "%s: adapter is null";
LABEL_8:
    qdf_trace_msg(0x33u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_lookup_ifaddr");
    return 0;
  }
  v9 = *(_QWORD *)(a1 + 32);
  v10 = *(_QWORD *)(v9 + 968);
  if ( !v10 )
  {
    v11 = "%s: Failed to get in_device";
    goto LABEL_8;
  }
  do
    v10 = *(_QWORD *)(v10 + 16);
  while ( v10 && strcmp((const char *)(v9 + 296), (const char *)(v10 + 76)) );
  return v10;
}
