__int64 __fastcall iris_hfi_get_core_capabilities(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (msm_cvp_debug & 0x100) == 0 || msm_cvp_debug_out )
    return 0;
  printk(&unk_861A5, "core", "iris_hfi_get_core_capabilities", a4);
  return 0;
}
