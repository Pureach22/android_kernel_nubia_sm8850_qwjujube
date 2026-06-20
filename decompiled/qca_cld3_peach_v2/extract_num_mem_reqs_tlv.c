__int64 __fastcall extract_num_mem_reqs_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _DWORD *a10)
{
  unsigned int v10; // w4

  if ( !*(_QWORD *)a10 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: %s: wmi_buf_alloc failed",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_num_mem_reqs_tlv",
      "extract_num_mem_reqs_tlv");
    return 0;
  }
  v10 = *(_DWORD *)(*(_QWORD *)a10 + 76LL);
  if ( v10 > a10[14] )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid num_mem_reqs %d:%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_num_mem_reqs_tlv");
    return 0;
  }
  return v10;
}
