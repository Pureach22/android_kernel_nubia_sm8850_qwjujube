double __fastcall dsi_display_manager_register(__int64 a1)
{
  __int64 v1; // x20
  __int64 *v3; // x0
  __int64 v4; // x2
  double result; // d0
  __int64 v6; // x8
  __int64 *v7; // x22

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 2212LL) & 1) == 0 )
    return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: no need of a mgr\n");
  v1 = *(_QWORD *)(a1 + 168);
  if ( (byte_29BAF8 & 1) == 0 )
  {
    disp_mgr = (__int64)&disp_mgr;
    qword_29BAC0 = (__int64)&disp_mgr;
    _mutex_init(&unk_29BAC8, "&disp_mgr.disp_mgr_mutex", &dsi_display_manager_init___key);
    byte_29BAF8 = 1;
  }
  v3 = (__int64 *)(a1 + 48);
  v4 = disp_mgr;
  if ( disp_mgr == a1 + 48 || v3 == &disp_mgr || *(__int64 **)(disp_mgr + 8) != &disp_mgr )
  {
    _list_add_valid_or_report(v3, &disp_mgr);
  }
  else
  {
    *(_QWORD *)(disp_mgr + 8) = v3;
    *(_QWORD *)(a1 + 48) = v4;
    *(_QWORD *)(a1 + 56) = &disp_mgr;
    disp_mgr = a1 + 48;
  }
  result = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: cell_index = %d\n", *(_DWORD *)(v1 + 8));
  if ( !*(_DWORD *)(v1 + 8) )
    *(_BYTE *)(a1 + 848) = 1;
  v6 = disp_mgr;
  if ( (__int64 *)disp_mgr != &disp_mgr )
  {
    do
    {
      v7 = *(__int64 **)v6;
      drm_dev_printk(
        0,
        &unk_2597DF,
        "[msm-dsi-info]: display name: %s type: %s\n",
        **(const char ***)(v6 + 216),
        *(const char **)(*(_QWORD *)(v6 + 216) + 8LL));
      v6 = (__int64)v7;
    }
    while ( v7 != &disp_mgr );
  }
  return result;
}
