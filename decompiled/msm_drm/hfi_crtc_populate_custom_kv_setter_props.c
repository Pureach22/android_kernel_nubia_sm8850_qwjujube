__int64 __fastcall hfi_crtc_populate_custom_kv_setter_props(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  unsigned int **v4; // x22
  unsigned int count; // w19
  __int64 payload_addr; // x0
  unsigned int v9; // w20
  int v10; // w4

  if ( a1 )
  {
    v4 = *(unsigned int ***)(a1 + 8032);
    mutex_lock(v4 + 1);
    hfi_util_kv_helper_reset(v4[9]);
    count = hfi_util_kv_helper_get_count((__int64)v4[9]);
    if ( count )
    {
      payload_addr = hfi_util_kv_helper_get_payload_addr((__int64)v4[9]);
      v9 = hfi_adapter_add_prop_array(a4, 0x2000001u, a2, 2u, payload_addr, 16 * count, count);
      if ( v9 )
        printk(&unk_273493, "hfi_crtc_populate_custom_kv_setter_props");
    }
    else
    {
      v9 = 0;
    }
    mutex_unlock(v4 + 1);
    if ( (_drm_debug & 4) != 0 )
    {
      if ( v4 )
        v10 = (*v4)[28];
      else
        v10 = -1;
      _drm_dev_dbg(0, 0, 0, "crtc%d kv-props count%d\n", v10, count);
    }
  }
  else
  {
    printk(&unk_25E167, "hfi_crtc_populate_custom_kv_setter_props");
    return (unsigned int)-22;
  }
  return v9;
}
