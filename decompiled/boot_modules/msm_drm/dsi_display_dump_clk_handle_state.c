__int64 __fastcall dsi_display_dump_clk_handle_state(__int64 a1)
{
  __int64 v1; // x19

  if ( a1 && (v1 = *(_QWORD *)(a1 + 80)) != 0 )
  {
    if ( *(_DWORD *)(v1 + 384) != 1 )
    {
      mutex_lock(v1 + 32);
      drm_dev_printk(
        0,
        &unk_2597DF,
        "[msm-dsi-info]: [%s]%s: Core (ref=%d, state=%d), Link (ref=%d, state=%d)\n",
        (const char *)v1,
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 48),
        *(_DWORD *)(a1 + 36),
        *(_DWORD *)(a1 + 52));
      mutex_unlock(v1 + 32);
    }
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
}
