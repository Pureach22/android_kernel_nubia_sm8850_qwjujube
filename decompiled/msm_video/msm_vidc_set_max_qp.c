__int64 __fastcall msm_vidc_set_max_qp(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v3; // x0

  _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(result + 9912) & 0x10) != 0
    || (*(_DWORD *)(result + 27384) >> 3) & 2
     | (*(_DWORD *)(result + 27216) >> 4) & 1
     | (*(_DWORD *)(result + 27552) >> 2) & 4 )
  {
    result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  }
  else if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v2 = result;
      v3 = cap_name(a2);
      printk(&unk_9518A, "high", v2 + 340, "msm_vidc_set_max_qp", v3);
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
