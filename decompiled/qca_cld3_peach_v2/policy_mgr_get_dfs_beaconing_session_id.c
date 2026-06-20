__int64 __fastcall policy_mgr_get_dfs_beaconing_session_id(__int64 a1)
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
  __int64 *v11; // x8
  unsigned int v12; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v10 = context;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_8D4F00) == 1
      && wlan_reg_is_5ghz_ch_freq(HIDWORD(pm_conc_connection_list))
      && (qword_8D4F00 & 0x6000000000000LL) != 0
      && (v11 = &pm_conc_connection_list, ((unsigned int)pm_conc_connection_list | 2) == 3)
      || BYTE4(qword_8D4F24) == 1
      && wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F0C))
      && (qword_8D4F24 & 0x6000000000000LL) != 0
      && (v11 = &qword_8D4F0C, ((unsigned int)qword_8D4F0C | 2) == 3)
      || BYTE4(qword_8D4F48) == 1
      && wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F30))
      && (qword_8D4F48 & 0x6000000000000LL) != 0
      && (v11 = &qword_8D4F30, ((unsigned int)qword_8D4F30 | 2) == 3)
      || BYTE4(qword_8D4F6C) == 1
      && wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F54))
      && (qword_8D4F6C & 0x6000000000000LL) != 0
      && (v11 = &qword_8D4F54, ((unsigned int)qword_8D4F54 | 2) == 3)
      || BYTE4(qword_8D4F90) == 1
      && wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F78))
      && (qword_8D4F90 & 0x6000000000000LL) != 0
      && (v11 = &qword_8D4F78, ((unsigned int)qword_8D4F78 | 2) == 3) )
    {
      v12 = *((_DWORD *)v11 + 6);
    }
    else
    {
      v12 = 255;
    }
    qdf_mutex_release(v10 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_get_dfs_beaconing_session_id");
    return 255;
  }
  return v12;
}
