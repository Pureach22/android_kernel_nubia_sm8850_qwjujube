__int64 __fastcall msm_vidc_set_vui_timing_info(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  _BOOL4 v3; // [xsp+4h] [xbp-Ch]
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0xC6 )
    __break(0x5512u);
  v3 = *(_QWORD *)(a1 + 168LL * a2 + 4352) != 1;
  result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  _ReadStatusReg(SP_EL0);
  return result;
}
