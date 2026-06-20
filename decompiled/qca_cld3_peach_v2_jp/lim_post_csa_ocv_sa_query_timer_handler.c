__int64 __fastcall lim_post_csa_ocv_sa_query_timer_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x21
  unsigned __int16 v19; // w20
  _WORD *v21; // x27
  __int64 hash_entry; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w4
  __int64 v32; // x27
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  qdf_trace_msg(
    0x35u,
    8u,
    "%s: CSA Post OCV SA Query timer fires",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "lim_post_csa_ocv_sa_query_timer_handler");
  if ( !a1 || !*(_BYTE *)(a1 + 70) || *(_DWORD *)(a1 + 88) != 1 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Session is not valid",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "lim_post_csa_ocv_sa_query_timer_handler");
  if ( *(_WORD *)(a1 + 376) )
  {
    v18 = *(_QWORD *)(a1 + 8608);
    v19 = 0;
    do
    {
      hash_entry = dph_get_hash_entry(v18, v19, a1 + 360);
      if ( hash_entry )
      {
        v31 = *(_DWORD *)(hash_entry + 8);
        if ( v31 <= 0xF && ((1 << v31) & 0xD000) != 0 )
        {
          if ( (*(_WORD *)hash_entry & 0x1000) != 0 )
          {
            v32 = hash_entry;
            qdf_trace_msg(
              0x35u,
              4u,
              "%s: No STA SA Query after CSA, Deauth %02x:%02x:%02x:**:**:%02x",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "lim_post_csa_ocv_sa_query_timer_handler",
              *(unsigned __int8 *)(hash_entry + 338),
              *(unsigned __int8 *)(hash_entry + 339),
              *(unsigned __int8 *)(hash_entry + 340),
              *(unsigned __int8 *)(hash_entry + 343));
            lim_send_deauth_mgmt_frame(v18, 2u, (void *)(v32 + 338), a1, 1, v33, v34, v35, v36, v37, v38, v39, v40);
            *(_BYTE *)(v32 + 642) = 1;
          }
        }
        else
        {
          v21 = (_WORD *)hash_entry;
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Invalid STA state %d",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "lim_post_csa_ocv_sa_query_timer_handler");
          *v21 &= ~0x1000u;
        }
      }
      ++v19;
    }
    while ( *(unsigned __int16 *)(a1 + 376) > (unsigned int)v19 );
  }
  return qdf_mc_timer_stop(a1 + 9800);
}
