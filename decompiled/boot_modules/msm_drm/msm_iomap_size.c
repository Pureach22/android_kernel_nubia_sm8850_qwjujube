_QWORD *__fastcall msm_iomap_size(__int64 a1, __int64 a2)
{
  _QWORD *result; // x0

  if ( a2 )
  {
    result = (_QWORD *)platform_get_resource_byname(a1, 512, a2);
    if ( !result )
      return result;
  }
  else
  {
    result = (_QWORD *)platform_get_resource(a1, 512, 0);
    if ( !result )
      return result;
  }
  return (_QWORD *)(result[1] - *result + 1LL);
}
