__int64 __fastcall policy_mgr_mode_specific_connection_count_with_mlo(__int64 a1, int a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  int v13; // w10
  int v14; // w9
  int v15; // w11
  int v16; // w12
  int v17; // w8
  int v18; // w9
  unsigned int v19; // w19

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    qdf_mutex_acquire(context + 56);
    v13 = BYTE4(qword_81C458);
    v14 = BYTE4(qword_81C47C);
    if ( (_DWORD)pm_conc_connection_list != a2 )
      v13 = 0;
    v15 = BYTE4(qword_81C4A0);
    if ( (_DWORD)qword_81C464 != a2 )
      v14 = 0;
    v16 = BYTE4(qword_81C4C4);
    if ( (_DWORD)qword_81C488 != a2 )
      v15 = 0;
    if ( (_DWORD)qword_81C4AC != a2 )
      v16 = 0;
    v17 = BYTE4(qword_81C4E8);
    v18 = v13 + v14 + v15 + v16;
    if ( (_DWORD)qword_81C4D0 != a2 )
      v17 = 0;
    v19 = v18 + v17;
    qdf_mutex_release(v12 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_mode_specific_connection_count_with_mlo");
    return 0;
  }
  return v19;
}
