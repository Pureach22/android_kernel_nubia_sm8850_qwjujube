__int64 __fastcall wma_process_tx_power_limits(
        __int64 *a1,
        _DWORD *a2,
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
  __int64 result; // x0
  int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w19

  _ReadStatusReg(SP_EL0);
  if ( (unsigned int)_wma_validate_handle(
                       (__int64)a1,
                       (__int64)"wma_process_tx_power_limits",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10) )
  {
    result = 4;
  }
  else
  {
    v21 = _wmi_validate_handle(*a1, (__int64)"wma_process_tx_power_limits", v12, v13, v14, v15, v16, v17, v18, v19);
    result = 4;
    if ( !v21 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: txpower2g: %x txpower5g: %x",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_process_tx_power_limits",
        *a2 | 0x100u,
        a2[1] | 0x100u);
      result = wma_send_multi_pdev_vdev_set_params(0, v30, v31, v32, v33, v34, v35, v36, v37);
      if ( (_DWORD)result )
      {
        v46 = result;
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: failed to send tx power pdev set params",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wma_process_tx_power_limits");
        result = v46;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
