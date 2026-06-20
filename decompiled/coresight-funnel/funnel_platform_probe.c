__int64 __fastcall funnel_platform_probe(__int64 a1)
{
  __int64 resource; // x20
  unsigned int v3; // w20
  unsigned int v11; // w9

  resource = platform_get_resource(a1, 512, 0);
  _X8 = (unsigned int *)(a1 + 496);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 + 1, _X8) );
  _pm_runtime_set_status(a1 + 16, 0);
  pm_runtime_enable(a1 + 16);
  v3 = funnel_probe(a1 + 16, resource);
  _pm_runtime_idle(a1 + 16, 5);
  if ( v3 )
    _pm_runtime_disable(a1 + 16, 1);
  return v3;
}
