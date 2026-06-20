__int64 __fastcall ttlm_tx_action_req_cb(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v3; // x21
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v1 = *(__int64 **)(a1 + 8);
  v3 = *v1;
  qdf_mutex_acquire(*v1 + 656);
  LODWORD(v1) = wlan_sm_dispatch(*(_QWORD *)(v3 + 720), 2u, 0x34u, (__int64)(v1 + 14), v4, v5, v6, v7, v8, v9, v10, v11);
  qdf_mutex_release(v3 + 656);
  _qdf_mem_free(*(_QWORD *)(a1 + 8));
  return (unsigned int)v1;
}
