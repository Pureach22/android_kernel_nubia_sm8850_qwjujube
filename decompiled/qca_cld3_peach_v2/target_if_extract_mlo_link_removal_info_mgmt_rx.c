__int64 __fastcall target_if_extract_mlo_link_removal_info_mgmt_rx(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w21

  if ( a3 )
  {
    v11 = *(int *)(a3 + 208);
    *(_QWORD *)(a3 + 200) = 0;
    if ( (_DWORD)v11 )
    {
      v15 = _qdf_mem_malloc(4 * v11, "target_if_extract_mlo_link_removal_info_mgmt_rx", 241);
      if ( v15 )
      {
        v24 = v15;
        result = wmi_extract_mgmt_rx_mlo_link_removal_info(a1, a2, v15, *(unsigned int *)(a3 + 208));
        if ( (_DWORD)result )
        {
          v34 = result;
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: Unable to extract link removal TLVs",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "target_if_extract_mlo_link_removal_info_mgmt_rx");
          *(_DWORD *)(a3 + 208) = 0;
          _qdf_mem_free(v24);
          return v34;
        }
        else
        {
          *(_QWORD *)(a3 + 200) = v24;
        }
      }
      else
      {
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Couldn't allocate memory for link_removal_info",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "target_if_extract_mlo_link_removal_info_mgmt_rx");
        *(_DWORD *)(a3 + 208) = 0;
        return 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: Link removal TLVs are not present",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "target_if_extract_mlo_link_removal_info_mgmt_rx");
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid rx_event",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_extract_mlo_link_removal_info_mgmt_rx");
    return 29;
  }
  return result;
}
