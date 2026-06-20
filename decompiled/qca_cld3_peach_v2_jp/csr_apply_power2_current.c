__int64 __fastcall csr_apply_power2_current(
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
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Updating Cfg with power settings",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "csr_apply_power2_current");
  csr_save_tx_power_to_cfg(a1, a1 + 16936, 1);
  return csr_save_tx_power_to_cfg(a1, a1 + 17024, 2);
}
