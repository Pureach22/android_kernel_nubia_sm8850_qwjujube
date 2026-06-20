__int64 __fastcall synx_util_get_bind_ops(int a1)
{
  __int64 v2; // x19
  int v3; // w20

  if ( a1 )
    return 0;
  mutex_lock(synx_dev + 176);
  v2 = synx_dev;
  v3 = *(unsigned __int8 *)(synx_dev + 324);
  mutex_unlock(synx_dev + 176);
  if ( v3 )
    return v2 + 288;
  else
    return 0;
}
