__int64 __fastcall wlan_ipa_logging_sock_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  unsigned __int64 v28; // x9
  unsigned __int64 v31; // x10
  unsigned __int64 v38; // x9

  qdf_trace_msg(
    0x61u,
    4u,
    "%s: Deinit IPA logging infra",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wlan_ipa_logging_sock_deinit");
  if ( !qdf_list_empty(&qword_92D850) )
  {
    _X8 = &qword_92E0A0;
    __asm { PRFM            #0x11, [X8] }
    do
      v38 = __ldxr((unsigned __int64 *)&qword_92E0A0);
    while ( __stxr(v38 | 2, (unsigned __int64 *)&qword_92E0A0) );
    _wake_up(&unk_92E078, 1, 1, 0);
    qdf_sleep();
  }
  _X8 = &qword_92E0A0;
  __asm { PRFM            #0x11, [X8] }
  do
    v28 = __ldxr((unsigned __int64 *)&qword_92E0A0);
  while ( __stxr(v28 | 4, (unsigned __int64 *)&qword_92E0A0) );
  dword_92E0AC = 2;
  _X9 = &qword_92E0A0;
  __asm { PRFM            #0x11, [X9] }
  do
    v31 = __ldxr((unsigned __int64 *)&qword_92E0A0);
  while ( __stxr(v31 & 0xFFFFFFFFFFFFFFFDLL, (unsigned __int64 *)&qword_92E0A0) );
  _wake_up(&unk_92E078, 1, 1, 0);
  v16 = 101;
  while ( dword_92E0AC != 3 )
  {
    qdf_sleep();
    if ( !--v16 )
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: IPA thread failed to cancel",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wlan_ipa_logging_sock_deinit");
      break;
    }
  }
  if ( !qdf_list_empty(&qword_92D850) )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: send log from deinit",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_ipa_logging_sock_deinit");
    wlan_ipa_send_to_userspace(1);
  }
  result = _qdf_mem_free(g_ipa_log_msg);
  g_ipa_log_msg = 0;
  return result;
}
