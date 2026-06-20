__int64 __fastcall replicator_platform_probe(__int64 a1)
{
  unsigned __int64 resource; // x20
  __int64 v3; // x0
  __int64 result; // x0
  unsigned int v5; // w20
  unsigned int v12; // w9

  resource = platform_get_resource(a1, 512, 0);
  v3 = devm_kmalloc(a1 + 16, 112, 3520);
  if ( !v3 )
    return 4294967284LL;
  *(_QWORD *)(a1 + 168) = v3;
  _X8 = (unsigned int *)(a1 + 496);
  __asm { PRFM            #0x11, [X8] }
  do
    v12 = __ldxr(_X8);
  while ( __stxr(v12 + 1, _X8) );
  _pm_runtime_set_status(a1 + 16, 0);
  pm_runtime_enable(a1 + 16);
  result = replicator_add_coresight_dev((_QWORD *)(a1 + 16), resource);
  if ( (_DWORD)result )
  {
    v5 = result;
    _pm_runtime_idle(a1 + 16, 4);
    _pm_runtime_disable(a1 + 16, 1);
    return v5;
  }
  return result;
}
