__int64 __fastcall osif_cm_osif_priv_deinit(__int64 a1)
{
  int v1; // w9
  __int64 result; // x0

  v1 = *(_DWORD *)(a1 + 16);
  result = 0;
  if ( (v1 & 0xFFFFFFFD) == 0 && !*(_QWORD *)(a1 + 608) )
  {
    qdf_trace_msg(72, 2, "%s: Invalid vdev osif priv", "osif_cm_osif_priv_deinit");
    return 4;
  }
  return result;
}
