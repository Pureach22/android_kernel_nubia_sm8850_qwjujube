__int64 __fastcall sme_ps_open(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w20
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  mlme_set_user_ps(*(_QWORD *)(a1 + 21624), 0, 1);
  *(_DWORD *)(a1 + 13200) = 0;
  *(_QWORD *)(a1 + 13192) = a1;
  v10 = 0;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13216, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13192) )
    goto LABEL_7;
  mlme_set_user_ps(*(_QWORD *)(a1 + 21624), 1, 1);
  *(_DWORD *)(a1 + 13392) = 1;
  *(_QWORD *)(a1 + 13384) = a1;
  v10 = 1;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13408, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13384) )
    goto LABEL_7;
  v10 = 2;
  mlme_set_user_ps(*(_QWORD *)(a1 + 21624), 2, 1);
  *(_DWORD *)(a1 + 13584) = 2;
  *(_QWORD *)(a1 + 13576) = a1;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13600, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13576) )
    goto LABEL_7;
  v10 = 3;
  mlme_set_user_ps(*(_QWORD *)(a1 + 21624), 3, 1);
  *(_DWORD *)(a1 + 13776) = 3;
  *(_QWORD *)(a1 + 13768) = a1;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13792, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13768) )
    goto LABEL_7;
  v10 = 4;
  mlme_set_user_ps(*(_QWORD *)(a1 + 21624), 4, 1);
  *(_DWORD *)(a1 + 13968) = 4;
  *(_QWORD *)(a1 + 13960) = a1;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13984, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13960)
    || (v10 = 5,
        mlme_set_user_ps(*(_QWORD *)(a1 + 21624), 5, 1),
        *(_DWORD *)(a1 + 14160) = 5,
        *(_QWORD *)(a1 + 14152) = a1,
        result = qdf_mc_timer_init(a1 + 14176, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 14152),
        (_DWORD)result) )
  {
LABEL_7:
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Cannot allocate timer for auto ps entry",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "sme_ps_open_per_session");
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: PMC Init Failed for session: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sme_ps_open",
      v10);
    return 16;
  }
  return result;
}
