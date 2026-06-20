__int64 __fastcall ucfg_dp_register_rx_mic_error_ind_handler(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8

  if ( !result )
    return qdf_trace_msg(
             0x45u,
             1u,
             "%s invalid instance",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "cdp_register_rx_mic_error_ind_handler",
             v9,
             v10);
  v11 = *(_QWORD *)(result + 8);
  if ( !v11 )
    return qdf_trace_msg(
             0x45u,
             1u,
             "%s invalid instance",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "cdp_register_rx_mic_error_ind_handler",
             v9,
             v10);
  *(_QWORD *)(v11 + 120) = dp_rx_mic_error_ind;
  return result;
}
