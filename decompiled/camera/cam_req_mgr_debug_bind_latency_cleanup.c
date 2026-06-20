void cam_req_mgr_debug_bind_latency_cleanup()
{
  _QWORD *v0; // x9
  _QWORD *v1; // x8
  _QWORD *v2; // x23
  __int64 v3; // x0
  _QWORD *v4; // x19

  v0 = cam_bind_latency_list;
  if ( cam_bind_latency_list != (_UNKNOWN *)&cam_bind_latency_list )
  {
    do
    {
      v2 = (_QWORD *)*v0;
      v1 = (_QWORD *)v0[1];
      if ( (_QWORD *)*v1 == v0 && (_QWORD *)v2[1] == v0 )
      {
        v2[1] = v1;
        *v1 = v2;
      }
      else
      {
        _list_del_entry_valid_or_report(v0);
      }
      v3 = *(v0 - 2);
      v4 = v0 - 2;
      *v0 = 0xDEAD000000000100LL;
      v0[1] = 0xDEAD000000000122LL;
      kfree(v3);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v4, 0);
      else
        kvfree(v4);
      v0 = v2;
    }
    while ( v2 != &cam_bind_latency_list );
  }
}
