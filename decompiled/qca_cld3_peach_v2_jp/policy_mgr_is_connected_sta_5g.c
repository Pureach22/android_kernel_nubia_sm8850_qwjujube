__int64 __fastcall policy_mgr_is_connected_sta_5g(__int64 a1, _DWORD *a2)
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
  __int64 v12; // x19
  unsigned int v13; // w0
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w0
  unsigned int v18; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    qdf_mutex_acquire(context + 56);
    v13 = HIDWORD(pm_conc_connection_list);
    *a2 = HIDWORD(pm_conc_connection_list);
    if ( !(_DWORD)pm_conc_connection_list && wlan_reg_is_5ghz_ch_freq(v13) && (qword_81C458 & 0x100000000LL) != 0 )
      goto LABEL_17;
    v14 = HIDWORD(qword_81C464);
    *a2 = HIDWORD(qword_81C464);
    if ( !(_DWORD)qword_81C464 && wlan_reg_is_5ghz_ch_freq(v14) && (qword_81C47C & 0x100000000LL) != 0 )
      goto LABEL_17;
    if ( (v15 = HIDWORD(qword_81C488), *a2 = HIDWORD(qword_81C488), !(_DWORD)qword_81C488)
      && wlan_reg_is_5ghz_ch_freq(v15)
      && (qword_81C4A0 & 0x100000000LL) != 0
      || (v16 = HIDWORD(qword_81C4AC), *a2 = HIDWORD(qword_81C4AC), !(_DWORD)qword_81C4AC)
      && wlan_reg_is_5ghz_ch_freq(v16)
      && (qword_81C4C4 & 0x100000000LL) != 0
      || (v17 = HIDWORD(qword_81C4D0), *a2 = HIDWORD(qword_81C4D0), !(_DWORD)qword_81C4D0)
      && wlan_reg_is_5ghz_ch_freq(v17)
      && (qword_81C4E8 & 0x100000000LL) != 0 )
    {
LABEL_17:
      v18 = 1;
    }
    else
    {
      v18 = 0;
    }
    qdf_mutex_release(v12 + 56);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_is_connected_sta_5g");
    return 0;
  }
  return v18;
}
