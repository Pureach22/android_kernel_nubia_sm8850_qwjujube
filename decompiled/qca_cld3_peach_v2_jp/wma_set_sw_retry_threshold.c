__int64 __fastcall wma_set_sw_retry_threshold(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  result = wma_send_multi_pdev_vdev_set_params(0, a1, a2, a3, a4, a5, a6, a7, a8);
  _ReadStatusReg(SP_EL0);
  return result;
}
