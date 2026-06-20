__int64 __fastcall policy_mgr_is_sap_p2pgo_on_dfs(
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
  __int64 context; // x0
  __int64 v11; // x19
  int v12; // w0
  int v13; // w0
  __int64 result; // x0
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  __int64 v16; // [xsp+8h] [xbp-18h]
  unsigned int v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v15 = 0;
  v16 = 0;
  if ( !a1 || (context = policy_mgr_get_context(a1)) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "policy_mgr_is_sap_p2pgo_on_dfs",
      v15);
    goto LABEL_13;
  }
  v11 = context;
  qdf_mutex_acquire(context + 56);
  v12 = policy_mgr_mode_specific_connection_count(a1, 1, &v15);
  if ( v12 >= 1 )
  {
    if ( (unsigned int)v15 >= 5 )
      goto LABEL_41;
    if ( (*((_WORD *)&pm_conc_connection_list + 18 * (unsigned int)v15 + 15) & 6) != 0 )
      goto LABEL_29;
    if ( v12 != 1 )
    {
      if ( HIDWORD(v15) > 4 )
        goto LABEL_41;
      if ( (*((_WORD *)&pm_conc_connection_list + 18 * HIDWORD(v15) + 15) & 6) != 0 )
        goto LABEL_29;
      if ( v12 != 2 )
      {
        if ( (unsigned int)v16 > 4 )
          goto LABEL_41;
        if ( (*((_WORD *)&pm_conc_connection_list + 18 * (unsigned int)v16 + 15) & 6) != 0 )
          goto LABEL_29;
        if ( v12 != 3 )
        {
          if ( HIDWORD(v16) > 4 )
            goto LABEL_41;
          if ( (*((_WORD *)&pm_conc_connection_list + 18 * HIDWORD(v16) + 15) & 6) != 0 )
            goto LABEL_29;
          if ( v12 != 4 )
          {
            if ( v17 > 4 )
              goto LABEL_41;
            if ( (*((_WORD *)&pm_conc_connection_list + 18 * v17 + 15) & 6) != 0 )
              goto LABEL_29;
            if ( v12 != 5 )
              goto LABEL_41;
          }
        }
      }
    }
  }
  v13 = policy_mgr_mode_specific_connection_count(a1, 3, &v15);
  if ( v13 >= 1 )
  {
    if ( (unsigned int)v15 >= 5 )
      goto LABEL_41;
    if ( (*((_WORD *)&pm_conc_connection_list + 18 * (unsigned int)v15 + 15) & 6) == 0 )
    {
      if ( v13 == 1 )
        goto LABEL_11;
      if ( HIDWORD(v15) <= 4 )
      {
        if ( (*((_WORD *)&pm_conc_connection_list + 18 * HIDWORD(v15) + 15) & 6) != 0 )
          goto LABEL_29;
        if ( v13 == 2 )
          goto LABEL_11;
        if ( (unsigned int)v16 <= 4 )
        {
          if ( (*((_WORD *)&pm_conc_connection_list + 18 * (unsigned int)v16 + 15) & 6) != 0 )
            goto LABEL_29;
          if ( v13 == 3 )
            goto LABEL_11;
          if ( HIDWORD(v16) <= 4 )
          {
            if ( (*((_WORD *)&pm_conc_connection_list + 18 * HIDWORD(v16) + 15) & 6) != 0 )
              goto LABEL_29;
            if ( v13 == 4 )
              goto LABEL_11;
            if ( v17 <= 4 )
            {
              if ( (*((_WORD *)&pm_conc_connection_list + 18 * v17 + 15) & 6) != 0 )
                goto LABEL_29;
              if ( v13 == 5 )
                goto LABEL_11;
            }
          }
        }
      }
LABEL_41:
      __break(0x5512u);
    }
LABEL_29:
    qdf_mutex_release(v11 + 56);
    result = 1;
    goto LABEL_30;
  }
LABEL_11:
  qdf_mutex_release(v11 + 56);
LABEL_13:
  result = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
