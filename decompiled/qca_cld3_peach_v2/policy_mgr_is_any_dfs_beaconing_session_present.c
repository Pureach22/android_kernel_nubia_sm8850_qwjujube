__int64 __fastcall policy_mgr_is_any_dfs_beaconing_session_present(__int64 a1, _DWORD *a2, _DWORD *a3)
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
  unsigned int v23; // w22

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v14 = context;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_8D4F00) == 1 && ((unsigned int)pm_conc_connection_list | 2) == 3 )
    {
      if ( (wlan_reg_is_dfs_for_freq(
              *(_QWORD *)(v14 + 8),
              HIDWORD(pm_conc_connection_list),
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22)
          & 1) != 0
        || (v23 = 0, wlan_reg_is_5ghz_ch_freq(HIDWORD(pm_conc_connection_list))) && (_DWORD)qword_8D4EF0 == 7 )
      {
        v23 = 1;
        *a2 = HIDWORD(pm_conc_connection_list);
        *a3 = qword_8D4EF0;
      }
    }
    else
    {
      v23 = 0;
    }
    if ( BYTE4(qword_8D4F24) == 1
      && ((unsigned int)qword_8D4F0C | 2) == 3
      && ((wlan_reg_is_dfs_for_freq(*(_QWORD *)(v14 + 8), HIDWORD(qword_8D4F0C), v15, v16, v17, v18, v19, v20, v21, v22)
         & 1) != 0
       || wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F0C)) && (_DWORD)qword_8D4F14 == 7) )
    {
      v23 = 1;
      *a2 = HIDWORD(qword_8D4F0C);
      *a3 = qword_8D4F14;
    }
    if ( BYTE4(qword_8D4F48) == 1
      && ((unsigned int)qword_8D4F30 | 2) == 3
      && ((wlan_reg_is_dfs_for_freq(*(_QWORD *)(v14 + 8), HIDWORD(qword_8D4F30), v15, v16, v17, v18, v19, v20, v21, v22)
         & 1) != 0
       || wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F30)) && (_DWORD)qword_8D4F38 == 7) )
    {
      v23 = 1;
      *a2 = HIDWORD(qword_8D4F30);
      *a3 = qword_8D4F38;
    }
    if ( BYTE4(qword_8D4F6C) == 1
      && ((unsigned int)qword_8D4F54 | 2) == 3
      && ((wlan_reg_is_dfs_for_freq(*(_QWORD *)(v14 + 8), HIDWORD(qword_8D4F54), v15, v16, v17, v18, v19, v20, v21, v22)
         & 1) != 0
       || wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F54)) && (_DWORD)qword_8D4F5C == 7) )
    {
      v23 = 1;
      *a2 = HIDWORD(qword_8D4F54);
      *a3 = qword_8D4F5C;
    }
    if ( BYTE4(qword_8D4F90) == 1
      && ((unsigned int)qword_8D4F78 | 2) == 3
      && ((wlan_reg_is_dfs_for_freq(*(_QWORD *)(v14 + 8), HIDWORD(qword_8D4F78), v15, v16, v17, v18, v19, v20, v21, v22)
         & 1) != 0
       || wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F78)) && (_DWORD)qword_8D4F80 == 7) )
    {
      v23 = 1;
      *a2 = HIDWORD(qword_8D4F78);
      *a3 = qword_8D4F80;
    }
    qdf_mutex_release(v14 + 56);
  }
  else
  {
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
      "policy_mgr_is_any_dfs_beaconing_session_present");
    return 0;
  }
  return v23;
}
