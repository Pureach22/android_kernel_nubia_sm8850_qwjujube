void cvp_hyp_assign_from_dsp()
{
  unsigned __int64 StatusReg; // x8
  __int64 v1; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v2[2]; // [xsp+10h] [xbp-10h] BYREF

  v2[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = 1073741832;
  v2[0] = 0x700000003LL;
  if ( byte_6C670 == 1 )
  {
    if ( (unsigned int)qcom_scm_assign_mem(qword_6C678, (unsigned int)dword_6C680, &v1, v2, 1) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8D550, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
    }
    else
    {
      qword_6C678 = 0;
      dword_6C680 = 0;
      byte_6C670 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
}
