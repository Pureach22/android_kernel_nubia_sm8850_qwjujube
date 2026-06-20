__int64 __fastcall sde_crtc_hal_funcs_install(_QWORD *a1)
{
  if ( a1 )
  {
    a1[1009] = hfi_crtc_destroy;
    a1[1033] = hfi_crtc_atomic_begin;
    a1[1051] = hfi_crtc_debugfs_misr_setup;
    a1[1054] = hfi_crtc_debugfs_misr_read;
    return 0;
  }
  else
  {
    printk(&unk_211DA1, "_sde_crtc_hal_funcs_install");
    return 4294967274LL;
  }
}
