__int64 __fastcall policy_mgr_is_restart_sap_required_with_mlo_sta(__int64 a1, int a2)
{
  _QWORD *context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  int v21; // w8
  int v22; // w8
  __int64 v23; // [xsp+0h] [xbp-30h] BYREF
  __int64 v24; // [xsp+8h] [xbp-28h] BYREF
  __int64 v25; // [xsp+10h] [xbp-20h] BYREF
  __int64 v26; // [xsp+18h] [xbp-18h]
  int v27; // [xsp+20h] [xbp-10h]
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v23) = 0;
  LOBYTE(v23) = 0;
  BYTE4(v24) = 0;
  LODWORD(v24) = 0;
  v27 = 0;
  v25 = 0;
  v26 = 0;
  context = (_QWORD *)policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_is_restart_sap_required_with_mlo_sta");
    result = 0;
    goto LABEL_14;
  }
  policy_mgr_get_ml_sta_info(context, (_BYTE *)&v23 + 4, &v23, (__int64)&v24, (__int64)&v25, nullptr, 0, 0);
  if ( BYTE4(v23) >= 6u )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: unexpected num_ml_sta %d ",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "policy_mgr_is_restart_sap_required_with_mlo_sta");
    result = 0;
    goto LABEL_14;
  }
  v21 = (unsigned __int8)v23;
  if ( BYTE4(v23) < (unsigned int)(unsigned __int8)v23 )
    v21 = 0;
  v22 = BYTE4(v23) - v21;
  if ( !v22 )
  {
LABEL_8:
    result = 0;
    goto LABEL_14;
  }
  result = 0;
  if ( (_DWORD)v25 != a2 && (unsigned __int8)v22 >= 2u && HIDWORD(v25) != a2 )
  {
    if ( (unsigned __int8)v22 != 2 )
    {
      if ( (_DWORD)v26 == a2 )
        goto LABEL_8;
      if ( (unsigned __int8)v22 != 3 )
      {
        if ( HIDWORD(v26) == a2 )
          goto LABEL_8;
        if ( (unsigned __int8)v22 != 4 )
        {
          if ( v27 == a2 )
            goto LABEL_8;
          if ( (unsigned __int8)v22 != 5 )
            __break(0x5512u);
        }
      }
    }
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: SAP is not SCC with any of active MLO STA link, restart SAP",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "policy_mgr_is_restart_sap_required_with_mlo_sta",
      v23,
      v24);
    result = 1;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
