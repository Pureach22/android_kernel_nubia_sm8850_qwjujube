__int64 __fastcall msm_vidc_set_conceal_color(__int64 a1, int a2)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a2 == 153 || a2 == 152 )
    result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  else
    result = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
