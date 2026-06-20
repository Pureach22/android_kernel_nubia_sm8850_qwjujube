__int64 __fastcall policy_mgr_get_sap_ch_width_update_action(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int *a4,
        _DWORD *a5)
{
  __int64 context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  unsigned int v20; // w24
  unsigned int bw; // w20
  int v22; // w8
  unsigned int v23; // w23
  unsigned int v24; // w24
  unsigned int v25; // w22
  bool v26; // cc
  bool v27; // w8
  bool v28; // [xsp+8h] [xbp-38h] BYREF
  unsigned int v29; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v30; // [xsp+10h] [xbp-30h] BYREF
  int v31; // [xsp+18h] [xbp-28h] BYREF
  __int16 v32; // [xsp+1Ch] [xbp-24h]
  _QWORD v33[4]; // [xsp+20h] [xbp-20h] BYREF

  v33[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v33, 0, 24);
  v32 = 0;
  v31 = 0;
  v28 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( *(_DWORD *)(context + 268) == 21 )
      qdf_mc_timer_stop(context + 120);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid context",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_stop_opportunistic_timer");
  }
  result = wlan_psoc_mlme_get_11be_capab(a1, &v28);
  if ( !(_DWORD)result && v28 )
  {
    v29 = 0;
    result = policy_mgr_get_sap_bw(a1, &v29);
    if ( !(_DWORD)result )
    {
      v20 = v29;
      if ( v29 >= 3 )
      {
        result = policy_mgr_get_mode_specific_conn_info(a1, v33, &v31, 1);
        if ( a3 && v20 == 7 )
        {
          v30 = 0;
          bw = policy_mgr_get_bw(7);
          result = policy_mgr_is_conn_lead_to_dbs_sbs(a1, a2, a3);
          if ( (result & 1) != 0 )
          {
            result = policy_mgr_get_hw_dbs_max_bw(a1, &v30);
            if ( bw > HIDWORD(v30) && bw > (unsigned int)v30 )
            {
              v22 = 16;
LABEL_29:
              *a4 = v22;
            }
          }
        }
        else if ( !a3 && v20 == 3 )
        {
          v23 = v33[0];
          v24 = (unsigned __int8)v31;
          v30 = 0;
          v25 = policy_mgr_get_bw(3);
          result = policy_mgr_is_conn_lead_to_dbs_sbs(a1, v24, v23);
          if ( (result & 1) != 0 )
          {
            result = policy_mgr_get_hw_dbs_max_bw(a1, &v30);
            v26 = v25 > HIDWORD(v30) && v25 > (unsigned int)v30;
            v27 = v26;
          }
          else
          {
            v27 = 0;
          }
          if ( a5 && !v27 && (*a5 | 4) == 4 )
          {
            v22 = 17;
            goto LABEL_29;
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
