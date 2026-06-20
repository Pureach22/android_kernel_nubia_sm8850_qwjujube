void __fastcall _dsp_resume(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x3
  unsigned __int64 StatusReg; // x8

  if ( (msm_cvp_dsp_disable & 1) == 0 )
  {
    if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
      printk(&unk_88AFE, "dsp", "__dsp_resume", a4);
    if ( (unsigned int)cvp_dsp_resume() )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_93A37, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
    }
    else if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_88B1E, "dsp", "__dsp_resume", v4);
    }
  }
}
