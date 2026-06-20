__int64 __fastcall _print_reg_details_errlog3_low_pakala(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  unsigned int v8; // w19
  int v9; // w8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x9

  _X21 = off_6C000;
  v8 = result;
  v9 = msm_cvp_debug_out;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    result = printk(&unk_87EFA, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    v9 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 1) == 0 )
      return result;
  }
  else if ( (msm_cvp_debug & 1) == 0 )
  {
    return result;
  }
  if ( !v9 )
  {
    if ( ((v8 >> 7) & 0x1F) >= 0x19 )
    {
      __break(0x5512u);
      __asm { STZ2G           X21, [X6,#0x4C0]! }
      return _dump_noc_regs_pakala(result, a2, a3, a4, a5, a6, a7);
    }
    else
    {
      v11 = _ReadStatusReg(SP_EL0);
      return printk(&unk_82C14, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
    }
  }
  return result;
}
