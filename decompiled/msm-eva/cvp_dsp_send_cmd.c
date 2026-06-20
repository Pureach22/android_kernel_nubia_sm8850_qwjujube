__int64 __fastcall cvp_dsp_send_cmd(unsigned int *a1)
{
  __int64 result; // x0
  int v3; // w8
  void *v4; // x0
  unsigned __int64 v5; // x8
  unsigned __int64 StatusReg; // x8

  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    printk(&unk_852BB, "dsp", "cvp_dsp_send_cmd", *a1);
  if ( qword_6C660 && (unsigned __int64)qword_6C660 < 0xFFFFFFFFFFFFF001LL )
  {
    result = rpmsg_send(*(_QWORD *)(qword_6C660 + 968), a1, 108);
    if ( !(_DWORD)result )
      return result;
    v3 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_934B9, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v3 = msm_cvp_debug_out;
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) == 0 )
        return result;
    }
    else
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) == 0 )
        return result;
    }
    if ( !v3 )
    {
      v4 = &unk_8AD6E;
      v5 = _ReadStatusReg(SP_EL0);
LABEL_16:
      printk(v4, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v4 = &unk_8C10B;
      v5 = _ReadStatusReg(SP_EL0);
      goto LABEL_16;
    }
  }
  return result;
}
