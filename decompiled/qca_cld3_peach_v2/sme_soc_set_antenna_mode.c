__int64 __fastcall sme_soc_set_antenna_mode(
        __int64 a1,
        unsigned __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 command_buffer; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int64 v30; // x5
  unsigned __int64 v31; // x9
  unsigned __int64 v32; // x8
  __int64 v33; // x20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  if ( a2 )
  {
    if ( (unsigned int)qdf_mutex_acquire(a1 + 12848) )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed to acquire lock",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "sme_soc_set_antenna_mode");
      return 1;
    }
    else
    {
      command_buffer = csr_get_command_buffer(a1);
      if ( command_buffer )
      {
        *(_DWORD *)(command_buffer + 16) = 262150;
        v30 = *a2;
        v31 = a2[1];
        v32 = a2[2];
        v33 = command_buffer;
        *(_QWORD *)(command_buffer + 48) = v32;
        *(_QWORD *)(command_buffer + 32) = v30;
        *(_QWORD *)(command_buffer + 40) = v31;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Antenna mode rx_chains: %d tx_chains: %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "sme_soc_set_antenna_mode",
          HIDWORD(v30));
        csr_queue_sme_command(a1, v33, 0);
        qdf_mutex_release(a1 + 12848);
        return 0;
      }
      else
      {
        qdf_mutex_release(a1 + 12848);
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Get command buffer failed",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "sme_soc_set_antenna_mode");
        return 29;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: antenna mode mesg is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_soc_set_antenna_mode");
    return 16;
  }
}
