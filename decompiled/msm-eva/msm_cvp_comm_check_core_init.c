__int64 __fastcall msm_cvp_comm_check_core_init(__int64 a1)
{
  __int64 v2; // x3
  __int64 v3; // x2
  unsigned int v4; // w20
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x3
  char v8; // w8
  unsigned __int64 StatusReg; // x8

  mutex_lock(a1);
  v3 = *(unsigned int *)(a1 + 304);
  if ( (unsigned int)v3 < 2 )
  {
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
      printk(&unk_92634, "core", v3, v2);
    v5 = _msecs_to_jiffies(*(unsigned int *)(a1 + 1024));
    if ( (unsigned int)wait_for_completion_timeout(a1 + 312, v5) )
    {
      v4 = 0;
      v8 = BYTE1(msm_cvp_debug);
      *(_DWORD *)(a1 + 304) = 2;
      if ( (v8 & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8ABFD, "core", v6, v7);
        goto LABEL_12;
      }
    }
    else
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_946DF, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      print_hfi_queue_info(*(__int64 **)(a1 + 256));
      v4 = -5;
    }
  }
  else
  {
    v4 = 0;
    if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_8C998, "info", v3, v2);
LABEL_12:
      v4 = 0;
    }
  }
  mutex_unlock(a1);
  return v4;
}
