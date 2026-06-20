__int64 synx_prepare_pm_ops()
{
  __int64 result; // x0
  __int64 v1; // x5
  unsigned int v2; // w19
  void *v3; // x0
  __int64 v4; // x3

  result = synx_global_memory_is_empty();
  if ( (_DWORD)result )
  {
    if ( (synx_debug & 1) == 0 )
      return result;
    v2 = result;
    v3 = &unk_27389;
    v4 = 4102;
    goto LABEL_10;
  }
  result = synx_util_local_map_is_empty(*(_QWORD *)(synx_dev + 152) + 22568LL, 4096);
  if ( (_DWORD)result )
  {
    if ( (synx_debug & 1) == 0 )
      return result;
    v2 = result;
    v3 = &unk_26A54;
    v4 = 4109;
    goto LABEL_10;
  }
  result = synx_global_free_synx_hwlock();
  if ( (_DWORD)result && (synx_debug & 1) != 0 )
  {
    v2 = result;
    v3 = &unk_25B9A;
    v4 = 4115;
LABEL_10:
    printk(v3, &unk_29207, "synx_prepare_pm_ops", v4, v2, v1);
    return v2;
  }
  return result;
}
