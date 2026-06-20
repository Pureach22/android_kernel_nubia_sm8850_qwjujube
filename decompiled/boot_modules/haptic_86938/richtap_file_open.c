__int64 __fastcall richtap_file_open(__int64 a1, __int64 a2)
{
  if ( (try_module_get(&_this_module) & 1) == 0 )
    return 4294967277LL;
  *(_QWORD *)(a2 + 32) = g_aw_haptic;
  return 0;
}
