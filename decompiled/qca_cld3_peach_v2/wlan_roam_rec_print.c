__int64 __fastcall wlan_roam_rec_print(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  const char *v21; // x3
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v39; // [xsp+0h] [xbp-10h]

  qdf_trace_msg(
    0x59u,
    8u,
    "index = %5d timestamp = 0x%016llx delta ms = %-12u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a2,
    *(_QWORD *)a1,
    a3);
  v20 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)v20 > 0x19 )
    v21 = "unknown";
  else
    v21 = off_AD85A0[v20];
  v39 = *(unsigned __int8 *)(a1 + 21);
  qdf_trace_msg(
    0x59u,
    8u,
    "info = %-24s vdev_id = %-3d mac addr = %02x:%02x:%02x:**:**:%02x",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v21,
    (unsigned int)*(char *)(a1 + 12),
    *(unsigned __int8 *)(a1 + 16),
    *(unsigned __int8 *)(a1 + 17),
    *(unsigned __int8 *)(a1 + 18),
    v39);
  qdf_trace_msg(
    0x59u,
    8u,
    "peer obj = 0x%pK peer_id = %-4d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    *(_QWORD *)(a1 + 24),
    (unsigned int)*(char *)(a1 + 14));
  return qdf_trace_msg(
           0x59u,
           8u,
           "arg1 = 0x%-8x arg2 = 0x%-8x",
           v30,
           v31,
           v32,
           v33,
           v34,
           v35,
           v36,
           v37,
           *(unsigned int *)(a1 + 32),
           *(unsigned int *)(a1 + 36));
}
