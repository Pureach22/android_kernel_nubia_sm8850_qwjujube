__int64 __fastcall msm_vidc_set_slice_count(__int64 result)
{
  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(result + 16952) )
  {
    result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  }
  else if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_91E2F, "high", result + 340, "msm_vidc_set_slice_count", 0);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
