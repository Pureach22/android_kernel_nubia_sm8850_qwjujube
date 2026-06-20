__int64 __fastcall clk_branch_restore_context_aon(__int64 a1)
{
  __int64 result; // x0

  result = clk_enable_regmap(a1);
  if ( (_DWORD)result )
  {
    clk_hw_get_name(a1);
    return printk(&unk_29671);
  }
  return result;
}
