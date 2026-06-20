__int64 __fastcall msm_cvp_session_init(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v3; // x19
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
    {
      v3 = a1;
      printk(&unk_8DE2C, "sess", "msm_cvp_session_init", a1);
      a1 = v3;
    }
    v1 = 0;
    *(_QWORD *)(a1 + 14056) = 1000;
    *(_QWORD *)(a1 + 14072) = 0x3E8000003E8LL;
    *(_QWORD *)(a1 + 14828) = 0xFFFFFFFF00000001LL;
    *(_QWORD *)(a1 + 14836) = 0;
    *(_DWORD *)(a1 + 14844) = 0;
    *(_DWORD *)(a1 + 14852) = 3;
  }
  else
  {
    v1 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_912BD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return (unsigned int)-22;
    }
  }
  return v1;
}
