__int64 __fastcall send_mlo_link_removal_cmd_tlv(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w23
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _DWORD *v22; // x24
  __int64 v23; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x5
  unsigned int v42; // w19

  if ( a2 )
  {
    v12 = *((_DWORD *)a2 + 4) + 3;
    v13 = wmi_buf_alloc_fl(a1, (v12 & 0xFFFFFFFC) + 16, "send_mlo_link_removal_cmd_tlv", 0x4BAu);
    if ( v13 )
    {
      v22 = *(_DWORD **)(v13 + 224);
      v23 = v13;
      *v22 = 73662472;
      v22[1] = *a2;
      v22[2] = *((_DWORD *)a2 + 4);
      v22[3] = v12 & 0xFFFC | 0x110000;
      qdf_mem_copy(v22 + 4, *((const void **)a2 + 1), *((unsigned int *)a2 + 4));
      wmi_mtrace(0x48006u, v22[1], 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v23,
                 (v12 & 0xFFFFFFFC) + 16,
                 0x48006u,
                 "send_mlo_link_removal_cmd_tlv",
                 0x4D8u,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31);
      if ( (_DWORD)result )
      {
        v41 = *a2;
        v42 = result;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send MLO link removal cmd: psoc (%pK) vdev(%u)",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "send_mlo_link_removal_cmd_tlv",
          **(_QWORD **)(a1 + 760),
          v41);
        wmi_buf_free();
        return v42;
      }
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi buf alloc failed for link removal cmd: psoc (%pK) vdev(%u)",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "send_mlo_link_removal_cmd_tlv",
        **(_QWORD **)(a1 + 760),
        *a2);
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: command params is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_mlo_link_removal_cmd_tlv");
    return 29;
  }
  return result;
}
