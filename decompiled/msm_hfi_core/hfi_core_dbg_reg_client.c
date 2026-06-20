__int64 __fastcall hfi_core_dbg_reg_client(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x21

  v5 = v4;
  _ReadStatusReg(SP_EL0);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "hfi_core_dbg_reg_client", 1404, a4);
  get_debugfs_input_client();
  printk(&unk_1F01E, "hfi_core_dbg_reg_client", 1411, v5);
  _ReadStatusReg(SP_EL0);
  return -22;
}
