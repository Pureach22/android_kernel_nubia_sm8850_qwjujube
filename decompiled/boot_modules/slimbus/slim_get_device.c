__int64 __fastcall slim_get_device(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0

  result = device_find_child(*a1, a2, slim_match_dev);
  if ( !result )
  {
    result = slim_alloc_device(a1, a2, 0);
    if ( !result )
      return -12;
  }
  return result;
}
