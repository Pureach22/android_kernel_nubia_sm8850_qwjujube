__int64 __fastcall hif_drain_tasklets(__int64 a1)
{
  int v2; // w22
  int v3; // w4

  if ( !*(_DWORD *)(a1 + 672) )
    return 0;
  v2 = 20;
  while ( 1 )
  {
    qdf_trace_msg(61, 5, "%s: Waiting for CE to finish access", "hif_drain_tasklets");
    msleep(10);
    v3 = *(_DWORD *)(a1 + 672);
    if ( !v3 )
      break;
    if ( !--v2 )
    {
      qdf_trace_msg(61, 2, "%s: CE still not done with access: %d", "hif_drain_tasklets", v3);
      return 4294967282LL;
    }
  }
  return 0;
}
