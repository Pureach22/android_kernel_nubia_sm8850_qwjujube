__int64 __fastcall target_if_pmo_send_pkt_filter_req(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x19
  unsigned int v13; // w19
  const char *v14; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 152);
    if ( v9 && (v10 = *(_QWORD *)(v9 + 80)) != 0 )
    {
      v11 = *(_QWORD *)(v10 + 2800);
      if ( v11 && (v12 = *(_QWORD *)(v11 + 16)) != 0 )
      {
        if ( (unsigned int)wmi_unified_config_packet_filter_cmd(*(_QWORD *)(v11 + 16)) )
        {
          v13 = 4;
          v14 = "%s: Failed to send pkt_filter cmd";
        }
        else
        {
          v13 = wmi_unified_enable_disable_packet_filter_cmd(v12);
          if ( !v13 )
            return v13;
          v14 = "%s: Failed to send packet filter wmi cmd to fw";
        }
      }
      else
      {
        v13 = 4;
        v14 = "%s: Invalid wmi handle";
      }
    }
    else
    {
      v13 = 4;
      v14 = "%s: psoc handle is NULL";
    }
  }
  else
  {
    v13 = 4;
    v14 = "%s: vdev ptr passed is NULL";
  }
  qdf_trace_msg(0x49u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_pmo_send_pkt_filter_req");
  return v13;
}
