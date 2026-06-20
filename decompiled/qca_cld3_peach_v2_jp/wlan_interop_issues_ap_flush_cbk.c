__int64 __fastcall wlan_interop_issues_ap_flush_cbk(__int64 a1)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a1 + 8);
  if ( v2 )
  {
    _qdf_mem_free(v2);
    *(_QWORD *)(a1 + 8) = 0;
  }
  return 0;
}
