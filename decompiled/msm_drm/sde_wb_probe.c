__int64 __fastcall sde_wb_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 property; // x0
  __int64 v5; // x0
  __int64 *v6; // x1
  long double v7; // q0
  __int64 result; // x0
  unsigned int v9; // w19

  v2 = devm_kmalloc(a1 + 16, 136, 3520);
  if ( !v2 )
    return 4294967284LL;
  v3 = v2;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "cell-index", v3 + 8, 1, 0) & 0x80000000) != 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "cell index not set, default to 0\n");
    *(_DWORD *)(v3 + 8) = 0;
  }
  property = of_get_property(*(_QWORD *)(a1 + 760), "label", 0);
  *(_QWORD *)(v3 + 24) = property;
  if ( !property )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "label not set, default to unknown\n");
    *(_QWORD *)(v3 + 24) = "unknown";
  }
  *(_DWORD *)(v3 + 12) = 0;
  _mutex_init(v3 + 48, "&wb_dev->wb_lock", &sde_wb_probe___key);
  *(_QWORD *)(a1 + 168) = v3;
  mutex_lock(&sde_wb_list_lock);
  v5 = v3 + 32;
  v6 = (__int64 *)off_C190;
  if ( off_C190 == (_UNKNOWN *)(v3 + 32) || *(_UNKNOWN ***)off_C190 != &sde_wb_list )
  {
    _list_add_valid_or_report(v5, off_C190);
  }
  else
  {
    off_C190 = (_UNKNOWN *)(v3 + 32);
    *(_QWORD *)(v3 + 32) = &sde_wb_list;
    *(_QWORD *)(v3 + 40) = v6;
    *v6 = v5;
  }
  mutex_unlock(&sde_wb_list_lock);
  if ( (_drm_debug & 4) != 0 )
    *(double *)&v7 = _drm_dev_dbg(0, 0, 0, "\n");
  result = component_add(a1 + 16, sde_wb_comp_ops, v7);
  if ( (_DWORD)result )
  {
    v9 = result;
    printk(&unk_22F6C1, "sde_wb_probe");
    return v9;
  }
  return result;
}
