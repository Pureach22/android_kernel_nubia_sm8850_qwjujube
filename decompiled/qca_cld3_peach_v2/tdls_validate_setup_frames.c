__int64 __fastcall tdls_validate_setup_frames(
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
  int v10; // w8
  __int64 v11; // x4
  __int64 v12; // x5
  int v14; // [xsp+0h] [xbp-20h]
  int v15; // [xsp+0h] [xbp-20h]
  int v16; // [xsp+8h] [xbp-18h]
  int v17; // [xsp+8h] [xbp-18h]
  int v18; // [xsp+10h] [xbp-10h]
  int v19; // [xsp+10h] [xbp-10h]

  v10 = *a2;
  if ( *a2 )
  {
    v11 = a2[1];
    v12 = a2[2];
    a2[8] = 1;
    v16 = *(unsigned __int16 *)(a1 + 202);
    v18 = *(unsigned __int16 *)(a1 + 200);
    v14 = v10;
    qdf_trace_msg(
      0,
      2u,
      "%s: %02x:%02x:%02x:**:**:%02x TDLS Max peer already connected, send response status (%d). Num of peers (%d), Max allowed (%d).",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_validate_setup_frames",
      v11,
      v12,
      a2[3],
      a2[6],
      v14,
      v16,
      v18);
    return 0xFFFFFFFFLL;
  }
  else
  {
    v19 = *(unsigned __int16 *)(a1 + 200);
    v17 = *(unsigned __int16 *)(a1 + 202);
    v15 = 0;
    qdf_trace_msg(
      0,
      2u,
      "%s: %02x:%02x:%02x:**:**:%02x TDLS Max peer already connected. action (%d) declined. Num of peers (%d), Max allowed (%d).",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_validate_setup_frames",
      a2[1],
      a2[2],
      a2[3],
      a2[6],
      v15,
      v17,
      v19);
    return 4294967274LL;
  }
}
