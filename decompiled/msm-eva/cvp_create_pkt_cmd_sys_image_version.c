__int64 __fastcall cvp_create_pkt_cmd_sys_image_version(_QWORD *a1)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    *a1 = 0x110100700000010LL;
    a1[1] = 0xB00000001LL;
    return 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_96F32, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
