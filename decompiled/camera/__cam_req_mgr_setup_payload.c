__int64 __fastcall _cam_req_mgr_setup_payload(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w8
  __int64 v4; // x11
  __int64 v5; // x12

  if ( mem_trace_en == 1 )
  {
    v2 = cam_mem_trace_alloc(80LL * *(unsigned int *)(a1 + 304), 3264, 0, "__cam_req_mgr_setup_payload", 136);
    if ( !v2 )
      return 4294967284LL;
  }
  else
  {
    v2 = _kvmalloc_node_noprof(80LL * *(unsigned int *)(a1 + 304), 0, 3520, 0xFFFFFFFFLL);
    if ( !v2 )
      return 4294967284LL;
  }
  if ( *(_DWORD *)(a1 + 304) )
  {
    v3 = 0;
    do
    {
      v4 = v2 + 80LL * (int)v3;
      v5 = *(_QWORD *)(a1 + 296) + 72LL * (int)v3++;
      *(_QWORD *)(v5 + 8) = v4;
    }
    while ( v3 < *(_DWORD *)(a1 + 304) );
  }
  return 0;
}
