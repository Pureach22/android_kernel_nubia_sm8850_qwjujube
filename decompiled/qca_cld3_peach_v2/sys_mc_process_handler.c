_QWORD *__fastcall sys_mc_process_handler(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w3
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *result; // x0
  _QWORD *v20; // x20
  __int64 (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x0
  __int64 (*v23)(void); // x8
  unsigned int v24; // w20

  if ( a1 )
  {
    v9 = *a1;
    if ( (__int16)a1[1] == -1330 )
    {
      if ( v9 == 3 )
      {
        v23 = *((__int64 (**)(void))a1 + 2);
        if ( v23 )
        {
          if ( *((_DWORD *)v23 - 1) != 1685785071 )
            __break(0x8228u);
          v24 = v23();
        }
        else
        {
          v24 = 0;
        }
        _qdf_mem_free(*((_QWORD *)a1 + 1));
        return (_QWORD *)v24;
      }
      else if ( v9 == 4 )
      {
        qdf_trace_msg(0x37u, 2u, "Processing SYS MC STOP", a2, a3, a4, a5, a6, a7, a8, a9);
        result = _cds_get_context(53, (__int64)"sys_mc_process_msg", v11, v12, v13, v14, v15, v16, v17, v18);
        if ( result )
        {
          v20 = result;
          sme_stop(result);
          mac_stop(v20);
          v21 = *((__int64 (__fastcall **)(_QWORD))a1 + 2);
          if ( *((_DWORD *)v21 - 1) != 1685785071 )
            __break(0x8228u);
          return (_QWORD *)v21(a1);
        }
      }
      else
      {
        qdf_trace_msg(0x37u, 2u, "Unknown message type msgType= %d [0x%08x]", a2, a3, a4, a5, a6, a7, a8, a9, *a1, *a1);
        return nullptr;
      }
    }
    else
    {
      qdf_trace_msg(0x37u, 2u, "Rx SYS unknown MC msgtype= %d [0x%08X]", a2, a3, a4, a5, a6, a7, a8, a9, *a1, *a1);
      v22 = *((_QWORD *)a1 + 1);
      if ( v22 )
        _qdf_mem_free(v22);
      return &off_0 + 7;
    }
  }
  else
  {
    qdf_trace_msg(
      0x37u,
      2u,
      "%s: NULL pointer to struct scheduler_msg",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "sys_mc_process_msg");
    return &off_0 + 4;
  }
  return result;
}
