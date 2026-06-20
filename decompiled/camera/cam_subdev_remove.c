__int64 __fastcall cam_subdev_remove(void **a1)
{
  _QWORD *v2; // x0

  if ( !a1 )
    return 4294967274LL;
  cam_unregister_subdev((__int64)a1);
  cam_node_deinit(a1[53]);
  v2 = a1[53];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  memset(a1, 0, 0x1D8u);
  return 0;
}
