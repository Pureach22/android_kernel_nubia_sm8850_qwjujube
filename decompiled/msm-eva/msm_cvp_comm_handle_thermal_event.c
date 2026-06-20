__int64 msm_cvp_comm_handle_thermal_event()
{
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0

  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    return printk(&unk_83CF0, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
  }
  return result;
}
