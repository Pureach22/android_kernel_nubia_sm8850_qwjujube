__int64 __fastcall hif_config_ce_pktlog(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x8
  unsigned int *v3; // x9
  unsigned int v4; // w19
  int v6; // w0
  int v7; // w19
  int v8; // w4
  unsigned int v9; // w19

  if ( !a1 )
    goto LABEL_14;
  if ( (*(_BYTE *)(a1 + 3989) & 1) != 0 )
    return 0;
  v2 = *(unsigned int *)(a1 + 30712);
  if ( (int)v2 < 1 )
    goto LABEL_14;
  v3 = (unsigned int *)(*(_QWORD *)(a1 + 30704) + 8LL);
  while ( *(v3 - 2) != 1536 )
  {
    --v2;
    v3 += 3;
    if ( !v2 )
      goto LABEL_14;
  }
  v4 = *v3;
  if ( (*v3 & 0x80000000) != 0 )
  {
LABEL_14:
    v8 = 16;
    goto LABEL_15;
  }
  if ( v4 >= 0xD )
  {
    __break(0x5512u);
    return ((__int64 (*)(void))hif_completion_thread_startup_by_ceid)();
  }
  else
  {
    if ( (unsigned int)hif_config_ce_by_id(a1, v4) == 8 )
      return 0;
    hif_config_irq_by_ceid(a1, v4);
    v6 = hif_completion_thread_startup_by_ceid(a1, v4);
    if ( v6 )
    {
      v7 = v6;
      qdf_trace_msg(61, 2, "%s: Failed to start hif thread", "hif_config_ce_pktlog");
      v8 = v7;
LABEL_15:
      qdf_trace_msg(61, 8, "%s: X, ret = %d", "hif_config_ce_pktlog", v8);
      return 1;
    }
    result = hif_post_recv_buffers_for_pipe((__int64 *)(a1 + 136LL * v4 + 27416));
    if ( (_DWORD)result )
    {
      v9 = result;
      qdf_trace_msg(61, 2, "%s: Failed to post buffers", "hif_config_ce_pktlog");
      return v9;
    }
    else
    {
      *(_BYTE *)(a1 + 3989) = 1;
    }
  }
  return result;
}
