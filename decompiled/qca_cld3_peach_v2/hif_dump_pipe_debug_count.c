__int64 __fastcall hif_dump_pipe_debug_count(__int64 result)
{
  unsigned __int64 v1; // x8
  __int64 v2; // x19
  unsigned __int64 v3; // x22
  _DWORD *v4; // x23
  int v5; // w7

  if ( !result )
    return qdf_trace_msg(61, 2, "%s: hif_state is NULL", "hif_dump_pipe_debug_count");
  v1 = *(unsigned int *)(result + 656);
  v2 = result;
  if ( (_DWORD)v1 )
  {
    v3 = 0;
    v4 = (_DWORD *)(result + 27500);
    do
    {
      if ( v3 == 13 )
      {
        __break(0x5512u);
        return hif_post_recv_buffers_for_pipe(result);
      }
      v5 = *(v4 - 1);
      if ( !*((_QWORD *)v4 - 1) )
      {
        if ( !*v4 )
          goto LABEL_5;
        v5 = 0;
      }
      result = qdf_trace_msg(
                 61,
                 2,
                 "%s: pipe_id = %d, recv_bufs_needed = %d, nbuf_alloc_err_count = %u, nbuf_dma_err_count = %u, nbuf_ce_en"
                 "queue_err_count = %u",
                 "hif_dump_pipe_debug_count",
                 *((unsigned __int8 *)v4 - 76),
                 *(v4 - 15),
                 *(v4 - 2),
                 v5,
                 *v4);
      v1 = *(unsigned int *)(v2 + 656);
LABEL_5:
      ++v3;
      v4 += 34;
    }
    while ( v3 < v1 );
  }
  return result;
}
