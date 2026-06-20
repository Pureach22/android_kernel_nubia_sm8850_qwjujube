_QWORD *__fastcall kgsl_pwrscale_tz_enable(_QWORD *result)
{
  _QWORD *v1; // x19

  if ( result[1389] )
  {
    v1 = result;
    if ( result[1427] )
    {
      result = (_QWORD *)queue_work_on(32, result[1487], result + 1492);
      *((_BYTE *)v1 + 11880) = 1;
    }
    else
    {
      result = (_QWORD *)kgsl_pwrctrl_pwrlevel_change((__int64)result);
      *((_BYTE *)v1 + 11880) = 0;
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
