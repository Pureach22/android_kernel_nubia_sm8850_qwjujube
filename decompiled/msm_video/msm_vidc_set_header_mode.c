__int64 __fastcall msm_vidc_set_header_mode(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a2 >= 0xC6 )
    __break(0x5512u);
  result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  _ReadStatusReg(SP_EL0);
  return result;
}
