__int64 __fastcall hfi_crtc_populate_props(__int64 a1, unsigned int a2, _QWORD *a3, __int64 a4)
{
  __int64 v4; // x24
  _DWORD *payload_addr; // x23
  unsigned int size; // w0
  unsigned int v11; // w0
  __int64 v12; // x8
  int v13; // w9
  __int64 *v14; // x23
  unsigned int v15; // w25
  int v16; // w4
  __int64 v17; // x2
  __int64 result; // x0
  unsigned int v19; // w19
  void *v20; // x0

  if ( !a3 )
  {
    printk(&unk_25E167, "_hfi_crtc_populate_props");
    return 4294967274LL;
  }
  v4 = a3[1004];
  if ( !*(_QWORD *)(v4 + 56) )
  {
    v19 = -22;
LABEL_22:
    v20 = &unk_23EE43;
    goto LABEL_23;
  }
  mutex_lock(v4 + 8);
  hfi_util_u32_prop_helper_reset(*(unsigned int **)(v4 + 56));
  hfi_crtc_add_base_prop_helper(dword_61C4, (__int64)a3, a4, *(int **)(v4 + 56), hfi_crtc_base_props_map);
  hfi_crtc_add_base_prop_helper(dword_61CC, (__int64)a3, a4, *(int **)(v4 + 56), dword_61C8);
  hfi_crtc_add_base_prop_helper(dword_61D4, (__int64)a3, a4, *(int **)(v4 + 56), dword_61D0);
  hfi_crtc_add_base_prop_helper(dword_61DC, (__int64)a3, a4, *(int **)(v4 + 56), dword_61D8);
  hfi_crtc_add_base_prop_helper(dword_61E4, (__int64)a3, a4, *(int **)(v4 + 56), dword_61E0);
  hfi_crtc_add_base_prop_helper(dword_61EC, (__int64)a3, a4, *(int **)(v4 + 56), dword_61E8);
  hfi_crtc_add_base_prop_helper(dword_61F4, (__int64)a3, a4, *(int **)(v4 + 56), dword_61F0);
  if ( !(unsigned int)hfi_util_u32_prop_helper_prop_count(*(_QWORD *)(v4 + 56)) )
    goto LABEL_16;
  payload_addr = hfi_util_u32_prop_helper_get_payload_addr(*(_DWORD **)(v4 + 56));
  size = hfi_util_u32_prop_helper_get_size(*(_QWORD *)(v4 + 56));
  v11 = hfi_adapter_add_set_property(a1, 33554433, a2, 2u, (__int64)payload_addr, size, 4);
  if ( v11 )
  {
    v19 = v11;
    printk(&unk_273493, "_hfi_crtc_set_props_base");
    mutex_unlock(v4 + 8);
    goto LABEL_22;
  }
  v12 = *a3;
  v13 = *(_DWORD *)(a4 + 12);
  v14 = *(__int64 **)(*a3 + 840LL);
  if ( v14 != (__int64 *)(*a3 + 840LL) )
  {
    v15 = *(_DWORD *)(v4 + 144) & ~v13;
    do
    {
      if ( ((v15 >> *((_DWORD *)v14 + 437)) & 1) != 0 )
      {
        hfi_plane_disable(a1, a2, v14 - 1, 0);
        v12 = *a3;
      }
      v14 = (__int64 *)*v14;
    }
    while ( v14 != (__int64 *)(v12 + 840) );
    v13 = *(_DWORD *)(a4 + 12);
  }
  *(_DWORD *)(v4 + 144) = v13;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v4 )
      v16 = *(_DWORD *)(*(_QWORD *)v4 + 112LL);
    else
      v16 = -1;
    _drm_dev_dbg(0, 0, 0, "crtc%d done adding all base props\n", v16);
  }
LABEL_16:
  mutex_unlock(v4 + 8);
  result = hfi_crtc_populate_custom_kv_setter_props((__int64)a3, a2, v17, a1);
  if ( (_DWORD)result )
  {
    v19 = result;
    v20 = &unk_211DE7;
LABEL_23:
    printk(v20, "_hfi_crtc_populate_props");
    return v19;
  }
  return result;
}
