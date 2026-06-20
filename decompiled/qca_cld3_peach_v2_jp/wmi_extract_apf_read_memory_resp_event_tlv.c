__int64 __fastcall wmi_extract_apf_read_memory_resp_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  _DWORD *v11; // x8
  unsigned int v12; // w4

  if ( a10 )
  {
    v11 = *(_DWORD **)a10;
    *(_DWORD *)a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
    *(_DWORD *)(a11 + 4) = v11[2];
    *(_BYTE *)(a11 + 12) = v11[4] != 0;
    v12 = v11[3];
    if ( v12 <= *(_DWORD *)(a10 + 24) )
    {
      if ( v12 && *(_QWORD *)(a10 + 16) )
      {
        *(_DWORD *)(a11 + 8) = v12;
        *(_QWORD *)(a11 + 16) = *(_QWORD *)(a10 + 16);
        return 0;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: FW msg data_len %d more than TLV hdr %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "wmi_extract_apf_read_memory_resp_event_tlv");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: encrypt decrypt resp evt_buf is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wmi_extract_apf_read_memory_resp_event_tlv");
    return 4;
  }
}
