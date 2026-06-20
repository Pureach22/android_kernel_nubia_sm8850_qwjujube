__int64 __fastcall hfi_plane_disable(__int64 a1, int a2, __int64 a3, char a4)
{
  __int64 v4; // x23
  _DWORD *payload_addr; // x22
  unsigned int size; // w0
  __int64 result; // x0
  int v11; // w4

  if ( !a3 )
    return printk(&unk_261E12, "hfi_plane_disable");
  v4 = *(_QWORD *)(a3 + 4272);
  if ( (a4 & 1) != 0 )
    mutex_lock(v4 + 16);
  hfi_util_u32_prop_helper_reset(*(unsigned int **)(v4 + 64));
  hfi_util_u32_prop_helper_add_prop(*(int **)(v4 + 64), 131097, 2, (_QWORD *)(v4 + 8), 4u);
  payload_addr = hfi_util_u32_prop_helper_get_payload_addr(*(_DWORD **)(v4 + 64));
  size = hfi_util_u32_prop_helper_get_size(*(_QWORD *)(v4 + 64));
  result = hfi_adapter_add_set_property(a1, 33554433, a2, 2u, (__int64)payload_addr, size, 4);
  if ( (_DWORD)result )
  {
    result = printk(&unk_24FA34, "hfi_plane_disable");
    if ( (a4 & 1) == 0 )
      return result;
    return mutex_unlock(v4 + 16);
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v4 )
      v11 = *(_DWORD *)(*(_QWORD *)v4 + 104LL);
    else
      v11 = -1;
    result = _drm_dev_dbg(0, 0, 0, "plane%d adding detatch layer\n", v11);
  }
  if ( (a4 & 1) != 0 )
    return mutex_unlock(v4 + 16);
  return result;
}
