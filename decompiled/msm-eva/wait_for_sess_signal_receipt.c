__int64 __fastcall wait_for_sess_signal_receipt(__int64 a1, int a2)
{
  __int64 v2; // x21
  __int64 v3; // x8
  __int64 v5; // x23
  __int64 *v7; // x20
  __int64 v8; // x0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x9
  __int64 v11; // x0
  __int64 v12; // x1
  unsigned __int64 v13; // x8

  v2 = (unsigned int)(a2 - 10);
  if ( (unsigned int)v2 >= 0x14 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_9257D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 128);
    v5 = a1 + 32 * v2;
    v7 = *(__int64 **)(v3 + 256);
    v8 = _msecs_to_jiffies(*(unsigned int *)(v3 + 1024));
    if ( (unsigned int)wait_for_completion_timeout(v5 + 12936, v8) )
    {
      if ( *(_DWORD *)(a1 + 328) == 9 )
      {
        return 4294967192LL;
      }
      else
      {
        result = *(unsigned int *)(a1 + 15252);
        *(_DWORD *)(a1 + 15252) = 0;
        *(_DWORD *)(a1 + 15256) = result;
      }
    }
    else
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        v13 = _ReadStatusReg(SP_EL0);
        printk(&unk_8ABB1, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), "warn");
      }
      if ( *(_DWORD *)(a1 + 328) != 9 )
        print_hfi_queue_info(v7);
      if ( (a2 & 0x1B) == 0xB || a2 == 13 || (a2 & 0x1D) == 0x10 )
      {
        v11 = a1;
        v12 = 0;
      }
      else
      {
        v11 = a1;
        v12 = 1;
      }
      handle_session_timeout(v11, v12);
      return 4294967186LL;
    }
  }
  return result;
}
