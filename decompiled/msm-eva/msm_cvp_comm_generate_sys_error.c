void __fastcall msm_cvp_comm_generate_sys_error(__int64 a1)
{
  unsigned __int64 v1; // x8
  unsigned __int64 StatusReg; // x8
  _QWORD v3[96]; // [xsp+0h] [xbp-300h] BYREF

  v3[95] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && *(_QWORD *)(a1 + 128) )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_9471E, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
    handle_sys_error(9, (__int64)v3);
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v1 = _ReadStatusReg(SP_EL0);
    printk(&unk_82944, *(unsigned int *)(v1 + 1800), *(unsigned int *)(v1 + 1804), &unk_8E7CE);
  }
  _ReadStatusReg(SP_EL0);
}
