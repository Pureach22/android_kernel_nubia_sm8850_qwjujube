__int64 __fastcall policy_mgr_is_special_mode_active_5g(__int64 a1, int a2)
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
  unsigned int v13; // w21
  char v14; // w21
  unsigned int v15; // w22
  unsigned int v16; // w22
  unsigned int v17; // w22
  unsigned int v18; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    qdf_mutex_acquire(context + 56);
    if ( (_DWORD)pm_conc_connection_list == a2
      && (v13 = HIDWORD(pm_conc_connection_list), v13 >= (unsigned int)wlan_reg_min_5ghz_chan_freq()) )
    {
      v14 = BYTE4(qword_81C458);
    }
    else
    {
      v14 = 0;
    }
    if ( (_DWORD)qword_81C464 == a2 )
    {
      v15 = HIDWORD(qword_81C464);
      if ( v15 >= (unsigned int)wlan_reg_min_5ghz_chan_freq() )
        v14 |= BYTE4(qword_81C47C);
    }
    if ( (_DWORD)qword_81C488 == a2 )
    {
      v16 = HIDWORD(qword_81C488);
      if ( v16 >= (unsigned int)wlan_reg_min_5ghz_chan_freq() )
        v14 |= BYTE4(qword_81C4A0);
    }
    if ( (_DWORD)qword_81C4AC == a2 )
    {
      v17 = HIDWORD(qword_81C4AC);
      if ( v17 >= (unsigned int)wlan_reg_min_5ghz_chan_freq() )
        v14 |= BYTE4(qword_81C4C4);
    }
    if ( (_DWORD)qword_81C4D0 == a2 )
    {
      v18 = HIDWORD(qword_81C4D0);
      if ( v18 >= (unsigned int)wlan_reg_min_5ghz_chan_freq() )
        v14 |= BYTE4(qword_81C4E8);
    }
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
      "policy_mgr_is_special_mode_active_5g");
    v14 = 0;
  }
  return v14 & 1;
}
