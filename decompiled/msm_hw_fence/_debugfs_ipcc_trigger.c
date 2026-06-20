__int64 __fastcall debugfs_ipcc_trigger(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  unsigned int v7; // w19
  unsigned int debugfs_input_client_with_min; // w0
  __int64 v9; // x22
  unsigned int v10; // w24
  unsigned int signal_id; // w0
  unsigned int v12; // w23
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v7 = a3;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  debugfs_input_client_with_min = get_debugfs_input_client_with_min(a1, a2, a3, v14, 1);
  if ( (debugfs_input_client_with_min & 0x80000000) != 0
    || (v9 = v14[0],
        v10 = debugfs_input_client_with_min,
        signal_id = hw_fence_ipcc_get_signal_id(v14[0], debugfs_input_client_with_min),
        (signal_id & 0x80000000) != 0) )
  {
    v7 = -22;
  }
  else
  {
    v12 = signal_id;
    if ( (~msm_hw_fence_debug_level & 0x10040) == 0 )
    {
      hw_fence_get_qtime(v9);
      printk(&unk_2AC11, "_debugfs_ipcc_trigger", 170, v10, a4);
    }
    hw_fence_ipcc_trigger_signal(v9, a4, a5, v12);
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
