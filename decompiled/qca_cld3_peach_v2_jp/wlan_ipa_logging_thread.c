__int64 __fastcall wlan_ipa_logging_thread(
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
  __int64 v17; // x0
  unsigned int v18; // w0
  __int64 v19; // x22
  unsigned __int64 v21; // x8
  unsigned __int64 v27; // x8
  __int64 v28; // x20
  _QWORD v30[6]; // [xsp+0h] [xbp-30h] BYREF

  v30[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dword_864E84 = 1;
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: ipa logging thread in running state",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wlan_ipa_logging_thread");
  _X24 = &qword_864E78;
  while ( 1 )
  {
    if ( (qword_864E78 & 2) == 0 && (qword_864E78 & 4) == 0 )
    {
      memset(v30, 0, 40);
      init_wait_entry(v30, 0);
      while ( 1 )
      {
        v17 = prepare_to_wait_event(&unk_864E50, v30, 1);
        if ( (qword_864E78 & 2) != 0 || (qword_864E78 & 4) != 0 )
        {
          finish_wait(&unk_864E50, v30);
          goto LABEL_16;
        }
        if ( v17 )
          break;
        schedule();
      }
      if ( (_DWORD)v17 == -512 )
        break;
    }
LABEL_16:
    __asm { PRFM            #0x11, [X24] }
    do
      v21 = __ldxr((unsigned __int64 *)&qword_864E78);
    while ( __stlxr(v21 & 0xFFFFFFFFFFFFFFFBLL, (unsigned __int64 *)&qword_864E78) );
    __dmb(0xBu);
    if ( (v21 & 4) != 0 )
      goto LABEL_25;
    __asm { PRFM            #0x11, [X24] }
    do
      v27 = __ldxr((unsigned __int64 *)&qword_864E78);
    while ( __stlxr(v27 & 0xFFFFFFFFFFFFFFFDLL, (unsigned __int64 *)&qword_864E78) );
    __dmb(0xBu);
    if ( (v27 & 2) != 0 )
    {
      v18 = wlan_ipa_send_to_userspace(0);
      if ( v18 )
      {
        v19 = jiffies;
        if ( wlan_ipa_logging_thread___last_ticks_12 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: failed to send log, ret - %d",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "wlan_ipa_logging_thread",
            v18);
          wlan_ipa_logging_thread___last_ticks_12 = v19;
        }
      }
    }
  }
  v28 = jiffies;
  if ( wlan_ipa_logging_thread___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: wait_evt_interrupt returned -ERESTARTSYS",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_ipa_logging_thread");
    wlan_ipa_logging_thread___last_ticks = v28;
  }
LABEL_25:
  dword_864E84 = 3;
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: exit ipa logging thread",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "wlan_ipa_logging_thread");
  _ReadStatusReg(SP_EL0);
  return 0;
}
