// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_1CBD4(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 v5; // x23
  unsigned __int64 v6; // x0
  __int64 v7; // x4
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  int updated; // w0
  __int64 v16; // x4
  __int64 v17; // x3
  int v18; // w0
  __int64 v19; // x4
  __int64 result; // x0
  int v21; // w21
  int v22; // w19
  unsigned __int64 v23; // [xsp-58h] [xbp-58h] BYREF
  unsigned int v24; // [xsp-50h] [xbp-50h]

  v6 = _arch_copy_from_user(&v23, a2 & 0xFF7FFFFFFFFFFFFFLL, 16);
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v14 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v14 - 4096);
  _WriteStatusReg(TTBR1_EL1, v14);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  if ( v6 )
  {
    if ( v6 >= 0x11 )
    {
      _fortify_panic(15, 0, v6);
      JUMPOUT(0x1CD48);
    }
    result = -14;
  }
  else
  {
    updated = msm_hw_fence_update_txq(*(_QWORD *)(v2 + 16), v23, 0, v24, v7);
    if ( updated )
    {
      v21 = updated;
      printk(&unk_22A46, "hw_sync_ioctl_fence_signal", 467, v3, *(unsigned int *)(v2 + 8));
      result = v21;
    }
    else
    {
      v17 = *(unsigned int *)(v5 + 164);
      if ( (v17 & 0x80000000) != 0 )
      {
        result = -22;
      }
      else
      {
        v18 = msm_hw_fence_trigger_signal(
                *(unsigned int **)(v2 + 16),
                *(_DWORD *)(v5 + 172),
                *(unsigned int *)(*(_QWORD *)(v4 + 1896) + 636LL),
                v17,
                v16);
        if ( v18 )
        {
          v22 = v18;
          printk(&unk_27C51, "hw_sync_ioctl_fence_signal", 479, v3, v19);
          result = v22;
        }
        else
        {
          result = 0;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
