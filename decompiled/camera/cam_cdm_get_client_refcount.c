__int64 __fastcall cam_cdm_get_client_refcount(__int64 a1)
{
  mutex_lock(a1 + 280);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_get_client_refcount",
      60,
      "CDM client get refcount=%d",
      *(_DWORD *)(a1 + 276));
  ++*(_DWORD *)(a1 + 276);
  return mutex_unlock(a1 + 280);
}
