__int64 __fastcall hfi_connector_populate_custom_kv_setter_props(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  unsigned int **v5; // x23
  void (__fastcall *v9)(__int64, __int64, __int64, __int64); // x8
  __int64 v10; // x0
  unsigned int count; // w21
  __int64 payload_addr; // x0
  unsigned int v13; // w19

  if ( a4 && a3 && (v5 = *(unsigned int ***)(a1 + 5136)) != nullptr )
  {
    mutex_lock(v5 + 1);
    hfi_util_kv_helper_reset(v5[8]);
    if ( (sde_connector_property_is_dirty(a3, (unsigned int)hfi_connector_kv_props_map) & 1) != 0 )
    {
      v9 = (void (__fastcall *)(__int64, __int64, __int64, __int64))off_61B8;
      if ( off_61B8 )
      {
        v10 = (unsigned int)dword_61B4;
        if ( *((_DWORD *)off_61B8 - 1) != -1074700648 )
          __break(0x8228u);
        v9(v10, a1, a3, a4);
      }
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "conn%d conn prop is not dirty\n", (*v5)[16]);
    }
    count = hfi_util_kv_helper_get_count((__int64)v5[8]);
    if ( count )
    {
      payload_addr = hfi_util_kv_helper_get_payload_addr((__int64)v5[8]);
      v13 = hfi_adapter_add_prop_array(a4, 0x2000001u, a2, 2u, payload_addr, count, 16 * count);
      if ( v13 && (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "conn%d failed to send HFI commands\n", (*v5)[16]);
    }
    else
    {
      v13 = 0;
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "conn%d adding kv-props count%d\n", (*v5)[16], count);
    mutex_unlock(v5 + 1);
  }
  else
  {
    printk(&unk_242658, "hfi_connector_populate_custom_kv_setter_props");
    return (unsigned int)-22;
  }
  return v13;
}
