_QWORD *__fastcall cam_icp_mgr_free_hw_devs(__int64 a1)
{
  unsigned int v2; // w21
  _QWORD *v3; // x0
  _QWORD *v4; // x0
  _QWORD *result; // x0

  if ( *(_DWORD *)(a1 + 64) )
  {
    v2 = 0;
    do
    {
      v3 = *(_QWORD **)(*(_QWORD *)(a1 + 56) + 584LL * (int)v2 + 16);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v3, 0);
      else
        kvfree(v3);
      ++v2;
    }
    while ( v2 < *(_DWORD *)(a1 + 64) );
  }
  v4 = *(_QWORD **)(a1 + 56);
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free(v4, 0);
  else
    result = (_QWORD *)kvfree(v4);
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  return result;
}
