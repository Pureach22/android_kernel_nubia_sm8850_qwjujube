__int64 __fastcall con_mode_handler_epping(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3

  result = param_set_int(a1, a2);
  if ( con_mode_epping == 8 )
  {
    curr_con_mode = 8;
    con_mode = 8;
  }
  else
  {
    printk(&unk_AA1B19, v3, v4, v5);
    return 4294966772LL;
  }
  return result;
}
