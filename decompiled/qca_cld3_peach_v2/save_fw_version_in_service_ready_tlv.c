__int64 __fastcall save_fw_version_in_service_ready_tlv(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( *(_QWORD *)a2 )
  {
    qdf_mem_copy((void *)(a1 + 272), (const void *)(*(_QWORD *)a2 + 8LL), 0x18u);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: %s: wmi_buf_alloc failed",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "save_fw_version_in_service_ready_tlv",
      "save_fw_version_in_service_ready_tlv");
    return 16;
  }
}
