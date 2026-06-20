__int64 __fastcall policy_mgr_is_any_mode_active_on_band_along_with_session(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3)
{
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v14 = context;
    qdf_mutex_acquire(context + 56);
    if ( a3 > 1 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalidband option:%d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "policy_mgr_is_any_mode_active_on_band_along_with_session",
        a3);
    }
    else if ( a3 )
    {
      if ( (_DWORD)qword_81C458 != a2
        && BYTE4(qword_81C458) == 1
        && wlan_reg_is_5ghz_ch_freq(HIDWORD(pm_conc_connection_list))
        || (_DWORD)qword_81C47C != a2 && BYTE4(qword_81C47C) == 1 && wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C464))
        || (_DWORD)qword_81C4A0 != a2 && BYTE4(qword_81C4A0) == 1 && wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C488))
        || (_DWORD)qword_81C4C4 != a2 && BYTE4(qword_81C4C4) == 1 && wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4AC))
        || (_DWORD)qword_81C4E8 != a2 && BYTE4(qword_81C4E8) == 1 && wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4D0)) )
      {
LABEL_38:
        v23 = 1;
        goto LABEL_39;
      }
    }
    else if ( (_DWORD)qword_81C458 != a2
           && BYTE4(qword_81C458) == 1
           && wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
           || (_DWORD)qword_81C47C != a2 && BYTE4(qword_81C47C) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464))
           || (_DWORD)qword_81C4A0 != a2 && BYTE4(qword_81C4A0) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488))
           || (_DWORD)qword_81C4C4 != a2 && BYTE4(qword_81C4C4) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC))
           || (_DWORD)qword_81C4E8 != a2 && BYTE4(qword_81C4E8) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0)) )
    {
      goto LABEL_38;
    }
    v23 = 0;
LABEL_39:
    qdf_mutex_release(v14 + 56);
    return v23;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid Context",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "policy_mgr_is_any_mode_active_on_band_along_with_session");
  return 0;
}
