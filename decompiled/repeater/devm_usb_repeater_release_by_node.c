__int64 __fastcall devm_usb_repeater_release_by_node(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  __int64 v4; // x8

  if ( a2 )
  {
    result = put_device(*a2);
    v4 = *(_QWORD *)(*a2 + 136LL);
    if ( v4 )
    {
      result = *(_QWORD *)(v4 + 16);
      if ( result )
        return module_put();
    }
  }
  return result;
}
