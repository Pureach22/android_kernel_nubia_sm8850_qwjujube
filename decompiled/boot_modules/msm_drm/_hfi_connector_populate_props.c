__int64 __fastcall hfi_connector_populate_props(__int64 a1, int a2, __int64 a3, _QWORD *a4)
{
  unsigned int **v4; // x24
  int v9; // w23
  int v10; // w23
  int v11; // w23
  int v12; // w23
  int v13; // w23
  _DWORD *payload_addr; // x23
  unsigned int size; // w0
  unsigned int v16; // w0
  __int64 result; // x0
  unsigned int v18; // w19

  v4 = *(unsigned int ***)(a3 + 5136);
  if ( !v4 )
  {
    printk(&unk_242658, "_hfi_connector_populate_props");
    return 4294967274LL;
  }
  if ( !v4[7] )
  {
    printk(&unk_242658, "_hfi_connector_set_props_base");
    v18 = -22;
LABEL_23:
    printk(&unk_261C49, "_hfi_connector_populate_props");
    return v18;
  }
  mutex_lock(v4 + 1);
  hfi_util_u32_prop_helper_reset(v4[7]);
  v9 = dword_618C;
  if ( (sde_connector_property_is_dirty(a4, (unsigned int)hfi_connector_base_props_map) & 1) != 0 )
    hfi_connector_add_base_prop_helper(v9, a3, a4, (int *)v4[7]);
  v10 = dword_6194;
  if ( (sde_connector_property_is_dirty(a4, (unsigned int)dword_6190) & 1) != 0 )
    hfi_connector_add_base_prop_helper(v10, a3, a4, (int *)v4[7]);
  v11 = dword_619C;
  if ( (sde_connector_property_is_dirty(a4, (unsigned int)dword_6198) & 1) != 0 )
    hfi_connector_add_base_prop_helper(v11, a3, a4, (int *)v4[7]);
  v12 = dword_61A4;
  if ( (sde_connector_property_is_dirty(a4, (unsigned int)dword_61A0) & 1) != 0 )
    hfi_connector_add_base_prop_helper(v12, a3, a4, (int *)v4[7]);
  v13 = dword_61AC;
  if ( (sde_connector_property_is_dirty(a4, (unsigned int)dword_61A8) & 1) != 0 )
    hfi_connector_add_base_prop_helper(v13, a3, a4, (int *)v4[7]);
  if ( (unsigned int)hfi_util_u32_prop_helper_prop_count((__int64)v4[7]) )
  {
    payload_addr = hfi_util_u32_prop_helper_get_payload_addr(v4[7]);
    size = hfi_util_u32_prop_helper_get_size((__int64)v4[7]);
    v16 = hfi_adapter_add_set_property(a1, 33554433, a2, 2u, (__int64)payload_addr, size, 4);
    if ( v16 )
    {
      v18 = v16;
      printk(&unk_22DD04, "_hfi_connector_set_props_base");
      mutex_unlock(v4 + 1);
      goto LABEL_23;
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "conn%d done adding all base props\n", (*v4)[16]);
  }
  mutex_unlock(v4 + 1);
  result = hfi_connector_populate_custom_kv_setter_props(a3, a2, (__int64)a4, a1);
  if ( (_DWORD)result )
  {
    v18 = result;
    goto LABEL_23;
  }
  return result;
}
