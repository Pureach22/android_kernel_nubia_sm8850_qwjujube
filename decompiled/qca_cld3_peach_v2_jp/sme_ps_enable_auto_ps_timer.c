__int64 __fastcall sme_ps_enable_auto_ps_timer(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  unsigned int v7; // w20
  char user_ps; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x2
  __int64 result; // x0
  __int64 v19; // x20
  unsigned int current_state; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // [xsp+0h] [xbp-30h]
  __int64 v30; // [xsp+8h] [xbp-28h]

  if ( (unsigned int)a2 >= 7 )
  {
    __break(0x5512u);
    return sme_ps_timer_flush_sync(a1, a2);
  }
  else
  {
    v29 = v3;
    v30 = v4;
    v7 = a2;
    user_ps = mlme_get_user_ps(*(_QWORD *)(a1 + 21552), a2);
    if ( !a3 && (user_ps & 1) == 0 )
    {
      v17 = "%s: auto_ps_timer called with timeout 0; ignore";
LABEL_5:
      qdf_trace_msg(0x34u, 8u, v17, v9, v10, v11, v12, v13, v14, v15, v16, "sme_ps_enable_auto_ps_timer", v29, v30);
      return 0;
    }
    v19 = a1 + 192LL * v7;
    current_state = qdf_mc_timer_get_current_state(v19 + 13144);
    if ( (current_state & 0xFFFFFFFE) == 0x14 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: auto_ps_timer is already started: %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "sme_ps_enable_auto_ps_timer",
        current_state,
        v3,
        v30);
      return 0;
    }
    else
    {
      if ( !a3 )
        a3 = 1000;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Start auto_ps_timer for %d ms",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "sme_ps_enable_auto_ps_timer",
        a3,
        v3,
        v30);
      result = qdf_mc_timer_start(v19 + 13144, a3);
      if ( (_DWORD)result )
      {
        if ( (_DWORD)result == 6 )
        {
          v17 = "%s: auto_ps_timer is already started";
          goto LABEL_5;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Cannot start auto_ps_timer",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "sme_ps_enable_auto_ps_timer");
        return 16;
      }
    }
  }
  return result;
}
