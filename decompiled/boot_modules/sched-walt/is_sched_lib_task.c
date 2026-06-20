size_t is_sched_lib_task()
{
  size_t result; // x0
  unsigned __int64 StatusReg; // x19
  size_t v2; // x0
  size_t v3; // x2
  __int64 v4; // x0

  result = strnlen(sched_lib_task, 0x200u);
  if ( result >= 0x201 )
  {
    _fortify_panic(2, 512, result + 1);
    goto LABEL_8;
  }
  if ( !result )
    return result;
  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = strnlen((const char *)(StatusReg + 2320), 0x10u);
  v3 = v2;
  if ( v2 >= 0x10 && v2 != 512 )
  {
LABEL_8:
    v4 = _fortify_panic(2, 16, v3 + 1);
    return account_yields(v4);
  }
  return strnstr(StatusReg + 2320, sched_lib_task, v2) != 0;
}
