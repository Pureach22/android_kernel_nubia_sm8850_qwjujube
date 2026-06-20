__int64 __fastcall wma_send_apf_write_work_memory_cmd(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v22; // x2

  if ( !(unsigned int)_wma_validate_handle(a1, "wma_send_apf_write_work_memory_cmd") )
  {
    v12 = *(_QWORD *)a1;
    if ( !(unsigned int)_wmi_validate_handle(
                          *(_QWORD *)a1,
                          (__int64)"wma_send_apf_write_work_memory_cmd",
                          v4,
                          v5,
                          v6,
                          v7,
                          v8,
                          v9,
                          v10,
                          v11) )
    {
      if ( (*(_BYTE *)(a1 + 280) & 8) != 0 )
      {
        if ( !(unsigned int)wmi_unified_send_apf_write_work_memory_cmd(v12) )
        {
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Sent APF write mem on vdevid: %d",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "wma_send_apf_write_work_memory_cmd",
            *a2);
          return 0;
        }
        v22 = "%s: Failed to send APF write mem command";
      }
      else
      {
        v22 = "%s: APF cababilities feature bit not enabled";
      }
      qdf_trace_msg(0x36u, 2u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "wma_send_apf_write_work_memory_cmd");
      return 16;
    }
  }
  return 4;
}
