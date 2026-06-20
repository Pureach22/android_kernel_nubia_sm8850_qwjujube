__int64 __fastcall cam_ife_mgr_apply_fcg_update(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v6; // x22
  unsigned int v7; // w0
  __int64 v8; // x6
  const char *v9; // x5
  unsigned int v10; // w19
  __int64 v11; // x4
  __int64 result; // x0
  __int64 v13; // x21
  __int64 v14; // [xsp+8h] [xbp-8h]

  v3 = a2 + 4096;
  if ( *(_BYTE *)(a2 + 4362) == 1 && (*(_BYTE *)(a2 + 4360) & 1) == 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v14 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_apply_fcg_update",
        7827,
        "Start writing IFE/MC_TFE FCG configs to kmd buffer on ctx: %d",
        *(_DWORD *)(a1 + 56));
      a2 = v14;
    }
    v6 = a2;
    v7 = cam_isp_blob_fcg_update(a2 + 4336, *(unsigned int *)(a2 + 4328), *(unsigned int *)(a2 + 4296), a1 + 224, a3);
    a2 = v6;
    if ( v7 )
    {
      v8 = *(unsigned int *)(a1 + 56);
      v9 = "Failed in applying IFE/MC_TFE FCG configurations, ctx_idx: %u";
      v10 = v7;
      v11 = 7837;
LABEL_16:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_apply_fcg_update",
        v11,
        v9,
        v8);
      return v10;
    }
  }
  if ( *(_BYTE *)(v3 + 265) != 1 || (*(_BYTE *)(v3 + 264) & 1) != 0 )
    return 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v13 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_apply_fcg_update",
      7845,
      "Start writing SFE FCG configs to kmd buffer on ctx: %d",
      *(_DWORD *)(a1 + 56));
    a2 = v13;
  }
  result = cam_isp_blob_fcg_update(a2 + 4304, *(unsigned int *)(a2 + 4300), *(unsigned int *)(a2 + 4296), a1 + 240, a3);
  if ( (_DWORD)result )
  {
    v8 = *(unsigned int *)(a1 + 56);
    v9 = "Failed in applying SFE FCG configurations, ctx_idx: %u";
    v10 = result;
    v11 = 7855;
    goto LABEL_16;
  }
  return result;
}
