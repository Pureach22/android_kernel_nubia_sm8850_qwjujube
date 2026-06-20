__int64 __fastcall wma_vdev_nss_chain_params_send(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 *context; // x0
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_vdev_nss_chain_params_send", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
    result = wmi_unified_vdev_nss_chain_params_send(*context);
  else
    result = 16;
  _ReadStatusReg(SP_EL0);
  return result;
}
