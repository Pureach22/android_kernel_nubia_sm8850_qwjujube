_QWORD *__fastcall target_if_action_oui_register_tx_ops(
        _QWORD *result,
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

  if ( !result )
    return (_QWORD *)qdf_trace_msg(
                       0x49u,
                       2u,
                       "%s: action_oui tx_ops is null",
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       "target_if_action_oui_register_tx_ops",
                       v9,
                       v10);
  *result = target_if_action_oui_send_req;
  return result;
}
