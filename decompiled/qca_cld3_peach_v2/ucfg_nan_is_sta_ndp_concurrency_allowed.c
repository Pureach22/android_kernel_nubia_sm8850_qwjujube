__int64 __fastcall ucfg_nan_is_sta_ndp_concurrency_allowed(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  const char *v13; // x3
  char v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int mode_specific_conn_info; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  __int64 comp_private_obj; // x0
  unsigned int conc_ext_flags; // w0
  int v36; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int8 v37; // [xsp+Ch] [xbp-24h]
  _QWORD v38[2]; // [xsp+10h] [xbp-20h] BYREF
  int v39; // [xsp+20h] [xbp-10h]
  __int64 v40; // [xsp+28h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v36 = 0;
  v39 = 0;
  v38[0] = 0;
  v38[1] = 0;
  if ( (nan_is_sta_sta_concurrency_present(a1) & 1) == 0 )
  {
    if ( (policy_mgr_is_mlo_sta_present(a1) & 1) != 0
      && (wlan_is_mlo_sta_nan_ndi_allowed(a1, v15, v16, v17, v18, v19, v20, v21, v22) & 1) == 0 )
    {
      goto LABEL_4;
    }
    mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(
                                a1,
                                (unsigned __int64)v38,
                                (unsigned __int64)&v36,
                                4u);
    if ( !mode_specific_conn_info || (v32 = *(unsigned __int8 *)(a2 + 168), v32 == (unsigned __int8)v36) )
    {
LABEL_9:
      v14 = 1;
      goto LABEL_10;
    }
    if ( mode_specific_conn_info == 1 )
      goto LABEL_12;
    if ( v32 == BYTE1(v36) )
      goto LABEL_9;
    if ( mode_specific_conn_info == 2 )
      goto LABEL_12;
    if ( v32 == BYTE2(v36) )
      goto LABEL_9;
    if ( mode_specific_conn_info == 3 )
      goto LABEL_12;
    if ( v32 == HIBYTE(v36) )
      goto LABEL_9;
    if ( mode_specific_conn_info == 4 )
      goto LABEL_12;
    if ( v32 == v37 )
      goto LABEL_9;
    if ( mode_specific_conn_info == 5 )
    {
LABEL_12:
      if ( a1 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
        if ( comp_private_obj )
        {
          if ( (*(_WORD *)(comp_private_obj + 232) & 0x40) != 0 )
          {
            conc_ext_flags = policy_mgr_get_conc_ext_flags(a2, 0, v4, v5, v6, v7, v8, v9, v10, v11);
            v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
                    a1,
                    4,
                    0,
                    3,
                    conc_ext_flags,
                    *(unsigned __int8 *)(a2 + 168));
            goto LABEL_10;
          }
          goto LABEL_4;
        }
        goto LABEL_26;
      }
    }
    else
    {
      __break(0x5512u);
    }
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", v24, v25, v26, v27, v28, v29, v30, v31, "nan_get_psoc_priv_obj");
LABEL_26:
    v12 = "%s: psoc_nan_obj is null";
    v13 = "ucfg_nan_is_sta_nan_ndi_4_port_allowed";
    goto LABEL_3;
  }
  v12 = "%s: STA+STA+NDP concurrency is not allowed";
  v13 = "ucfg_nan_is_sta_ndp_concurrency_allowed";
LABEL_3:
  qdf_trace_msg(0x53u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, v13);
LABEL_4:
  v14 = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v14 & 1;
}
