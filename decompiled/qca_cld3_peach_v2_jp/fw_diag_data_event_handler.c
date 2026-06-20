__int64 __fastcall fw_diag_data_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned int v10; // w8
  _DWORD *v11; // x0
  unsigned __int64 v12; // x1
  bool v13; // cf

  if ( a10 )
  {
    v10 = *(_DWORD *)(a10 + 24);
    if ( v10 >= 0xC )
    {
      v11 = *(_DWORD **)(a10 + 16);
      while ( 1 )
      {
        v12 = ((unsigned __int64)(unsigned int)*v11 >> 16) + 12;
        v13 = v10 >= (unsigned int)v12;
        v10 -= v12;
        if ( !v13 )
          break;
        if ( (unsigned __int8)*v11 < 2u )
          return send_fw_diag_nl_data();
        v11 = (_DWORD *)((char *)v11 + v12);
        if ( v10 <= 0xB )
          return 0;
      }
      if ( (dword_17AC4 & 4) != 0 )
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: processed all the messages\n",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "process_fw_diag_event_data");
    }
    return 0;
  }
  else
  {
    if ( (dword_17AC4 & 1) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Got NULL point message from FW\n",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "fw_diag_data_event_handler");
    return 0xFFFFFFFFLL;
  }
}
