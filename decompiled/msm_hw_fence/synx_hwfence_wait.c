__int64 __fastcall synx_hwfence_wait(unsigned __int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x30
  unsigned int v5; // w5
  __int64 v6; // x23
  unsigned int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w22
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( !a1
    || a1 > 0xFFFFFFFFFFFFF000LL
    || (v5 = *(_DWORD *)a1, (unsigned int)(*(_DWORD *)a1 - 1024) > 0xBFF)
    || (a2 & 0x80000000) == 0 )
  {
    printk(&unk_2527A, "synx_hwfence_wait", 455, v3, a1);
    result = 4294967274LL;
    goto LABEL_9;
  }
  if ( (*(_DWORD *)a1 & 0xFC0) != 0x940 && v5 - 2944 > 0xFF )
  {
    v9 = -22;
LABEL_13:
    printk(&unk_22AE6, "synx_hwfence_wait", 467, v3, v5);
    result = hw_fence_interop_to_synx_status(v9);
    goto LABEL_9;
  }
  v6 = v3;
  v7 = hw_fence_debug_wait_val(hw_fence_drv_data, *(unsigned int **)(a1 + 8), 0, a2, 0xFFFF, a3, &v10);
  if ( v7 )
  {
    v5 = *(_DWORD *)a1;
    v9 = v7;
    v3 = v6;
    goto LABEL_13;
  }
  result = hw_fence_interop_to_synx_signal_status(1, v10);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
