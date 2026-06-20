__int64 __fastcall sap_dfs_cac_timer_callback(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int *v9; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  const char *v20; // x2
  _QWORD v21[4]; // [xsp+0h] [xbp-20h] BYREF

  v21[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v20 = "%s: Invalid mac_handle";
LABEL_34:
    result = qdf_trace_msg(0x39u, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, "sap_dfs_cac_timer_callback");
    goto LABEL_35;
  }
  v9 = *(unsigned int **)(a1 + 14816);
  if ( (*(_DWORD *)(a1 + 14824) | 2) != 3
    || ((unsigned __int8)sap_is_dfs_cac_wait_state(*(_QWORD *)(a1 + 14816), a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
  {
    if ( v9 )
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs: mode:%d intf:%d state:%d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "sap_find_cac_wait_session",
        *(unsigned int *)(a1 + 14824),
        0,
        v9[182]);
    v9 = *(unsigned int **)(a1 + 14832);
    if ( (*(_DWORD *)(a1 + 14840) | 2) != 3
      || ((unsigned __int8)sap_is_dfs_cac_wait_state(*(_QWORD *)(a1 + 14832), a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
    {
      if ( v9 )
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: sapdfs: mode:%d intf:%d state:%d",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "sap_find_cac_wait_session",
          *(unsigned int *)(a1 + 14840),
          1,
          v9[182]);
      v9 = *(unsigned int **)(a1 + 14848);
      if ( (*(_DWORD *)(a1 + 14856) | 2) != 3
        || ((unsigned __int8)sap_is_dfs_cac_wait_state(*(_QWORD *)(a1 + 14848), a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
      {
        if ( v9 )
          qdf_trace_msg(
            0x39u,
            8u,
            "%s: sapdfs: mode:%d intf:%d state:%d",
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            "sap_find_cac_wait_session",
            *(unsigned int *)(a1 + 14856),
            2,
            v9[182]);
        v9 = *(unsigned int **)(a1 + 14864);
        if ( (*(_DWORD *)(a1 + 14872) | 2) != 3
          || ((unsigned __int8)sap_is_dfs_cac_wait_state(*(_QWORD *)(a1 + 14864), a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
        {
          if ( v9 )
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: sapdfs: mode:%d intf:%d state:%d",
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              "sap_find_cac_wait_session",
              *(unsigned int *)(a1 + 14872),
              3,
              v9[182]);
          v9 = *(unsigned int **)(a1 + 14880);
          if ( (*(_DWORD *)(a1 + 14888) | 2) != 3
            || ((unsigned __int8)sap_is_dfs_cac_wait_state(*(_QWORD *)(a1 + 14880), a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
          {
            if ( v9 )
              qdf_trace_msg(
                0x39u,
                8u,
                "%s: sapdfs: mode:%d intf:%d state:%d",
                a2,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                "sap_find_cac_wait_session",
                *(unsigned int *)(a1 + 14888),
                4,
                v9[182]);
            v9 = *(unsigned int **)(a1 + 14896);
            if ( (*(_DWORD *)(a1 + 14904) | 2) != 3
              || ((unsigned __int8)sap_is_dfs_cac_wait_state(*(_QWORD *)(a1 + 14896), a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
            {
              if ( v9 )
                qdf_trace_msg(
                  0x39u,
                  8u,
                  "%s: sapdfs: mode:%d intf:%d state:%d",
                  a2,
                  a3,
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  "sap_find_cac_wait_session",
                  *(unsigned int *)(a1 + 14904),
                  5,
                  v9[182]);
              goto LABEL_33;
            }
          }
        }
      }
    }
  }
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: found SAP in cac wait state",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "sap_find_cac_wait_session");
  if ( !v9 )
  {
LABEL_33:
    v20 = "%s: no SAP contexts in wait state";
    goto LABEL_34;
  }
  if ( *(_BYTE *)(a1 + 14809) == 1 )
  {
    if ( (*((_BYTE *)v9 + 1627) & 1) == 0 )
      qdf_mc_timer_destroy(a1 + 14640);
    *(_BYTE *)(a1 + 14809) = 0;
  }
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sapdfs: Sending eSAP_DFS_CHANNEL_CAC_END for target_chan_freq = %d on sapctx[%pK]",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "sap_dfs_cac_timer_callback",
    *v9,
    v9);
  v21[0] = 0;
  v21[1] = 15;
  v21[2] = 0;
  result = sap_fsm(v9, (__int64)v21, v11, v12, v13, v14, v15, v16, v17, v18);
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
