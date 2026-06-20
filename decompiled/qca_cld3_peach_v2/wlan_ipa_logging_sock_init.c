__int64 __fastcall wlan_ipa_logging_sock_init(
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
  unsigned __int64 StatusReg; // x8
  __int64 v17; // x22
  __int64 v18; // x23
  unsigned __int64 thread; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  _QWORD v29[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v30) = 0;
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: Init IPA logging infra",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wlan_ipa_logging_sock_init",
    0,
    0,
    v30,
    v31);
  dword_92E0AC = 0;
  scnprintf(v29, 20, "ipa_log_thread");
  g_ipa_logging_ctx = (__int64)&g_ipa_logging_ctx;
  qword_92D840 = (__int64)&g_ipa_logging_ctx;
  qword_92D848 = 0x4000000000LL;
  qword_92D850 = (__int64)&qword_92D850;
  qword_92D858 = (__int64)&qword_92D850;
  qword_92D860 = 0x4000000000LL;
  dword_92D868 = 0;
  qword_92D870 = 0;
  g_ipa_log_msg = _qdf_mem_malloc(0x8400u, "wlan_ipa_allocate_log_msg", 208);
  if ( !g_ipa_log_msg )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Could not allocate memory for log_msg",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_ipa_logging_sock_init");
LABEL_14:
    result = 16;
    goto LABEL_15;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&dword_92D868);
  }
  else
  {
    raw_spin_lock_bh(&dword_92D868);
    qword_92D870 |= 1uLL;
  }
  v17 = 0;
  v18 = 64;
  do
  {
    qdf_list_insert_back(&g_ipa_logging_ctx, (_QWORD *)(g_ipa_log_msg + v17));
    --v18;
    v17 += 528;
  }
  while ( v18 );
  if ( (qword_92D870 & 1) != 0 )
  {
    qword_92D870 &= ~1uLL;
    raw_spin_unlock_bh(&dword_92D868);
  }
  else
  {
    raw_spin_unlock(&dword_92D868);
  }
  qword_92E0A0 = 0;
  _init_waitqueue_head(&unk_92E078, "&g_ipa_logging_ctx.wait_q", &wlan_ipa_logging_sock_init___key);
  thread = qdf_create_thread((__int64)wlan_ipa_logging_thread, 0, (__int64)v29);
  qword_92E090 = thread;
  if ( !thread )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: could not create ipa_log_thread",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_ipa_logging_sock_init");
    _qdf_mem_free(g_ipa_log_msg);
    goto LABEL_14;
  }
  qdf_wake_up_process(thread);
  qdf_sleep();
  result = 0;
  word_92E098 = 0;
  byte_92E0A8 = 0;
  *(_QWORD *)&dword_92E0B0 = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
