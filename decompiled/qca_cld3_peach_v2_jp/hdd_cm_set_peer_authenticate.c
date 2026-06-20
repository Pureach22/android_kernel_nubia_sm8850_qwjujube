__int64 __fastcall hdd_cm_set_peer_authenticate(
        __int64 a1,
        unsigned __int8 *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  const char *v18; // x8
  int v19; // w22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  if ( a2 )
  {
    v14 = *a2;
    v15 = a2[1];
    v16 = a2[2];
    v17 = a2[5];
  }
  else
  {
    v16 = 0;
    v14 = 0;
    v15 = 0;
    v17 = 0;
  }
  v18 = "AUTHENTICATED";
  if ( (a3 & 1) != 0 )
  {
    v18 = "CONNECTED";
    v19 = 2;
  }
  else
  {
    v19 = 3;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: sta: %02x:%02x:%02x:**:**:%02xChanging TL state to %s",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "hdd_cm_set_peer_authenticate",
    v14,
    v15,
    v16,
    v17,
    v18);
  hdd_change_peer_state((unsigned __int8 *)a1, (__int64)a2, v19, v20, v21, v22, v23, v24, v25, v26, v27);
  hdd_conn_set_authenticated(a1, (a3 & 1) == 0, v28, v29, v30, v31, v32, v33, v34, v35);
  return hdd_objmgr_set_peer_mlme_auth_state(*(_QWORD *)(a1 + 32), (a3 & 1) == 0);
}
