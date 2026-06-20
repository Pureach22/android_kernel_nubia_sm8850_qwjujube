void *__fastcall cm_free_connect_req_mem(_QWORD *a1)
{
  __int64 v2; // x0
  void *v3; // x20

  v2 = a1[125];
  if ( v2 )
    scm_purge_scan_results(v2);
  cm_free_connect_req_param(a1 + 1);
  v3 = (void *)a1[130];
  if ( v3 )
  {
    cm_free_connect_rsp_ies(a1[130]);
    qdf_mem_set(v3, 0x150u, 0);
    _qdf_mem_free((__int64)v3);
  }
  return qdf_mem_set(a1, 0x9D8u, 0);
}
