__int64 __fastcall msm_sharedmem_remove(__int64 a1)
{
  return uio_unregister_device(*(_QWORD *)(a1 + 168));
}
