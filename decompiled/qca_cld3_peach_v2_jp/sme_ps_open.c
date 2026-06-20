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

  mlme_set_user_ps(*(_QWORD *)(a1 + 21552), 0, 1);
  *(_DWORD *)(a1 + 13128) = 0;
  *(_QWORD *)(a1 + 13120) = a1;
  v10 = 0;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13144, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13120) )
    goto LABEL_7;
  mlme_set_user_ps(*(_QWORD *)(a1 + 21552), 1, 1);
  *(_DWORD *)(a1 + 13320) = 1;
  *(_QWORD *)(a1 + 13312) = a1;
  v10 = 1;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13336, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13312) )
    goto LABEL_7;
  v10 = 2;
  mlme_set_user_ps(*(_QWORD *)(a1 + 21552), 2, 1);
  *(_DWORD *)(a1 + 13512) = 2;
  *(_QWORD *)(a1 + 13504) = a1;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13528, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13504) )
    goto LABEL_7;
  v10 = 3;
  mlme_set_user_ps(*(_QWORD *)(a1 + 21552), 3, 1);
  *(_DWORD *)(a1 + 13704) = 3;
  *(_QWORD *)(a1 + 13696) = a1;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13720, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13696) )
    goto LABEL_7;
  v10 = 4;
  mlme_set_user_ps(*(_QWORD *)(a1 + 21552), 4, 1);
  *(_DWORD *)(a1 + 13896) = 4;
  *(_QWORD *)(a1 + 13888) = a1;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 13912, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 13888)
    || (v10 = 5,
        mlme_set_user_ps(*(_QWORD *)(a1 + 21552), 5, 1),
        *(_DWORD *)(a1 + 14088) = 5,
        *(_QWORD *)(a1 + 14080) = a1,
        result = qdf_mc_timer_init(a1 + 14104, 0, (__int64)sme_auto_ps_entry_timer_expired, a1 + 14080),
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
