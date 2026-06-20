__int64 __fastcall target_if_send_link_reconfig_req_cmd(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x20
  int v22; // w9
  char v23; // w9
  char v24; // w9
  char v25; // w9
  void *v26; // x0
  __int64 result; // x0
  _QWORD v28[31]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v29; // [xsp+100h] [xbp-10h]
  __int64 v30; // [xsp+108h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  memset(v28, 0, sizeof(v28));
  if ( !a1 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: null psoc", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_send_link_reconfig_req_cmd");
    result = 29;
    goto LABEL_15;
  }
  qdf_trace_msg(0x49u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_send_link_reconfig_req_cmd");
  v20 = *(_QWORD *)(a1 + 2800);
  if ( !v20 || (v21 = *(_QWORD *)(v20 + 16)) == 0 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: null handle",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_send_link_reconfig_req_cmd");
    result = 16;
    goto LABEL_15;
  }
  qdf_mem_set(v28, 0x100u, 0);
  LOBYTE(v28[0]) = *a2;
  qdf_mem_copy((char *)v28 + 1, a2 + 552, 6u);
  v22 = (unsigned __int8)a2[128];
  LOBYTE(v28[1]) = -1;
  LODWORD(v28[16]) = v22;
  if ( !v22 )
    goto LABEL_19;
  v23 = a2[8];
  HIBYTE(v28[0]) = a2[9];
  LOBYTE(v28[1]) = v23;
  qdf_mem_copy((char *)&v28[1] + 1, a2 + 16, 6u);
  if ( LODWORD(v28[16]) <= 1 )
    goto LABEL_19;
  v24 = a2[48];
  HIBYTE(v28[1]) = a2[49];
  LOBYTE(v28[2]) = v24;
  qdf_mem_copy((char *)&v28[2] + 1, a2 + 56, 6u);
  if ( LODWORD(v28[16]) < 3
    || (v25 = a2[88],
        HIBYTE(v28[2]) = a2[89],
        LOBYTE(v28[3]) = v25,
        v26 = qdf_mem_copy((char *)&v28[3] + 1, a2 + 96, 6u),
        LODWORD(v28[16]) <= 3) )
  {
LABEL_19:
    HIDWORD(v29) = (unsigned __int8)a2[256];
    if ( !HIDWORD(v29)
      || (BYTE4(v28[16]) = a2[137], qdf_mem_copy((char *)&v28[16] + 6, a2 + 144, 6u), HIDWORD(v29) < 2)
      || (BYTE4(v28[17]) = a2[177], qdf_mem_copy((char *)&v28[17] + 6, a2 + 184, 6u), HIDWORD(v29) < 3)
      || (BYTE4(v28[18]) = a2[217], v26 = qdf_mem_copy((char *)&v28[18] + 6, a2 + 224, 6u), HIDWORD(v29) <= 3) )
    {
      result = wmi_send_link_reconfig_req_cmd(v21, v28);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  __break(0x5512u);
  return target_if_mlo_register_tx_ops(v26);
}
