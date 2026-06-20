__int64 __fastcall sme_register_tx_queue_cb(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a1 + 14480) = a2;
    qdf_mutex_release(a1 + 12848);
    qdf_trace_msg(0x34u, 8u, "%s: Tx queue callback set", v5, v6, v7, v8, v9, v10, v11, v12, "sme_register_tx_queue_cb");
    return 0;
  }
  return result;
}
