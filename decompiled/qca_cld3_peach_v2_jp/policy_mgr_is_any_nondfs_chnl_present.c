__int64 __fastcall policy_mgr_is_any_nondfs_chnl_present(__int64 a1, _DWORD *a2, char a3, unsigned __int8 a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int conc_ml_sap_link_freq; // w21
  unsigned int v27; // w22
  _BYTE v29[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v17 = context;
    qdf_mutex_acquire(context + 56);
    if ( (a3 & 1) != 0 )
      conc_ml_sap_link_freq = policy_mgr_get_conc_ml_sap_link_freq(a1, a4, v29);
    else
      conc_ml_sap_link_freq = 0;
    if ( BYTE4(qword_81C458) != 1
      || (wlan_reg_is_dfs_for_freq(
            *(_QWORD *)(v17 + 8),
            HIDWORD(pm_conc_connection_list),
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25)
        & 1) != 0
      || conc_ml_sap_link_freq && conc_ml_sap_link_freq == HIDWORD(pm_conc_connection_list) )
    {
      v27 = 0;
    }
    else
    {
      v27 = 1;
      *a2 = HIDWORD(pm_conc_connection_list);
    }
    if ( BYTE4(qword_81C47C) == 1
      && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v17 + 8), HIDWORD(qword_81C464), v18, v19, v20, v21, v22, v23, v24, v25)
        & 1) == 0
      && (!conc_ml_sap_link_freq || conc_ml_sap_link_freq != HIDWORD(qword_81C464)) )
    {
      v27 = 1;
      *a2 = HIDWORD(qword_81C464);
    }
    if ( BYTE4(qword_81C4A0) == 1
      && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v17 + 8), HIDWORD(qword_81C488), v18, v19, v20, v21, v22, v23, v24, v25)
        & 1) == 0
      && (!conc_ml_sap_link_freq || conc_ml_sap_link_freq != HIDWORD(qword_81C488)) )
    {
      v27 = 1;
      *a2 = HIDWORD(qword_81C488);
    }
    if ( BYTE4(qword_81C4C4) == 1
      && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v17 + 8), HIDWORD(qword_81C4AC), v18, v19, v20, v21, v22, v23, v24, v25)
        & 1) == 0
      && (!conc_ml_sap_link_freq || conc_ml_sap_link_freq != HIDWORD(qword_81C4AC)) )
    {
      v27 = 1;
      *a2 = HIDWORD(qword_81C4AC);
    }
    if ( BYTE4(qword_81C4E8) == 1
      && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v17 + 8), HIDWORD(qword_81C4D0), v18, v19, v20, v21, v22, v23, v24, v25)
        & 1) == 0
      && (!conc_ml_sap_link_freq || conc_ml_sap_link_freq != HIDWORD(qword_81C4D0)) )
    {
      v27 = 1;
      *a2 = HIDWORD(qword_81C4D0);
    }
    qdf_mutex_release(v17 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_is_any_nondfs_chnl_present");
    v27 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v27;
}
