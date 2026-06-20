__int64 __fastcall policy_mgr_sap_ch_width_update(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x24
  _DWORD *v20; // x10
  __int64 v21; // x1
  unsigned int v22; // w23
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w19
  const char *v33; // x2
  __int64 v34; // [xsp+0h] [xbp-10h] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v34) = 0;
  LODWORD(v34) = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v33 = "%s: Invalid Context";
LABEL_12:
    qdf_trace_msg(0x4Fu, 2u, v33, v11, v12, v13, v14, v15, v16, v17, v18, "policy_mgr_sap_ch_width_update", v34, v35);
    result = 16;
    goto LABEL_13;
  }
  v19 = comp_private_obj;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: action: %d reason: %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "policy_mgr_sap_ch_width_update",
    a2,
    a3);
  if ( !(unsigned int)policy_mgr_get_mode_specific_conn_info(a1, 0, &v34, 1) )
  {
    v33 = "%s: sap count is 0!";
    goto LABEL_12;
  }
  v20 = *(_DWORD **)(v19 + 456);
  v21 = (unsigned __int8)v34;
  if ( a2 == 16 )
    v22 = 3;
  else
    v22 = 7;
  if ( *(v20 - 1) != -587629941 )
    __break(0x822Au);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v20)(a1, v21, v22, a3, a4, a5);
  if ( (_DWORD)result )
  {
    v32 = result;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev %d failed to set BW to %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "policy_mgr_sap_ch_width_update",
      (unsigned __int8)v34,
      v22);
    result = v32;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
