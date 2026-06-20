int *__fastcall rmnet_module_hook_unregister_no_sync(int *result, __int64 a2)
{
  __int64 i; // x8
  __int64 v3; // x10
  int v4; // t1

  if ( (int)a2 >= 1 )
  {
    for ( i = (unsigned int)a2; i; --i )
    {
      v4 = *result;
      result += 4;
      v3 = (unsigned int)v4;
      if ( v4 <= 24 )
      {
        if ( (unsigned int)v3 >= 0x1A )
        {
          __break(0x5512u);
          return (int *)rmnet_module_hook_offload_ingress(result, a2);
        }
        *(&rmnet_module_hooks + v3) = nullptr;
      }
    }
  }
  return result;
}
