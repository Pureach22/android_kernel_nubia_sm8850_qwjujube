__int64 __fastcall usb_gadget_autopm_get(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    result = *(_QWORD *)(result + 200);
    if ( result )
    {
      result = _pm_runtime_resume(result, 4);
      if ( (result & 0x80000000) != 0 )
        return _pm_runtime_idle(*(_QWORD *)(v1 + 200), 4);
    }
  }
  return result;
}
