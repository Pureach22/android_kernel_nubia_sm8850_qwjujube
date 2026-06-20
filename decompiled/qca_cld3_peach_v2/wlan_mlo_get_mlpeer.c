__int64 __fastcall wlan_mlo_get_mlpeer(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  int v15; // w8
  __int64 mlpeer; // x20

  if ( a2 )
  {
    v12 = *a2;
    v13 = a2[1];
    v14 = a2[2];
    v15 = a2[5];
  }
  else
  {
    v14 = 0;
    v12 = 0;
    v13 = 0;
    v15 = 0;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: MLD ID %d ML Peer search mac %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_mlo_get_mlpeer",
    *(unsigned __int8 *)(a1 + 16),
    v12,
    v13,
    v14,
    v15);
  qdf_mutex_acquire(a1 + 1584);
  mlpeer = mlo_get_mlpeer(a1, (__int64)a2);
  qdf_mutex_release(a1 + 1584);
  return mlpeer;
}
