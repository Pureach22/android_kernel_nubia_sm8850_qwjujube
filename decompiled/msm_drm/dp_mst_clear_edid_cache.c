__int64 __fastcall dp_mst_clear_edid_cache(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x19
  int v12; // w6
  int v13; // w7
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  char v16; // [xsp+0h] [xbp-20h]
  char v17; // [xsp+0h] [xbp-20h]
  _QWORD v18[3]; // [xsp+8h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v18[1] = 0;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_clear_edid_cache", 1251, 8, 4369, -1059143953, a7, a8, v16);
  if ( a1 )
  {
    v9 = a1[5];
    drm_connector_list_iter_begin(*a1, v18);
    v10 = drm_connector_list_iter_next(v18);
    if ( v10 )
    {
      v11 = v10;
      do
      {
        if ( *(_QWORD *)(v11 + 2776) )
        {
          mutex_lock(v9 + 4184);
          kfree(*(_QWORD *)(v11 + 5008));
          *(_QWORD *)(v11 + 5008) = 0;
          mutex_unlock(v9 + 4184);
        }
        v11 = drm_connector_list_iter_next(v18);
      }
      while ( v11 );
    }
    drm_connector_list_iter_end(v18);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]exit:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    result = sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_clear_edid_cache", 1275, 8, 8738, -1059143953, v12, v13, v17);
  }
  else
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    result = printk(&unk_275B6D, "dp_mst_clear_edid_cache");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
