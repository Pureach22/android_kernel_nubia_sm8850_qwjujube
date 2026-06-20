__int64 __fastcall policy_mgr_get_current_pref_hw_mode_dbs_1x1(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  const char *v12; // x2
  __int64 result; // x0
  unsigned int connection_count; // w20
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
  char v31; // w20
  char v32; // w0
  bool v33; // zf
  unsigned int v34; // w20
  char v35; // w20
  char v36; // w21
  char v37; // w0
  __int64 v38; // [xsp+8h] [xbp-18h] BYREF
  __int64 v39; // [xsp+10h] [xbp-10h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v12 = "%s: Invalid Context";
    goto LABEL_5;
  }
  v11 = comp_private_obj;
  if ( !(unsigned int)policy_mgr_get_current_hw_mode(a1, &v38) )
  {
    connection_count = policy_mgr_get_connection_count(a1);
    qdf_mutex_acquire(v11 + 56);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: chan[0]:%d chan[1]:%d chan[2]:%d num_connections:%d dbs:%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "policy_mgr_get_current_pref_hw_mode_dbs_1x1",
      HIDWORD(pm_conc_connection_list),
      HIDWORD(qword_8D4F0C),
      HIDWORD(qword_8D4F30),
      connection_count,
      HIBYTE(v38),
      v38,
      v39,
      v40);
    if ( connection_count != 1 )
    {
      if ( connection_count == 3 )
      {
        v35 = wlan_reg_freq_to_band(HIDWORD(pm_conc_connection_list));
        v36 = wlan_reg_freq_to_band(HIDWORD(qword_8D4F0C));
        v37 = wlan_reg_freq_to_band(HIDWORD(qword_8D4F30));
        if ( v35 != v36 )
          goto LABEL_23;
        if ( v35 == v37 && HIBYTE(v38) )
        {
LABEL_20:
          v34 = 5;
LABEL_25:
          qdf_mutex_release(v11 + 56);
          result = v34;
          goto LABEL_26;
        }
        if ( v35 != v37 )
        {
LABEL_23:
          if ( !HIBYTE(v38) )
          {
            v34 = 2;
            goto LABEL_25;
          }
        }
      }
      else
      {
        if ( connection_count == 2 )
        {
          v31 = wlan_reg_freq_to_band(HIDWORD(pm_conc_connection_list));
          v32 = wlan_reg_freq_to_band(HIDWORD(qword_8D4F0C));
          if ( v32 != v31 || !HIBYTE(v38) )
          {
            if ( HIBYTE(v38) )
              v33 = 1;
            else
              v33 = (unsigned __int8)(v32 ^ v31) == 0;
            if ( v33 )
              v34 = 0;
            else
              v34 = 2;
            goto LABEL_25;
          }
          goto LABEL_20;
        }
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: unexpected num_connections value %d",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "policy_mgr_get_current_pref_hw_mode_dbs_1x1",
          connection_count);
      }
    }
    v34 = 0;
    goto LABEL_25;
  }
  v12 = "%s: policy_mgr_get_current_hw_mode failed";
LABEL_5:
  qdf_trace_msg(0x4Fu, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_get_current_pref_hw_mode_dbs_1x1");
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
