__int64 msm_vidc_set_apv_level_band()
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  _ReadStatusReg(SP_EL0);
  return result;
}
