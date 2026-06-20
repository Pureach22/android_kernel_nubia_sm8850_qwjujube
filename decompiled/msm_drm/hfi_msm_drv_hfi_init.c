__int64 __fastcall hfi_msm_drv_hfi_init(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0

  v1 = *(_QWORD *)(a1 + 5920);
  if ( v1 )
  {
    v2 = hfi_adapter_init(1);
    *(_QWORD *)(v1 + 8) = v2;
    if ( v2 )
    {
      _drm_dev_dbg(0, 0, 0, "success to initialize HFI adapter: %d\n", 0);
      return 0;
    }
    _drm_err("failed to initialize HFI adapter: %d\n", -22);
  }
  return 4294967274LL;
}
