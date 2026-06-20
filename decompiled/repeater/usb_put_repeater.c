_QWORD *__fastcall usb_put_repeater(_QWORD *result)
{
  _QWORD *v1; // x19
  __int64 v2; // x8

  if ( result )
  {
    v1 = result;
    result = (_QWORD *)put_device(*result);
    v2 = *(_QWORD *)(*v1 + 136LL);
    if ( v2 )
    {
      result = *(_QWORD **)(v2 + 16);
      if ( result )
        return (_QWORD *)module_put();
    }
  }
  return result;
}
