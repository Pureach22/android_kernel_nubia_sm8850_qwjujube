__int64 __fastcall stm_find_device(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x19

  if ( !stm_core_up )
    return 0;
  result = class_find_device(&stm_class, 0, a1, &device_match_name);
  if ( result )
  {
    v2 = result;
    if ( (try_module_get(*(_QWORD *)(result + 912)) & 1) != 0 )
    {
      return v2;
    }
    else
    {
      put_device(v2);
      return 0;
    }
  }
  return result;
}
