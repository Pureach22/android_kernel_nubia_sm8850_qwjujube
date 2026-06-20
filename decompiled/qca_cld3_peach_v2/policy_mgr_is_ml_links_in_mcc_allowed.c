__int64 __fastcall policy_mgr_is_ml_links_in_mcc_allowed(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4)
{
  _QWORD *context; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w4
  const char *v25; // x2
  unsigned int v26; // w1
  __int64 result; // x0
  unsigned __int8 mode_specific_conn_info; // w20
  unsigned __int8 v29; // w21
  _BYTE v30[4]; // [xsp+Ch] [xbp-44h] BYREF
  int v31; // [xsp+10h] [xbp-40h] BYREF
  char v32; // [xsp+14h] [xbp-3Ch]
  _QWORD v33[2]; // [xsp+18h] [xbp-38h] BYREF
  int v34; // [xsp+28h] [xbp-28h]
  _QWORD v35[2]; // [xsp+30h] [xbp-20h] BYREF
  int v36; // [xsp+40h] [xbp-10h]
  __int64 v37; // [xsp+48h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30[0] = 0;
  v36 = 0;
  v35[0] = 0;
  v35[1] = 0;
  v34 = 0;
  v33[0] = 0;
  v33[1] = 0;
  v32 = 0;
  v31 = 0;
  context = (_QWORD *)policy_mgr_get_context(a1);
  if ( !context )
  {
    v25 = "%s: Invalid Context";
    v26 = 2;
LABEL_5:
    qdf_trace_msg(0x4Fu, v26, v25, v8, v9, v10, v11, v12, v13, v14, v15, "policy_mgr_is_ml_links_in_mcc_allowed");
    goto LABEL_6;
  }
  policy_mgr_get_ml_sta_info(context, a4, v30, a3, (__int64)v35, nullptr, 0, 0);
  v24 = (unsigned __int8)*a4;
  if ( v24 < 2 || v24 > 5 || v30[0] )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: num_ml_sta invalid %d or link already disabled%d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_is_ml_links_in_mcc_allowed");
  }
  else
  {
    if ( (policy_mgr_is_ml_sta_links_in_mcc(a1, (__int64)v35, a3, 0, v24, nullptr) & 1) == 0 )
      goto LABEL_6;
    if ( (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) != 0 )
    {
      v25 = "%s: Don't disable eMLSR links";
      v26 = 8;
      goto LABEL_5;
    }
    mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(
                                a1,
                                (unsigned __int64)v33,
                                (unsigned __int64)&v31,
                                3u);
    v29 = policy_mgr_get_mode_specific_conn_info(a1, (unsigned __int64)v33, (unsigned __int64)&v31, 2u);
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 || !(v29 | mode_specific_conn_info) )
    {
      result = 0;
      goto LABEL_7;
    }
  }
LABEL_6:
  result = 16;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
