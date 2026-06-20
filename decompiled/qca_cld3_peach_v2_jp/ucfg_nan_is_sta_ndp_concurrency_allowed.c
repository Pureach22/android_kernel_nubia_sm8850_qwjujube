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
  int mode_specific_conn_info; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  __int64 comp_private_obj; // x0
  int v27; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int8 v28; // [xsp+Ch] [xbp-24h]
  _QWORD v29[2]; // [xsp+10h] [xbp-20h] BYREF
  int v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v27 = 0;
  v30 = 0;
  v29[0] = 0;
  v29[1] = 0;
  if ( nan_is_sta_sta_concurrency_present(a1) )
  {
    v12 = "%s: STA+STA+NDP concurrency is not allowed";
    v13 = "ucfg_nan_is_sta_ndp_concurrency_allowed";
LABEL_3:
    qdf_trace_msg(0x53u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, v13);
    v14 = 0;
    goto LABEL_7;
  }
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(
                              a1,
                              (unsigned __int64)v29,
                              (unsigned __int64)&v27,
                              4u);
  if ( !mode_specific_conn_info || (v24 = *(unsigned __int8 *)(a2 + 104), v24 == (unsigned __int8)v27) )
  {
LABEL_6:
    v14 = 1;
    goto LABEL_7;
  }
  if ( mode_specific_conn_info != 1 )
  {
    if ( v24 == BYTE1(v27) )
      goto LABEL_6;
    if ( mode_specific_conn_info != 2 )
    {
      if ( v24 == BYTE2(v27) )
        goto LABEL_6;
      if ( mode_specific_conn_info != 3 )
      {
        if ( v24 == HIBYTE(v27) )
          goto LABEL_6;
        if ( mode_specific_conn_info != 4 )
        {
          if ( v24 == v28 )
            goto LABEL_6;
          if ( mode_specific_conn_info != 5 )
          {
            __break(0x5512u);
            goto LABEL_22;
          }
        }
      }
    }
  }
  if ( !a1 )
  {
LABEL_22:
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", v16, v17, v18, v19, v20, v21, v22, v23, "nan_get_psoc_priv_obj");
    goto LABEL_23;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_23:
    v12 = "%s: psoc_nan_obj is null";
    v13 = "ucfg_nan_is_sta_nan_ndi_4_port_allowed";
    goto LABEL_3;
  }
  if ( (*(_WORD *)(comp_private_obj + 232) & 0x40) != 0 )
    v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
            a1,
            4,
            0,
            3,
            0,
            *(unsigned __int8 *)(a2 + 104));
  else
    v14 = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v14 & 1;
}
