__int64 __fastcall lim_chk_mcs(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  int v31; // w8

  if ( !*(_BYTE *)(a4 + 3160) )
    return 1;
  if ( (unsigned __int8)lim_check_mcs_set(a1, (unsigned __int8 *)(a4 + 3164), a6, a7, a8, a9, a10, a11, a12, a13) )
    return 1;
  if ( (_BYTE)a5 )
    v27 = "ReAssoc";
  else
    v27 = "Assoc";
  if ( a2 )
  {
    v28 = *a2;
    v29 = a2[1];
    v30 = a2[2];
    v31 = a2[5];
  }
  else
  {
    v30 = 0;
    v28 = 0;
    v29 = 0;
    v31 = 0;
  }
  qdf_trace_msg(
    0x35u,
    3u,
    "%s: rcvd %s req with unsupported MCS Rate Set from %02x:%02x:%02x:**:**:%02x",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "lim_chk_mcs",
    v27,
    v28,
    v29,
    v30,
    v31);
  lim_send_assoc_rsp_mgmt_frame(a1, 12, 1, a2, a5, 0, a3, 0, a4 + 3608);
  return 0;
}
