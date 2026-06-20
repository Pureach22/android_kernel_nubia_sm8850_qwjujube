__int64 __fastcall lim_clean_up_disassoc_deauth_req(__int64 result, const void *a2, char a3)
{
  const void *v3; // x22
  __int64 v5; // x19
  unsigned __int8 *v7; // x22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w20

  v3 = *(const void **)(result + 12392);
  v5 = result;
  if ( !v3 || (result = qdf_mem_cmp(a2, v3, 6u), (_DWORD)result) )
  {
LABEL_5:
    v7 = *(unsigned __int8 **)(v5 + 12400);
    if ( !v7 )
      return result;
    goto LABEL_6;
  }
  if ( (a3 & 1) != 0 )
  {
    result = lim_send_disassoc_cnf(v5);
    goto LABEL_5;
  }
  if ( (tx_timer_running(v5 + 2400) & 1) != 0 )
    lim_deactivate_and_change_timer(v5, 16);
  result = _qdf_mem_free((__int64)v3);
  *(_QWORD *)(v5 + 12392) = 0;
  v7 = *(unsigned __int8 **)(v5 + 12400);
  if ( v7 )
  {
LABEL_6:
    result = qdf_mem_cmp(a2, v7, 6u);
    if ( !(_DWORD)result )
    {
      if ( (a3 & 1) != 0 )
      {
        v16 = v7[12];
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Deauth Ack timeout for vdev id %d",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "lim_process_deauth_ack_timeout",
          v7[12]);
        return lim_send_deauth_cnf(v5, v16);
      }
      else
      {
        if ( (tx_timer_running(v5 + 2664) & 1) != 0 )
          lim_deactivate_and_change_timer(v5, 17);
        result = _qdf_mem_free((__int64)v7);
        *(_QWORD *)(v5 + 12400) = 0;
      }
    }
  }
  return result;
}
