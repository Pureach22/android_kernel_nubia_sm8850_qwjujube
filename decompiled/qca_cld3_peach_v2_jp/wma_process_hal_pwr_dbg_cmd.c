__int64 __fastcall wma_process_hal_pwr_dbg_cmd(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: sir_pwr_dbg_params is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_process_hal_pwr_dbg_cmd");
    result = 4;
    goto LABEL_5;
  }
  if ( *(_DWORD *)(a2 + 8) <= 8u )
  {
    result = wmi_unified_send_power_dbg_cmd(*a1);
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return wma_vdev_nss_chain_params_send(a1, a2);
}
