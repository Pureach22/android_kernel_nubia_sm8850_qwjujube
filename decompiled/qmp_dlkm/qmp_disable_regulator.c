__int64 __fastcall qmp_disable_regulator(__int64 a1)
{
  __int64 result; // x0
  int v3; // w20

  result = *(_QWORD *)(a1 + 48);
  if ( result )
  {
    result = regulator_disable();
    if ( (_DWORD)result )
    {
      v3 = result;
      result = __ratelimit(&qmp_disable_regulator__rs, "qmp_disable_regulator");
      if ( (_DWORD)result )
        return dev_err(*(_QWORD *)(a1 + 8), "qmp regulator disable failed %d", v3);
    }
  }
  return result;
}
