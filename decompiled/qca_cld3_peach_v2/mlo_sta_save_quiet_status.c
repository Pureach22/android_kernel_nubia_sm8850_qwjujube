__int64 __fastcall mlo_sta_save_quiet_status(
        __int64 a1,
        unsigned __int8 a2,
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int8 *v22; // x9
  __int64 v23; // x12
  unsigned __int8 v24; // w8
  unsigned __int8 *v25; // x11
  __int64 v26; // x10
  const char *v28; // x2
  unsigned __int8 *v29; // x9

  if ( !a1 )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: invalid mlo_dev_ctx", a4, a5, a6, a7, a8, a9, a10, a11, "mlo_sta_save_quiet_status");
    return 4;
  }
  qdf_mutex_acquire(a1 + 1656);
  v22 = *(unsigned __int8 **)(a1 + 2224);
  if ( !v22 )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: invalid sta_ctx", v14, v15, v16, v17, v18, v19, v20, v21, "mlo_sta_save_quiet_status");
    goto LABEL_12;
  }
  v23 = v22[194];
  v24 = a3 & 1;
  v25 = v22 + 192;
  if ( (v23 & 1) == 0 || *v25 != a2 )
  {
    if ( (v22[197] & 1) == 0 )
      goto LABEL_15;
    if ( v22[195] == a2 )
    {
      v26 = 195;
      goto LABEL_10;
    }
    if ( !v22[194] )
    {
LABEL_15:
      v28 = "%s: mld mac %02x:%02x:%02x:**:**:%02x link id %d in quiet status %d";
      v29 = &v25[v23 | (2 * v23)];
      v29[1] = v24;
      *v29 = a2;
      v29[2] = 1;
      goto LABEL_16;
    }
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: no free buffer for link id %d to save quiet_status",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "mlo_sta_save_quiet_status",
      a2);
LABEL_12:
    qdf_mutex_release(a1 + 1656);
    return 4;
  }
  v26 = 192;
LABEL_10:
  v28 = "%s: mld mac %02x:%02x:%02x:**:**:%02x link id %d quiet status update %d";
  v22[v26 + 1] = v24;
LABEL_16:
  qdf_trace_msg(
    0x8Fu,
    8u,
    v28,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "mlo_sta_save_quiet_status",
    *(unsigned __int8 *)(a1 + 17),
    *(unsigned __int8 *)(a1 + 18),
    *(unsigned __int8 *)(a1 + 19),
    *(unsigned __int8 *)(a1 + 22),
    a2,
    a3 & 1);
  qdf_mutex_release(a1 + 1656);
  return 0;
}
