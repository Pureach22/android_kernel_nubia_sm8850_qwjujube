__int64 kgsl_drawobjs_cache_init()
{
  __int64 args; // x0
  _QWORD v2[5]; // [xsp+8h] [xbp-28h] BYREF

  v2[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v2[1], 0, 24);
  v2[0] = 8;
  args = _kmem_cache_create_args("kgsl_memobj_node", 64, v2, 0);
  memobjs_cache = args;
  _ReadStatusReg(SP_EL0);
  if ( args )
    return 0;
  else
    return 4294967284LL;
}
