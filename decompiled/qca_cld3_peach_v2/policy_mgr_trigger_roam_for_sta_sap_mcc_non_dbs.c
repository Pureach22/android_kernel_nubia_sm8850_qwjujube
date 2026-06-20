__int64 __fastcall policy_mgr_trigger_roam_for_sta_sap_mcc_non_dbs(__int64 a1)
{
  __int64 result; // x0
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  char mode_specific_conn_info; // w21
  int v14; // [xsp+0h] [xbp-50h] BYREF
  _BYTE v15[4]; // [xsp+4h] [xbp-4Ch] BYREF
  int v16; // [xsp+8h] [xbp-48h] BYREF
  char v17; // [xsp+Ch] [xbp-44h]
  int v18; // [xsp+10h] [xbp-40h] BYREF
  char v19; // [xsp+14h] [xbp-3Ch]
  _QWORD v20[2]; // [xsp+18h] [xbp-38h] BYREF
  int v21; // [xsp+28h] [xbp-28h]
  _QWORD v22[2]; // [xsp+30h] [xbp-20h] BYREF
  int v23; // [xsp+40h] [xbp-10h]
  __int64 v24; // [xsp+48h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v19 = 0;
  v18 = 0;
  v23 = 0;
  v22[0] = 0;
  v22[1] = 0;
  v17 = 0;
  v16 = 0;
  v21 = 0;
  v20[0] = 0;
  v20[1] = 0;
  v14 = 0;
  result = policy_mgr_is_hw_dbs_capable(a1);
  if ( (result & 1) == 0 )
  {
    context = policy_mgr_get_context(a1);
    if ( context )
    {
      v12 = context;
      result = policy_mgr_get_mcc_scc_switch(a1, v15);
      if ( v15[0] == 6 )
      {
        qdf_mutex_acquire(v12 + 56);
        if ( (unsigned __int8)policy_mgr_get_mode_specific_conn_info(a1, v22, &v18, 0) == 1 )
        {
          mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, v20, &v16, 1);
          result = qdf_mutex_release(v12 + 56);
          if ( mode_specific_conn_info == 1 && LODWORD(v20[0]) != LODWORD(v22[0]) )
          {
            result = policy_mgr_if_freq_n_inactive_links_freq_same(a1);
            if ( (result & 1) == 0 )
            {
              result = ((__int64 (__fastcall *)(__int64, int *, _QWORD, _QWORD, _QWORD))policy_mgr_check_scc_channel)(
                         a1,
                         &v14,
                         LODWORD(v20[0]),
                         (unsigned __int8)v16,
                         v15[0]);
              if ( !v14 || v14 == LODWORD(v20[0]) )
                result = policy_mgr_roam_invoke_on_sta_for_mcc(
                           v12,
                           (unsigned __int8)v18,
                           LODWORD(v22[0]),
                           LODWORD(v20[0]));
            }
          }
        }
        else
        {
          result = qdf_mutex_release(v12 + 56);
        }
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x4Fu,
                 2u,
                 "%s: Invalid context",
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 "policy_mgr_trigger_roam_for_sta_sap_mcc_non_dbs");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
