__int64 __fastcall dp_aux_abort_transaction(__int64 result, char a2)
{
  if ( result )
  {
    *(_DWORD *)(result + 1832) = a2 & 1;
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    return printk(&unk_275B6D, "dp_aux_abort_transaction");
  }
  return result;
}
