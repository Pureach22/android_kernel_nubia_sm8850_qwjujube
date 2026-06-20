__int64 __fastcall rmnet_module_hook_is_set(int a1)
{
  __int64 v2; // x0

  if ( a1 > 24 )
    return 0;
  if ( (unsigned int)a1 < 0x19 )
    return *(&rmnet_module_hooks + (unsigned int)a1) != nullptr;
  __break(0x5512u);
  v2 = MEMORY[0x57BD5D4]();
  return rmnet_module_hook_unregister_no_sync(v2);
}
