__int64 __fastcall sme_deregister_tx_queue_cb(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a1 + 14408) = 0;
    qdf_mutex_release(a1 + 12776);
    qdf_trace_msg(0x34u, 8u, "%s: Tx queue callback set", v3, v4, v5, v6, v7, v8, v9, v10, "sme_register_tx_queue_cb");
    return 0;
  }
  return result;
}
