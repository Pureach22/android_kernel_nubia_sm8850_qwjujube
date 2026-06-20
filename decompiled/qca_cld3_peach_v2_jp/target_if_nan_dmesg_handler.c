__int64 __fastcall target_if_nan_dmesg_handler(__int64 a1, __int64 a2)
{
  __int64 psoc_from_scn_hdl; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x0
  unsigned int nan_msg; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  const char *v24; // x2
  const char *v25; // x2
  __int64 result; // x0
  __int64 v27; // [xsp+8h] [xbp-18h] BYREF
  __int64 v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v25 = "%s: psoc is null";
    goto LABEL_9;
  }
  v12 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 16)) == 0 )
  {
    v25 = "%s: wmi_handle is null";
LABEL_9:
    qdf_trace_msg(0x49u, 2u, v25, v4, v5, v6, v7, v8, v9, v10, v11, "target_if_nan_dmesg_handler");
    goto LABEL_10;
  }
  nan_msg = wmi_extract_nan_msg(v13, a2, (__int64)&v27);
  if ( nan_msg )
  {
    v23 = nan_msg;
    v24 = "%s: parsing of event failed, %d";
  }
  else
  {
    if ( v27 )
    {
      qdf_trace_msg(0x49u, 4u, "%s: %s", v15, v16, v17, v18, v19, v20, v21, v22, "target_if_nan_dmesg_handler");
      result = 0;
      goto LABEL_11;
    }
    v23 = (unsigned int)v28;
    v24 = "%s: msg not present %d";
  }
  qdf_trace_msg(0x49u, 2u, v24, v15, v16, v17, v18, v19, v20, v21, v22, "target_if_nan_dmesg_handler", v23);
LABEL_10:
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
