__int64 __fastcall hdd_debugfs_mws_coex_info_cb(
        const void *a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x0
  __int64 v14; // x19
  unsigned int v15; // w21
  void *v16; // x0
  const char *v18; // x2

  if ( !a1 )
  {
    v18 = "%s: data is null";
    return qdf_trace_msg(0x33u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_debugfs_mws_coex_info_cb");
  }
  v13 = osif_request_get(a2);
  if ( !v13 )
  {
    v18 = "%s: obsolete request";
    return qdf_trace_msg(0x33u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_debugfs_mws_coex_info_cb");
  }
  v14 = v13;
  if ( (unsigned int)(a3 - 1) <= 4 )
  {
    v15 = dword_A2E638[a3 - 1];
    v16 = (void *)osif_request_priv(v13);
    qdf_mem_copy(v16, a1, v15);
  }
  osif_request_complete(v14);
  return osif_request_put(v14);
}
