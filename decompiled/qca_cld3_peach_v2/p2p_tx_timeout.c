__int64 __fastcall p2p_tx_timeout(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  _QWORD *v19; // x23
  int v20; // w22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  _QWORD *v37[2]; // [xsp+0h] [xbp-10h] BYREF

  v37[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = nullptr;
  qdf_trace_msg(0x4Eu, 4u, "%s: pdata:%pK", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_tx_timeout", a1);
  if ( a1 )
  {
    result = qdf_list_peek_front((_QWORD *)(a1 + 56), v37);
    if ( !(_DWORD)result )
    {
      do
      {
        v19 = v37[0];
        v20 = qdf_list_peek_next((_QWORD *)(a1 + 56), v37[0], v37);
        result = qdf_mc_timer_get_current_state((__int64)(v19 + 9));
        if ( (_DWORD)result == 19 )
        {
          if ( (unsigned int)qdf_list_remove_node(a1 + 56, v19) )
          {
            result = qdf_trace_msg(
                       0x4Eu,
                       2u,
                       "%s: remove %pK from roc_q fail",
                       v21,
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       "p2p_tx_timeout",
                       v19);
          }
          else
          {
            qdf_mc_timer_destroy((__int64)(v19 + 9));
            p2p_send_tx_conf((__int64)v19, 0, v29, v30, v31, v32, v33, v34, v35, v36);
            _qdf_mem_free(v19[6]);
            result = _qdf_mem_free((__int64)v19);
          }
        }
      }
      while ( !v20 );
    }
  }
  else
  {
    result = qdf_trace_msg(0x4Eu, 2u, "%s: null p2p soc obj", v10, v11, v12, v13, v14, v15, v16, v17, "p2p_tx_timeout");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
