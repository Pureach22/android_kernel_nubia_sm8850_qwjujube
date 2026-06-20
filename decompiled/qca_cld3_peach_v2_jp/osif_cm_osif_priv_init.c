__int64 __fastcall osif_cm_osif_priv_init(__int64 a1)
{
  __int64 v2; // x8

  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    return 0;
  v2 = *(_QWORD *)(a1 + 608);
  if ( v2 )
  {
    *(_DWORD *)(v2 + 32) = 0;
    *(_QWORD *)(v2 + 40) = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: Invalid vdev osif priv", "osif_cm_osif_priv_init");
    return 4;
  }
}
