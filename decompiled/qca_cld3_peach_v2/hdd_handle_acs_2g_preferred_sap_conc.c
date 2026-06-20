__int64 __fastcall hdd_handle_acs_2g_preferred_sap_conc(__int64 result, __int64 a2, __int64 a3)
{
  __int64 *v4; // x20
  __int64 v5; // x19
  __int64 v6; // x22
  __int64 v7; // x23
  int v8; // w23
  unsigned __int8 v9; // w22
  int v10; // w24
  unsigned int v11; // w21
  unsigned int chan_width; // w0
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // [xsp+8h] [xbp-48h] BYREF
  char v31; // [xsp+Ch] [xbp-44h]
  int v32; // [xsp+10h] [xbp-40h] BYREF
  char v33; // [xsp+14h] [xbp-3Ch]
  __int64 v34; // [xsp+18h] [xbp-38h] BYREF
  __int64 v35; // [xsp+20h] [xbp-30h]
  unsigned int v36; // [xsp+28h] [xbp-28h]
  _QWORD v37[2]; // [xsp+30h] [xbp-20h] BYREF
  int v38; // [xsp+40h] [xbp-10h]
  __int64 v39; // [xsp+48h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 40) == 1 )
  {
    v4 = (__int64 *)a2;
    v5 = result;
    v33 = 0;
    v32 = 0;
    v37[0] = 0;
    v37[1] = 0;
    v38 = 0;
    v30 = 0;
    v31 = 0;
    v34 = 0;
    v35 = 0;
    v36 = 0;
    result = policy_mgr_is_hw_dbs_capable(result);
    if ( (result & 1) != 0 )
    {
      if ( *(_BYTE *)(a3 + 1184) )
      {
        v6 = *(_QWORD *)(a3 + 1176);
        v7 = 0;
        while ( 1 )
        {
          result = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v6 + 4 * v7));
          if ( (result & 1) == 0 )
            break;
          if ( ++v7 >= (unsigned __int64)*(unsigned __int8 *)(a3 + 1184) )
          {
            result = policy_mgr_get_mode_specific_conn_info(v5, (unsigned __int64)v37, (unsigned __int64)&v32, 3u);
            if ( (unsigned __int8)result == 1 )
            {
              result = wlan_reg_is_24ghz_ch_freq(v37[0]);
              if ( (result & 1) != 0 )
              {
                v8 = v37[0];
                if ( LODWORD(v37[0]) )
                {
                  v9 = v32;
                  result = policy_mgr_get_mode_specific_conn_info(v5, (unsigned __int64)&v34, (unsigned __int64)&v30, 0);
                  v10 = (unsigned __int8)result;
                  if ( (_BYTE)result )
                  {
                    result = (unsigned int)v34;
                    if ( v8 != (_DWORD)v34 )
                    {
                      result = wlan_reg_is_24ghz_ch_freq(v34);
                      if ( (result & 1) != 0 )
                        v11 = v34;
                      else
                        v11 = 0;
                      if ( v10 == 1 )
                        goto LABEL_43;
                      result = HIDWORD(v34);
                      if ( v8 == HIDWORD(v34) )
                        break;
                      result = wlan_reg_is_24ghz_ch_freq(HIDWORD(v34));
                      if ( (result & 1) != 0 )
                        v11 = HIDWORD(v34);
                      if ( v10 == 2 )
                        goto LABEL_43;
                      result = (unsigned int)v35;
                      if ( v8 == (_DWORD)v35 )
                        break;
                      result = wlan_reg_is_24ghz_ch_freq(v35);
                      if ( (result & 1) != 0 )
                        v11 = v35;
                      if ( v10 == 3 )
                        goto LABEL_43;
                      result = HIDWORD(v35);
                      if ( v8 == HIDWORD(v35) )
                        break;
                      result = wlan_reg_is_24ghz_ch_freq(HIDWORD(v35));
                      if ( (result & 1) != 0 )
                        v11 = HIDWORD(v35);
                      if ( v10 == 4 )
                        goto LABEL_43;
                      result = v36;
                      if ( v8 == v36 )
                        break;
                      result = wlan_reg_is_24ghz_ch_freq(v36);
                      if ( (result & 1) != 0 )
                        v11 = v36;
                      if ( v10 == 5 )
                      {
LABEL_43:
                        if ( !v11 )
                          break;
                        result = hdd_get_link_info_by_vdev(v4[3]);
                        if ( !result )
                          break;
                        v4 = (__int64 *)result;
                        result = _hdd_validate_adapter(*(_QWORD *)result, "hdd_handle_acs_2g_preferred_sap_conc");
                        if ( (_DWORD)result )
                          break;
                        wlan_hdd_set_sap_csa_reason(v5, v9, 0xEu);
                        qdf_event_reset((__int64)(v4 + 11));
                        chan_width = wlansap_get_chan_width(v4[34]);
                        v13 = hdd_softap_set_channel_change(v4, v11, 0, chan_width, 0, 0, 1);
                        if ( v13 )
                        {
                          result = qdf_trace_msg(
                                     0x33u,
                                     2u,
                                     "%s: CSA failed to %d, ret %d",
                                     v14,
                                     v15,
                                     v16,
                                     v17,
                                     v18,
                                     v19,
                                     v20,
                                     v21,
                                     "hdd_handle_acs_2g_preferred_sap_conc",
                                     v11,
                                     v13);
                          break;
                        }
                      }
                      else
                      {
                        __break(0x5512u);
                      }
                      result = qdf_wait_for_event_completion((__int64)(v4 + 11), 0x32C8u);
                      if ( (_DWORD)result )
                        result = qdf_trace_msg(
                                   0x33u,
                                   2u,
                                   "%s: wait for qdf_event failed!!",
                                   v22,
                                   v23,
                                   v24,
                                   v25,
                                   v26,
                                   v27,
                                   v28,
                                   v29,
                                   "hdd_handle_acs_2g_preferred_sap_conc");
                    }
                  }
                }
              }
            }
            break;
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
