// positive sp value has been detected, the output may be wrong!
void __usercall sub_2A01B4(char a1@<W8>)
{
  unsigned int v1; // w19
  unsigned int *v2; // x20
  char v3; // w21
  unsigned int v4; // w22
  __int64 v5; // x23
  __int64 v6; // x24
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  __int64 v41; // x26
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w25
  __int64 v51; // x10
  unsigned int v52; // w22
  unsigned int user_config_sap_freq; // w0
  __int64 v54; // x23
  int v55; // w24
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  _DWORD v65[102]; // [xsp-26Ch] [xbp-26Ch] BYREF
  _BYTE v66[104]; // [xsp-D4h] [xbp-D4h] BYREF
  unsigned int v67[27]; // [xsp-6Ch] [xbp-6Ch] BYREF

  if ( (v6 & 0x1000000000LL) != 0 )
  {
    ((void (*)(void))policy_mgr_sap_on_non_psc_channel)();
    return;
  }
  if ( (a1 & 1) == 0 && (unsigned __int8)policy_mgr_mode_specific_connection_count(v5, 0, nullptr) && v3 == 4 )
  {
    if ( policy_mgr_get_context(v5) )
    {
      qdf_mem_set(v65, 0x204u, 0);
      if ( (unsigned int)policy_mgr_get_pcl_for_existing_conn(
                           v5,
                           1u,
                           (__int64)v65,
                           v67,
                           (__int64)v66,
                           0x66u,
                           0,
                           v4,
                           v15,
                           v16,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22) )
      {
        v23 = "%s: Unable to get PCL for SAP";
      }
      else if ( v67[0]
             || (unsigned int)policy_mgr_mode_specific_connection_count(v5, 1, nullptr)
             || (qdf_trace_msg(
                   0x4Fu,
                   8u,
                   "%s: policy_mgr_get_pcl_for_existing_conn returned no pcl",
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   "policy_mgr_get_sap_mandatory_channel"),
                 !(unsigned int)((__int64 (__fastcall *)(__int64, __int64, _DWORD *, unsigned int *, _BYTE *, __int64, _QWORD))policy_mgr_get_pcl)(
                                  v5,
                                  1,
                                  v65,
                                  v67,
                                  v66,
                                  102,
                                  v4)) )
      {
        if ( (unsigned int)policy_mgr_modify_sap_pcl_based_on_mandatory_channel(v5, (__int64)v65, (__int64)v66, v67, v4) )
        {
          v23 = "%s: Unable to modify SAP PCL";
        }
        else
        {
          if ( v67[0] )
          {
            if ( (policy_mgr_are_sbs_chan(v5, v1, *v2) & 1) != 0 && v67[0] )
            {
              v40 = 0;
              while ( 1 )
              {
                if ( v40 == 102 )
                  goto LABEL_62;
                if ( v65[v40] == v1 )
                  break;
                if ( v67[0] == ++v40 )
                  goto LABEL_23;
              }
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: As both freq, %d and %d are SBS, allow sap on mandatory freq %d",
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                "policy_mgr_get_sap_mandatory_channel",
                v1,
                *v2,
                v1);
              *v2 = 0;
            }
            else
            {
LABEL_23:
              if ( wlan_reg_is_24ghz_ch_freq(*v2) || !v67[0] )
              {
LABEL_29:
                policy_mgr_promote_best_sap_channel_in_pcl(v5, v4, (__int64)v65, v67);
                v50 = v65[0];
                if ( v67[0] )
                {
                  v51 = 0;
                  while ( 1 )
                  {
                    if ( v51 == 102 )
                      goto LABEL_62;
                    if ( v65[v51] == *v2 )
                      break;
                    if ( v67[0] == ++v51 )
                      goto LABEL_40;
                  }
                  v50 = *v2;
                }
LABEL_40:
                user_config_sap_freq = policy_mgr_get_user_config_sap_freq(v5, v4);
                if ( v67[0] )
                {
                  v52 = user_config_sap_freq;
                  v54 = 0;
                  v55 = v6 ^ 1;
                  while ( 1 )
                  {
                    if ( v54 == 102 )
                      goto LABEL_62;
                    if ( (wlan_reg_is_freq_indoor() & 1) != 0 && ((wlan_reg_is_6ghz_chan_freq(v65[v54]) | v55) & 1) == 0 )
                      break;
                    if ( v52 && v65[v54] == v52 )
                    {
                      qdf_trace_msg(
                        0x4Fu,
                        8u,
                        "%s: Prefer starting SAP on user configured channel:%d",
                        v56,
                        v57,
                        v58,
                        v59,
                        v60,
                        v61,
                        v62,
                        v63,
                        "policy_mgr_get_sap_mandatory_channel",
                        v52);
                      goto LABEL_61;
                    }
                    if ( ++v54 >= (unsigned __int64)v67[0] )
                      goto LABEL_49;
                  }
                  v52 = v65[v54];
                  qdf_trace_msg(
                    0x4Fu,
                    8u,
                    "%s: Choose Indoor channel from PCL list %d sap_new_freq %d",
                    v56,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    "policy_mgr_get_sap_mandatory_channel",
                    *v2,
                    v52);
                }
                else
                {
LABEL_49:
                  if ( (wlan_reg_is_6ghz_chan_freq(v1) || wlan_reg_is_5ghz_ch_freq(v1) && wlan_reg_is_5ghz_ch_freq(*v2))
                    && v67[0] )
                  {
                    v52 = *v2;
                    v64 = 0;
                    while ( v64 != 102 )
                    {
                      if ( v65[v64] == v52 )
                        goto LABEL_61;
                      if ( v67[0] == ++v64 )
                        goto LABEL_58;
                    }
LABEL_62:
                    __break(0x5512u);
                    JUMPOUT(0x2A0814);
                  }
LABEL_58:
                  v52 = v50;
                }
              }
              else
              {
                v41 = 0;
                while ( 1 )
                {
                  if ( v41 == 102 )
                    goto LABEL_62;
                  if ( (policy_mgr_are_sbs_chan(v5, v65[v41], *v2) & 1) != 0 )
                    break;
                  if ( ++v41 >= (unsigned __int64)v67[0] )
                    goto LABEL_29;
                }
                v52 = v65[v41];
              }
LABEL_61:
              *v2 = v52;
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: Mandatory channel:%d org sap ch %d",
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                "policy_mgr_get_sap_mandatory_channel",
                v52,
                v1);
            }
            goto LABEL_15;
          }
          v23 = "%s: No common channel between mandatory list & PCL";
        }
      }
      else
      {
        v23 = "%s: Unable to get PCL for SAP: policy_mgr_get_pcl";
      }
    }
    else
    {
      v23 = "%s: Invalid Context";
    }
    qdf_trace_msg(0x4Fu, 2u, v23, v7, v8, v9, v10, v11, v12, v13, v14, "policy_mgr_get_sap_mandatory_channel");
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
}
