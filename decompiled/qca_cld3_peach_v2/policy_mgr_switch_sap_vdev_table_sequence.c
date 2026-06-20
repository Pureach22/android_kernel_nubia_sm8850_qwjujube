__int64 __fastcall policy_mgr_switch_sap_vdev_table_sequence(__int64 a1, _BYTE *a2, unsigned int a3)
{
  __int64 v6; // x27
  int v7; // w26
  unsigned int v8; // w22
  unsigned int v9; // w24
  unsigned int v10; // w23
  int v11; // w8
  char *v12; // x21
  char *v13; // x21
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w23
  unsigned __int8 v48; // w8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // w23
  unsigned int v58; // [xsp+Ch] [xbp-4h]

  qdf_mutex_acquire(a1 + 56);
  v6 = 0;
  LOBYTE(v7) = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v58 = 0;
  do
  {
    v11 = *(_DWORD *)((char *)&pm_conc_connection_list + v6);
    if ( v11 )
    {
      if ( v11 == 1 )
      {
        v12 = (char *)&pm_conc_connection_list + v6;
        if ( *((_BYTE *)&pm_conc_connection_list + v6 + 28) == 1 )
        {
          if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)v12 + 1)) )
          {
            v9 = *((_DWORD *)v12 + 1);
            v7 = *(_DWORD *)((char *)&pm_conc_connection_list + v6 + 24);
          }
          else if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)v12 + 1)) )
          {
            v58 = *((_DWORD *)v12 + 1);
          }
        }
      }
    }
    else
    {
      v13 = (char *)&pm_conc_connection_list + v6;
      if ( *((_BYTE *)&pm_conc_connection_list + v6 + 28) == 1 )
      {
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)v13 + 1)) )
        {
          v10 = *((_DWORD *)v13 + 1);
        }
        else if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)v13 + 1)) )
        {
          v8 = *((_DWORD *)v13 + 1);
        }
      }
    }
    v6 += 36;
  }
  while ( v6 != 180 );
  result = qdf_mutex_release(a1 + 56);
  if ( v10 )
  {
    if ( v9 )
    {
      if ( v10 != v9 )
      {
        if ( v8 )
        {
          if ( v58 )
          {
            if ( v8 != v58 )
            {
              result = wlan_reg_is_6ghz_psc_chan_freq(v8, v15, v16, v17, v18, v19, v20, v21, v22);
              if ( (result & 1) == 0 )
              {
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: 5g sta:%d, sap:%d, 6g: sta:%d, sap:%d vdev_id:%d",
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  "policy_mgr_switch_sap_vdev_table_sequence",
                  v10,
                  v9,
                  v8,
                  v58,
                  (unsigned __int8)v7);
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: before exchange vdev restart table",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "policy_mgr_switch_sap_vdev_table_sequence");
                if ( a3 )
                {
                  v47 = 0;
                  do
                    qdf_trace_msg(
                      0x4Fu,
                      8u,
                      "%s: vdev_id:%d",
                      v39,
                      v40,
                      v41,
                      v42,
                      v43,
                      v44,
                      v45,
                      v46,
                      "policy_mgr_switch_sap_vdev_table_sequence",
                      (unsigned __int8)a2[(unsigned __int8)v47++]);
                  while ( a3 > (unsigned __int8)v47 );
                  v48 = 0;
                  while ( (unsigned __int8)a2[v48] != (unsigned __int8)v7 )
                  {
                    if ( a3 <= ++v48 )
                      goto LABEL_31;
                  }
                  a2[v48] = *a2;
                  *a2 = v7;
LABEL_31:
                  qdf_trace_msg(
                    0x4Fu,
                    8u,
                    "%s: after exchange vdev restart table",
                    v39,
                    v40,
                    v41,
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    "policy_mgr_switch_sap_vdev_table_sequence");
                  v57 = 0;
                  do
                    result = qdf_trace_msg(
                               0x4Fu,
                               8u,
                               "%s: vdev_id:%d",
                               v49,
                               v50,
                               v51,
                               v52,
                               v53,
                               v54,
                               v55,
                               v56,
                               "policy_mgr_switch_sap_vdev_table_sequence",
                               (unsigned __int8)a2[(unsigned __int8)v57++]);
                  while ( a3 > (unsigned __int8)v57 );
                }
                else
                {
                  return qdf_trace_msg(
                           0x4Fu,
                           8u,
                           "%s: after exchange vdev restart table",
                           v39,
                           v40,
                           v41,
                           v42,
                           v43,
                           v44,
                           v45,
                           v46,
                           "policy_mgr_switch_sap_vdev_table_sequence");
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
