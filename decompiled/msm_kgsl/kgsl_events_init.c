__int64 kgsl_events_init()
{
  __int64 result; // x0
  _QWORD v1[5]; // [xsp+8h] [xbp-28h] BYREF

  v1[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v1[1], 0, 24);
  v1[0] = 8;
  result = _kmem_cache_create_args("kgsl_event", 120, v1, 0);
  events_cache = result;
  _ReadStatusReg(SP_EL0);
  return result;
}
