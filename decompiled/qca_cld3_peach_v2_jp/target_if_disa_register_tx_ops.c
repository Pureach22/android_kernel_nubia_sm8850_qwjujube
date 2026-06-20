__int64 (__fastcall **__fastcall target_if_disa_register_tx_ops(
        __int64 (__fastcall **result)(__int64 a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9),
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9))(__int64 a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( !result )
    return (__int64 (__fastcall **)(__int64, double, double, double, double, double, double, double, double))qdf_trace_msg(0x49u, 2u, "%s: disa_tx_ops is null", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_disa_register_tx_ops", v9, v10);
  *result = target_if_disa_encrypt_decrypt_req;
  result[1] = target_if_disa_register_ev_handlers;
  result[2] = target_if_disa_unregister_ev_handlers;
  return result;
}
