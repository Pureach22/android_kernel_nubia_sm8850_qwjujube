__int64 __fastcall send_action_oui_cmd_tlv(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  unsigned int v11; // w22
  __int64 v12; // x8
  unsigned int v14; // w23
  int v16; // w9
  __int64 v17; // x25
  int v18; // w24
  unsigned int *v19; // x10
  int v20; // w11
  __int64 v21; // x0
  const char *v22; // x2
  __int64 result; // x0
  int v24; // w28
  unsigned int v25; // w26
  __int64 v26; // x0
  __int64 v27; // x3
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _DWORD *v36; // x8
  __int64 v37; // x21
  __int64 v38; // x1
  int v39; // w8
  _BYTE *v40; // x9
  int v41; // w11
  _DWORD *v42; // x12
  int v43; // w14
  int v44; // w15
  int v45; // w16
  int v46; // w0
  int v47; // w17
  int v48; // w2
  int v49; // w13
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7

  if ( !a2 )
  {
    v22 = "%s: action oui is empty";
LABEL_16:
    qdf_trace_msg(0x31u, 2u, v22, a3, a4, a5, a6, a7, a8, a9, a10, "send_action_oui_cmd_tlv");
    return 4;
  }
  v10 = a2[2];
  if ( (unsigned int)v10 > 0xA || (v11 = a2[3], v11 >= 0xBF) )
  {
    v22 = "%s: Invalid number of action oui extensions";
    goto LABEL_16;
  }
  v12 = *a2;
  if ( (unsigned int)v12 >= 0x13 || ((0x73FFFu >> v12) & 1) == 0 )
  {
    v22 = "%s: Invalid action id";
    goto LABEL_16;
  }
  v14 = dword_A2D718[v12];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: wmi action_id %d num %d total_num %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "send_action_oui_cmd_tlv",
    v14,
    (unsigned int)v10,
    v11);
  v16 = 0;
  v17 = 28 * v10;
  v18 = 28 * v10 + 24;
  if ( (_DWORD)v10 )
  {
    v19 = a2 + 10;
    v20 = v10;
    v21 = a1;
    do
    {
      v16 += *(v19 - 5) + *(v19 - 4) + *(v19 - 3) + *(v19 - 2) + *(v19 - 1) + *v19;
      if ( *((_BYTE *)a2 + 4) && !*((_BYTE *)v19 + 40) )
        ++v16;
      --v20;
      v19 += 17;
    }
    while ( v20 );
  }
  else
  {
    v21 = a1;
  }
  v24 = v16 + v10 + 3;
  v25 = v24 & 0xFFFFFFFC;
  v26 = wmi_buf_alloc_fl(v21, v18 + (v24 & 0xFFFFFFFC), "send_action_oui_cmd_tlv", 0x144u);
  if ( !v26 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to allocate wmi buffer",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "send_action_oui_cmd_tlv");
    return 16;
  }
  v36 = *(_DWORD **)(v26 + 224);
  v37 = v26;
  *v36 = 44957708;
  v36[1] = v14;
  v38 = (__int64)(v36 + 5);
  v36[2] = v11;
  v36[3] = v10;
  v36[4] = v17 | 0x120000;
  if ( (_DWORD)v10 )
  {
    v39 = *((unsigned __int8 *)a2 + 4);
    v40 = a2 + 20;
    v41 = v10;
    v42 = (_DWORD *)v38;
    do
    {
      *v42 = 45023256;
      v42[2] = *((_DWORD *)v40 - 16) & 0x3F;
      v42[3] = *((_DWORD *)v40 - 15);
      v42[4] = *((_DWORD *)v40 - 14);
      v42[5] = *((_DWORD *)v40 - 12);
      v49 = *((_DWORD *)v40 - 10);
      v42[6] = v49;
      if ( !v39 || *v40 )
        v43 = 1;
      else
        v43 = 2;
      v44 = *((_DWORD *)v40 - 15);
      v45 = *((_DWORD *)v40 - 14);
      v47 = *((_DWORD *)v40 - 13);
      v46 = *((_DWORD *)v40 - 12);
      v48 = *((_DWORD *)v40 - 11);
      --v41;
      v40 += 68;
      v42[1] = v44 + v49 + v45 + v47 + v46 + v48 + v43;
      v42 += 7;
    }
    while ( v41 );
  }
  *(_DWORD *)(v38 + 28 * v10) = v24 & 0xFFFC | 0x110000;
  wmi_fill_oui_extensions_buffer((__int64)(a2 + 4), v38, v10, v27, (char *)(v38 + v17 + 4), *((_BYTE *)a2 + 4));
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: wmi len %d data:",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "send_action_oui_cmd_tlv",
    v18 + v25);
  v58 = ((double (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
          49,
          9,
          *(_QWORD *)(v37 + 224),
          v18 + v25);
  result = wmi_unified_cmd_send_fl(
             a1,
             v37,
             v18 + v25,
             0x4031u,
             "send_action_oui_cmd_tlv",
             0x171u,
             v58,
             v59,
             v60,
             v61,
             v62,
             v63,
             v64,
             v65);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: WMI_PDEV_CONFIG_VENDOR_OUI_ACTION send fail",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "send_action_oui_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
