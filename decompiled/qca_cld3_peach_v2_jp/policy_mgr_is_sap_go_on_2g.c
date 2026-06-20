__int64 __fastcall policy_mgr_is_sap_go_on_2g(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned int v11; // w20
  char v12; // w20
  unsigned int v13; // w21
  unsigned int v14; // w21
  unsigned int v15; // w21
  unsigned int v16; // w21

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v10 = context;
    qdf_mutex_acquire(context + 56);
    if ( ((unsigned int)pm_conc_connection_list | 2) == 3
      && (v11 = HIDWORD(pm_conc_connection_list), v11 <= (unsigned int)wlan_reg_max_24ghz_chan_freq()) )
    {
      v12 = BYTE4(qword_81C458);
    }
    else
    {
      v12 = 0;
    }
    if ( ((unsigned int)qword_81C464 | 2) == 3 )
    {
      v13 = HIDWORD(qword_81C464);
      if ( v13 <= (unsigned int)wlan_reg_max_24ghz_chan_freq() )
        v12 |= BYTE4(qword_81C47C);
    }
    if ( ((unsigned int)qword_81C488 | 2) == 3 )
    {
      v14 = HIDWORD(qword_81C488);
      if ( v14 <= (unsigned int)wlan_reg_max_24ghz_chan_freq() )
        v12 |= BYTE4(qword_81C4A0);
    }
    if ( ((unsigned int)qword_81C4AC | 2) == 3 )
    {
      v15 = HIDWORD(qword_81C4AC);
      if ( v15 <= (unsigned int)wlan_reg_max_24ghz_chan_freq() )
        v12 |= BYTE4(qword_81C4C4);
    }
    if ( ((unsigned int)qword_81C4D0 | 2) == 3 )
    {
      v16 = HIDWORD(qword_81C4D0);
      if ( v16 <= (unsigned int)wlan_reg_max_24ghz_chan_freq() )
        v12 |= BYTE4(qword_81C4E8);
    }
    qdf_mutex_release(v10 + 56);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_is_sap_go_on_2g");
    v12 = 0;
  }
  return v12 & 1;
}
