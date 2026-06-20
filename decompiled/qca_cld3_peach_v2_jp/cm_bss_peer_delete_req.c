__int64 __fastcall cm_bss_peer_delete_req(
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
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x7
  int v14; // w8

  if ( a2 )
  {
    v11 = *a2;
    v12 = a2[1];
    v13 = a2[2];
    v14 = a2[5];
  }
  else
  {
    v13 = 0;
    v11 = 0;
    v12 = 0;
    v14 = 0;
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d: delete peer%02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "cm_bss_peer_delete_req",
    *(unsigned __int8 *)(a1 + 104),
    v11,
    v12,
    v13,
    v14);
  return mlme_cm_bss_peer_delete_req(a1);
}
