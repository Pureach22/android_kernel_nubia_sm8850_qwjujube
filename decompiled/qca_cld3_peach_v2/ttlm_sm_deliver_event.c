__int64 __fastcall ttlm_sm_deliver_event(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  qdf_mutex_acquire(a1 + 656);
  LODWORD(a4) = wlan_sm_dispatch(*(_QWORD *)(a1 + 720), a2, a3, a4, v8, v9, v10, v11, v12, v13, v14, v15);
  qdf_mutex_release(a1 + 656);
  return (unsigned int)a4;
}
