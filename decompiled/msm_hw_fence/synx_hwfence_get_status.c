__int64 __fastcall synx_hwfence_get_status(_DWORD *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  __int64 result; // x0
  unsigned int v9; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v6 = v5;
  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v9 = 0;
  if ( a1 && (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL && a2 < 0 && (unsigned int)(*a1 - 4096) > 0xFFFFF3FF )
  {
    if ( (unsigned int)hw_fence_get_flags_error(hw_fence_drv_data, (unsigned __int16)a2, v10, &v9, a5) )
    {
      printk(&unk_28F7E, "synx_hwfence_get_status", 520, v6, (unsigned int)*a1);
      result = 0;
    }
    else
    {
      result = hw_fence_interop_to_synx_signal_status(LODWORD(v10[0]), v9);
    }
  }
  else
  {
    printk(&unk_25E32, "synx_hwfence_get_status", 513, v5, a1);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
