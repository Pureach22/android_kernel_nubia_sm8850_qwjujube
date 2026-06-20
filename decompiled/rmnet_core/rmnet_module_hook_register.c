__int64 __fastcall rmnet_module_hook_register(__int64 result, int a2)
{
  int v2; // w13
  __int64 v3; // x8
  unsigned __int64 *i; // x9
  __int64 v5; // x11

  if ( a2 < 1 )
    return result;
  v3 = (unsigned int)a2;
  for ( i = (unsigned __int64 *)(result + 8); ; i += 2 )
  {
    v5 = *((unsigned int *)i - 2);
    if ( (int)v5 <= 24 )
      break;
LABEL_3:
    if ( !--v3 )
      return result;
  }
  if ( (unsigned int)v5 < 0x1A )
  {
    atomic_store(*i, (unsigned __int64 *)&rmnet_module_hooks + v5);
    goto LABEL_3;
  }
  __break(0x5512u);
  if ( (v2 & 0x1000000) != 0 )
    JUMPOUT(0x21128);
  return rmnet_module_hook_is_set();
}
