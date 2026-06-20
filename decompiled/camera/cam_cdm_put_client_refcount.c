__int64 __fastcall cam_cdm_put_client_refcount(__int64 a1)
{
  int v2; // w8

  mutex_lock(a1 + 280);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_put_client_refcount",
      69,
      "CDM client put refcount=%d",
      *(_DWORD *)(a1 + 276));
    v2 = *(_DWORD *)(a1 + 276);
    if ( v2 )
      goto LABEL_4;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_put_client_refcount",
      73,
      "Refcount put when zero");
    __break(0x800u);
    return mutex_unlock(a1 + 280);
  }
  v2 = *(_DWORD *)(a1 + 276);
  if ( !v2 )
    goto LABEL_6;
LABEL_4:
  *(_DWORD *)(a1 + 276) = v2 - 1;
  return mutex_unlock(a1 + 280);
}
