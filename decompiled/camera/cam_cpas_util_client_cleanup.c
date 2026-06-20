__int64 __fastcall cam_cpas_util_client_cleanup(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x22
  __int64 v4; // x8
  _QWORD *v5; // x0

  v2 = 0;
  v3 = *(_QWORD *)(a1 + 3680) + 320LL;
  do
  {
    v4 = *(_QWORD *)(v3 + 8 * v2);
    if ( v4 && *(_BYTE *)(v4 + 168) == 1 )
      cam_cpas_hw_unregister_client(a1, (unsigned int)v2);
    v5 = *(_QWORD **)(v3 + 8 * v2);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
    *(_QWORD *)(v3 + 8 * v2++) = 0;
  }
  while ( v2 != 43 );
  return 0;
}
