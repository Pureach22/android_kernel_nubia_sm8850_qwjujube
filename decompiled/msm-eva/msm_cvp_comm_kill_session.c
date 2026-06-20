__int64 __fastcall msm_cvp_comm_kill_session(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x19
  unsigned int v4; // w8
  __int64 v5; // x8
  __int64 *v6; // x0
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  __int64 v9; // x3
  int v10; // w9
  __int64 v11; // x8
  __int64 v12; // x19
  __int64 v13; // x0
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v16; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 128)) != 0 && *(_QWORD *)(v1 + 256) )
  {
    v2 = *(_QWORD *)(a1 + 320);
    if ( v2 )
    {
      v3 = a1;
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_94744, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        a1 = v3;
      }
      v4 = *(_DWORD *)(a1 + 328);
      if ( v4 - 5 <= 1 )
      {
        v5 = *(_QWORD *)(a1 + 128);
        if ( v5 && (v6 = *(__int64 **)(v5 + 256)) != nullptr )
        {
          print_hfi_queue_info(v6);
        }
        else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v16 = _ReadStatusReg(SP_EL0);
          printk(&unk_86F4F, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
        }
        mutex_lock(v3 + 80);
        v9 = *(unsigned int *)(v3 + 328);
        v10 = (msm_cvp_debug_out == 0) & (BYTE1(msm_cvp_debug) >> 5);
        if ( (_DWORD)v9 == 9 )
        {
          if ( v10 )
            printk(&unk_8E12E, "sess", v3, 9);
        }
        else
        {
          v11 = v3;
          if ( v10 )
          {
            printk(&unk_89763, "sess", v3, v9);
            v11 = v3;
          }
          *(_DWORD *)(v11 + 328) = 9;
        }
        mutex_unlock(v3 + 80);
        v4 = *(_DWORD *)(v3 + 328);
        a1 = v3;
      }
      if ( v4 >= 8 )
      {
        v12 = a1;
        v13 = raw_spin_lock_irqsave(a1 + 288);
        *(_DWORD *)(v12 + 292) = 1;
        raw_spin_unlock_irqrestore(v12 + 288, v13);
        _wake_up(v12 + 296, 3, 0, 0);
      }
      goto LABEL_30;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_88F46, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
LABEL_30:
      LODWORD(v2) = 0;
    }
  }
  else
  {
    LODWORD(v2) = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v7 = _ReadStatusReg(SP_EL0);
      printk(&unk_82944, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
      LODWORD(v2) = -22;
    }
  }
  return (unsigned int)v2;
}
