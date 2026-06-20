__int64 __fastcall cam_packet_util_get_unique_tbl(_QWORD *a1, __int64 *a2)
{
  _QWORD *v4; // x21
  __int64 v5; // x8

  if ( mem_trace_en != 1 )
  {
    v4 = (_QWORD *)_kvmalloc_node_noprof(1600, 0, 3520, 0xFFFFFFFFLL);
    if ( v4 )
      goto LABEL_3;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_get_unique_tbl",
      421,
      "Failed at allocating unique src tbl");
    return 4294967284LL;
  }
  v4 = (_QWORD *)cam_mem_trace_alloc(1600, 0xCC0u, 0, "cam_packet_util_get_unique_tbl", 0x1A3u);
  if ( !v4 )
    goto LABEL_7;
LABEL_3:
  if ( mem_trace_en == 1 )
  {
    v5 = cam_mem_trace_alloc(1600, 0xCC0u, 0, "cam_packet_util_get_unique_tbl", 0x1AAu);
    if ( v5 )
    {
LABEL_5:
      *a1 = v4;
      *a2 = v5;
      return 0;
    }
  }
  else
  {
    v5 = _kvmalloc_node_noprof(1600, 0, 3520, 0xFFFFFFFFLL);
    if ( v5 )
      goto LABEL_5;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_packet_util_get_unique_tbl",
    428,
    "Failed at allocating unique dst tbl");
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v4, 0);
  else
    kvfree(v4);
  return 4294967284LL;
}
