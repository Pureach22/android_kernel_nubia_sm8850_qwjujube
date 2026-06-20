__int64 __fastcall wlan_cm_host_roam_start(__int64 a1)
{
  __int64 v1; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 8);
    if ( v1 )
      _qdf_mem_free(v1);
  }
  return 0;
}
