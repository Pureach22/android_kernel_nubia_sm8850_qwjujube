__int64 __fastcall hfi_dbg_reg_read_handler(__int64 a1, int a2)
{
  __int64 result; // x0

  if ( a2 != -16777203 )
    return printk(&unk_261DE8, "hfi_dbg_reg_read_handler");
  return result;
}
