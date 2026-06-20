__int64 __fastcall clk_rcg2_crm_err_dump(__int64 a1)
{
  __int64 result; // x0

  result = crm_dump_regs(**(_QWORD **)(a1 + 120));
  if ( (_DWORD)result )
  {
    if ( !*(_QWORD *)(a1 + 16) )
      clk_hw_get_name(a1);
    return printk(&unk_28CEC);
  }
  return result;
}
