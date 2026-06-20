__int64 __fastcall os_if_wfds_ipcc_map_n_cfg_ind_cb(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        _DWORD *a12)
{
  _ReadStatusReg(SP_EL0);
  if ( result && a11 )
  {
    if ( *a12 < 4u )
      result = ucfg_dp_wfds_handle_ipcc_map_n_cfg_ind();
    else
      result = qdf_trace_msg(
                 0x48u,
                 4u,
                 "%s: IPCC CE information array size %d exceeds max length",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "os_if_wfds_ipcc_map_n_cfg_ind_cb");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
