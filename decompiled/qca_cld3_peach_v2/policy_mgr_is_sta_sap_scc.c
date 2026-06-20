__int64 __fastcall policy_mgr_is_sta_sap_scc(__int64 a1, unsigned int a2, char a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v15 = context;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_8D4F00) == 1
      && ((unsigned int)pm_conc_connection_list | 2) == 2
      && HIDWORD(pm_conc_connection_list) == a2
      || BYTE4(qword_8D4F24) == 1 && ((unsigned int)qword_8D4F0C | 2) == 2 && HIDWORD(qword_8D4F0C) == a2
      || BYTE4(qword_8D4F48) == 1 && ((unsigned int)qword_8D4F30 | 2) == 2 && HIDWORD(qword_8D4F30) == a2
      || BYTE4(qword_8D4F6C) == 1 && ((unsigned int)qword_8D4F54 | 2) == 2 && HIDWORD(qword_8D4F54) == a2
      || BYTE4(qword_8D4F90) == 1 && ((unsigned int)qword_8D4F78 | 2) == 2 && HIDWORD(qword_8D4F78) == a2 )
    {
      qdf_mutex_release(v15 + 56);
      return 1;
    }
    qdf_mutex_release(v15 + 56);
    if ( (a3 & 1) != 0
      && (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0
      && (policy_mgr_if_freq_n_inactive_links_freq_same(a1, a2) & 1) != 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Standby/inactive link present for freq %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "policy_mgr_is_sta_sap_scc",
        a2);
      return 1;
    }
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v7, v8, v9, v10, v11, v12, v13, v14, "policy_mgr_is_sta_sap_scc");
  }
  return 0;
}
