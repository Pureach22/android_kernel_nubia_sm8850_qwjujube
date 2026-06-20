__int64 __fastcall wlan_twt_responder_enable(__int64 a1, unsigned int *a2, __int64 a3)
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
  unsigned int v16; // w5
  __int64 v17; // x4
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  const char *v35; // x2
  unsigned int v36; // w1
  __int64 v37; // [xsp+0h] [xbp-10h] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v37) = 0;
  LOBYTE(v37) = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( !comp_private_obj )
  {
    v35 = "%s: null twt psoc priv obj";
    v36 = 2;
LABEL_6:
    qdf_trace_msg(0x96u, v36, v35, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_twt_responder_enable", v37, v38);
    result = 16;
    goto LABEL_7;
  }
  v15 = comp_private_obj;
  wlan_twt_cfg_get_responder(a1, (char *)&v37 + 4);
  if ( !BYTE4(v37) )
  {
    v35 = "%s: twt responder ini is not enabled";
    v36 = 3;
    goto LABEL_6;
  }
  *(_DWORD *)(v15 + 48) = 1;
  *(_QWORD *)(v15 + 56) = a3;
  wlan_twt_cfg_get_bcast_responder(a1, &v37);
  v16 = (unsigned __int8)v37;
  v17 = *a2;
  *((_BYTE *)a2 + 77) = *((_BYTE *)a2 + 77) & 0xFE | v37;
  a2[17] = 1;
  a2[18] = v16;
  qdf_trace_msg(
    0x96u,
    8u,
    "%s: TWT res enable: mac_id:%d bcast:%d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wlan_twt_responder_enable",
    v17);
  qdf_trace_msg(
    0x96u,
    8u,
    "%s: TWT res enable: role:%d ext:%d oper:%d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_twt_responder_enable",
    a2[17],
    *((unsigned __int8 *)a2 + 76),
    a2[18]);
  result = tgt_twt_enable_req_send(a1, a2);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
