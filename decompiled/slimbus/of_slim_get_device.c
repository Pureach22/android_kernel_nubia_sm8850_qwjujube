__int64 __fastcall of_slim_get_device(_QWORD *a1, __int64 a2)
{
  return device_find_child(*a1, a2, of_slim_match_dev);
}
