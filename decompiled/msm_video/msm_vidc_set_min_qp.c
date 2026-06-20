__int64 __fastcall msm_vidc_set_min_qp(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v3; // x0

  _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(result + 9744) & 0x10) != 0
    || (*(_DWORD *)(result + 26880) >> 3) & 2
     | (*(_DWORD *)(result + 26712) >> 4) & 1
     | (*(_DWORD *)(result + 27048) >> 2) & 4 )
  {
    result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  }
  else if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v2 = result;
      v3 = cap_name(a2);
      printk(&unk_8A46D, "high", v2 + 340, "msm_vidc_set_min_qp", v3);
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
