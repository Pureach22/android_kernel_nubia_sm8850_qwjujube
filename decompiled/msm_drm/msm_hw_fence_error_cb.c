__int64 __fastcall msm_hw_fence_error_cb(unsigned int a1, int a2, int **a3)
{
  int v7; // w7
  size_t v8; // x0
  int v9; // w2
  int v10; // w4
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  sde_evtlog_log(sde_dbg_base_evtlog, "msm_hw_fence_error_cb", 143, -1, a1, a2, 4369, -1059143953, vars0);
  if ( !a3 )
  {
    printk(&unk_25BE5B, "msm_hw_fence_error_cb");
    v8 = sde_dbg_base_evtlog;
    v9 = 148;
    v10 = 13107;
    return sde_evtlog_log(v8, "msm_hw_fence_error_cb", v9, -1, v10, 60333, -1059143953, v7, vars0a);
  }
  if ( !*a3 )
  {
    printk(&unk_26686C, "msm_hw_fence_error_cb");
    v8 = sde_dbg_base_evtlog;
    v9 = 155;
    v10 = 17476;
    return sde_evtlog_log(v8, "msm_hw_fence_error_cb", v9, -1, v10, 60333, -1059143953, v7, vars0a);
  }
  return sde_encoder_handle_hw_fence_error(**a3, *((_QWORD *)*a3 + 1), a1, a2);
}
