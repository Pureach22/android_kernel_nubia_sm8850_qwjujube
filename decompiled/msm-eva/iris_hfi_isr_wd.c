__int64 __fastcall iris_hfi_isr_wd(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8

  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_8F298, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  disable_irq_nosync();
  queue_work_on(32, *(_QWORD *)(a2 + 2176), &iris_hfi_wd_work);
  return 1;
}
