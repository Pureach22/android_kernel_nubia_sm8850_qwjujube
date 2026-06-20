__int64 __fastcall sme_ps_close(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 13216) == 21 )
    qdf_mc_timer_stop(a1 + 13216);
  if ( (unsigned int)qdf_mc_timer_destroy(a1 + 13216) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Cannot deallocate suto PS timer",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "sme_ps_close_per_session");
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 13408) == 21 )
    qdf_mc_timer_stop(a1 + 13408);
  if ( (unsigned int)qdf_mc_timer_destroy(a1 + 13408) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Cannot deallocate suto PS timer",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "sme_ps_close_per_session");
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 13600) == 21 )
    qdf_mc_timer_stop(a1 + 13600);
  if ( (unsigned int)qdf_mc_timer_destroy(a1 + 13600) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Cannot deallocate suto PS timer",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "sme_ps_close_per_session");
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 13792) == 21 )
    qdf_mc_timer_stop(a1 + 13792);
  if ( (unsigned int)qdf_mc_timer_destroy(a1 + 13792) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Cannot deallocate suto PS timer",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "sme_ps_close_per_session");
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 13984) == 21 )
    qdf_mc_timer_stop(a1 + 13984);
  if ( (unsigned int)qdf_mc_timer_destroy(a1 + 13984) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Cannot deallocate suto PS timer",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "sme_ps_close_per_session");
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 14176) == 21 )
    qdf_mc_timer_stop(a1 + 14176);
  if ( (unsigned int)qdf_mc_timer_destroy(a1 + 14176) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Cannot deallocate suto PS timer",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "sme_ps_close_per_session");
  return 0;
}
