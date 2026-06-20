__int64 __fastcall mlo_mgr_link_switch_init(void *a1, __int64 a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x21
  __int64 v6; // x0
  __int64 v7; // x0

  v4 = _qdf_mem_malloc(0x178u, "mlo_mgr_link_switch_init", 1101);
  *(_QWORD *)(a2 + 3880) = v4;
  if ( !v4 )
    return 2;
  qdf_mutex_acquire(a2 + 1656);
  *(_DWORD *)(*(_QWORD *)(a2 + 3880) + 164LL) = 0;
  qdf_mutex_release(a2 + 1656);
  if ( a2 )
  {
    v5 = *(_QWORD **)(a2 + 3880);
    v6 = _qdf_mem_malloc(0x28u, "mlo_mgr_alloc_link_info_wmi_chan", 324);
    v5[4] = v6;
    if ( v6 )
    {
      v7 = _qdf_mem_malloc(0x28u, "mlo_mgr_alloc_link_info_wmi_chan", 324);
      v5[10] = v7;
      if ( v7 )
        v5[16] = _qdf_mem_malloc(0x28u, "mlo_mgr_alloc_link_info_wmi_chan", 324);
    }
  }
  mlo_mgr_update_link_info_reset(a1, a2);
  return 0;
}
