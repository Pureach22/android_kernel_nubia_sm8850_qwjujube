__int64 __fastcall hwmon_dev_attr_is_visible(__int64 a1, __int64 a2)
{
  if ( (char **)a2 == &dev_attr_name )
  {
    if ( !*(_QWORD *)(a1 - 16) )
      return 0;
  }
  else if ( (char **)a2 == &dev_attr_label && !*(_QWORD *)(a1 - 8) )
  {
    return 0;
  }
  return *(unsigned __int16 *)(a2 + 8);
}
