__int64 __fastcall hfi_plane_populate_custom_kv_setter_props(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  unsigned int **v4; // x22
  unsigned int count; // w19
  __int64 payload_addr; // x0
  unsigned int v9; // w20
  int v10; // w4

  if ( a1 )
  {
    v4 = *(unsigned int ***)(a1 + 4272);
    mutex_lock(v4 + 2);
    hfi_util_kv_helper_reset(v4[10]);
    count = hfi_util_kv_helper_get_count((__int64)v4[10]);
    if ( count )
    {
      payload_addr = hfi_util_kv_helper_get_payload_addr((__int64)v4[10]);
      v9 = hfi_adapter_add_prop_array(a4, 0x2000001u, a2, 2u, payload_addr, 16 * count, count);
      if ( v9 )
        printk(&unk_24FA34, "hfi_plane_populate_custom_kv_setter_props");
    }
    else
    {
      v9 = 0;
    }
    if ( (_drm_debug & 4) != 0 )
    {
      if ( v4 )
        v10 = (*v4)[26];
      else
        v10 = -1;
      _drm_dev_dbg(0, 0, 0, "plane%d adding kv-props count%d\n", v10, count);
    }
    mutex_unlock(v4 + 2);
  }
  else
  {
    printk(&unk_226FC0, "hfi_plane_populate_custom_kv_setter_props");
    return (unsigned int)-22;
  }
  return v9;
}
