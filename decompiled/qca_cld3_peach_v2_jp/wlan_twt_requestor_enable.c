__int64 __fastcall wlan_twt_requestor_enable(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  unsigned int v16; // w9
  char v17; // w8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  unsigned int v27; // w8
  const char *v28; // x2
  unsigned int v29; // w1
  __int64 result; // x0
  const char *v31; // x2
  __int64 v32; // x4
  __int64 v33; // x5
  char v34; // w7
  char v35; // w8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  _BYTE v44[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v45[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v46[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46[0] = 0;
  v45[0] = 0;
  v44[0] = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( !comp_private_obj )
  {
    v28 = "%s: null twt psoc priv obj";
    v29 = 2;
LABEL_8:
    qdf_trace_msg(0x96u, v29, v28, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_twt_requestor_enable");
    result = 16;
    goto LABEL_16;
  }
  v15 = comp_private_obj;
  wlan_twt_cfg_get_requestor(a1, v46);
  if ( (v46[0] & 1) == 0 )
  {
    v28 = "%s: twt requestor ini is not enabled";
    v29 = 3;
    goto LABEL_8;
  }
  *(_DWORD *)(v15 + 48) = 0;
  *(_QWORD *)(v15 + 56) = a3;
  wlan_twt_cfg_get_congestion_timeout(a1, a2 + 1);
  wlan_twt_cfg_get_bcast_requestor(a1, v45);
  v16 = v45[0];
  v17 = *((_BYTE *)a2 + 77) & 0xFE;
  a2[17] = 0;
  a2[18] = v16;
  *((_BYTE *)a2 + 77) = v17 | v16;
  wlan_twt_cfg_get_rtwt_requestor(a1, v44);
  if ( !a1 )
  {
    v31 = "%s: null psoc";
LABEL_11:
    qdf_trace_msg(0x96u, 2u, v31, v18, v19, v20, v21, v22, v23, v24, v25, "wlan_twt_tgt_caps_get_restricted_support");
    v27 = 0;
    goto LABEL_12;
  }
  v26 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( !v26 )
  {
    v31 = "%s: null twt psoc priv obj";
    goto LABEL_11;
  }
  v27 = *(unsigned __int8 *)(v26 + 29);
LABEL_12:
  v32 = *a2;
  v33 = a2[1];
  if ( v27 >= v44[0] )
    v34 = v44[0];
  else
    v34 = v27;
  v35 = *((_BYTE *)a2 + 77);
  *((_BYTE *)a2 + 78) = v34;
  qdf_trace_msg(
    0x96u,
    8u,
    "%s: TWT req enable: pdev_id:%d cong:%d bcast:%d rtwt:%d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wlan_twt_requestor_enable",
    v32,
    v33,
    v35 & 1);
  qdf_trace_msg(
    0x96u,
    8u,
    "%s: TWT req enable: role:%d ext:%d oper:%d",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "wlan_twt_requestor_enable",
    a2[17],
    *((unsigned __int8 *)a2 + 76),
    a2[18]);
  result = tgt_twt_enable_req_send(a1, a2);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
