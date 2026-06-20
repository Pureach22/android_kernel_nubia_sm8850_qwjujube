__int64 __fastcall scm_waitq_flag_handler(_DWORD *a1, __int64 a2)
{
  __int64 result; // x0

  if ( (_DWORD)a2 == 2 )
  {
    result = complete_all();
    *a1 = 0;
  }
  else if ( (_DWORD)a2 == 1 )
  {
    return complete(a1, a2, (unsigned int)a2);
  }
  else
  {
    return printk(&unk_12A88, "scm_waitq_flag_handler", (unsigned int)a2);
  }
  return result;
}
