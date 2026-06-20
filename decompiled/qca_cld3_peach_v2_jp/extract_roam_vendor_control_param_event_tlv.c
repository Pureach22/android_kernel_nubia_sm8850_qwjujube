__int64 __fastcall extract_roam_vendor_control_param_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        unsigned int a11,
        _QWORD *a12)
{
  __int64 v12; // x21
  const char *v13; // x2
  unsigned int v14; // w1
  unsigned int v16; // w19
  __int64 v17; // x22
  _DWORD *v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _DWORD *v27; // x20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _DWORD *v36; // x27
  int *v37; // x26
  unsigned int v38; // w25
  int v39; // w4
  int v40; // t1
  unsigned int v41; // w8

  if ( !a10 || !a11 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Empty roam vendor control param event",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_vendor_control_param_event_tlv");
    return 16;
  }
  v12 = *a10;
  if ( !*a10 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: received null event data from target",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_vendor_control_param_event_tlv");
    return 4;
  }
  if ( *(_DWORD *)(v12 + 4) >= 6u )
  {
    v13 = "%s: Invalid VDEV id %d";
    v14 = 8;
LABEL_10:
    qdf_trace_msg(0x31u, v14, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_roam_vendor_control_param_event_tlv");
    return 16;
  }
  v16 = *((_DWORD *)a10 + 6);
  if ( 12 * (unsigned __int64)v16 + 16 > a11 )
  {
    v14 = 2;
    v13 = "%s: Invalid length: %d";
    goto LABEL_10;
  }
  v17 = a10[2];
  v18 = (_DWORD *)_qdf_mem_malloc(0x48u, "extract_roam_vendor_control_param_event_tlv", 3715);
  if ( !v18 )
    return 16;
  v27 = v18;
  *v18 = *(_DWORD *)(v12 + 4);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id:%d, num_tlv:%d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "extract_roam_vendor_control_param_event_tlv");
  if ( v16 )
  {
    v36 = v27 + 3;
    v37 = (int *)(v17 + 8);
    v38 = v16;
    do
    {
      v41 = *(v37 - 1) + 1;
      if ( v41 < 0xA && ((0x3FDu >> v41) & 1) != 0 )
      {
        v39 = dword_A2EA38[v41];
      }
      else
      {
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: Invalid param id",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "convert_wmi_roam_vendor_control_param");
        v39 = 0;
      }
      *(v36 - 1) = v39;
      v40 = *v37;
      v37 += 3;
      *v36 = v40;
      v36 += 2;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: param_info->param_id:%d, param_info->param_value:%d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "extract_roam_vendor_control_param_event_tlv");
      --v38;
    }
    while ( v38 );
  }
  v27[1] = v16;
  *a12 = v27;
  return 0;
}
