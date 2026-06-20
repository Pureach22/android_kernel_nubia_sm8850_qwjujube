_QWORD *__fastcall kgsl_pwrscale_tz_disable(_QWORD *result, char a2)
{
  __int64 v2; // x19

  if ( result[1389] )
  {
    v2 = (__int64)result;
    if ( result[1427] )
      result = (_QWORD *)queue_work_on(32, result[1487], result + 1488);
    *(_BYTE *)(v2 + 11880) = 0;
    if ( (a2 & 1) != 0 )
      return (_QWORD *)kgsl_pwrctrl_pwrlevel_change(v2);
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
