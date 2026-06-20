__int64 __fastcall cvp_create_pkt_cmd_sys_coverage_config(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    *(_DWORD *)(a1 + 16) = a2;
    *(_QWORD *)a1 = 0x110100600000014LL;
    *(_QWORD *)(a1 + 8) = 0x600000001LL;
    result = 0;
    if ( (msm_cvp_debug & 0x20) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_85873, &unk_96215, a2, a4);
      return 0;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8DCCF, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
