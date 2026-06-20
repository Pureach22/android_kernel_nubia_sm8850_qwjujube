__int64 __fastcall cam_ife_hw_mgr_acquire_res_sfe_out(__int64 a1, __int64 a2)
{
  __int64 *v2; // x20
  __int64 *v3; // x22
  __int64 result; // x0
  int v7; // w6

  v3 = (__int64 *)(a1 + 240);
  v2 = *(__int64 **)(a1 + 240);
  if ( v2 != (__int64 *)(a1 + 240) )
  {
    while ( 1 )
    {
      if ( *((_DWORD *)v2 + 27) )
        goto LABEL_9;
      v7 = *((_DWORD *)v2 + 5);
      if ( (unsigned int)(v7 - 1) >= 3 )
      {
        if ( (unsigned int)(v7 - 4) < 2 )
        {
          result = cam_ife_hw_mgr_acquire_res_sfe_out_rdi(a1, v2, a2);
          if ( (_DWORD)result )
            return result;
          goto LABEL_9;
        }
        if ( v7 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_acquire_res_sfe_out",
            3322,
            "Unknown SFE IN resource: %d, ctx_idx: %u",
            v7,
            *(_DWORD *)(a1 + 56));
          return 4294967274LL;
        }
      }
      else
      {
        result = cam_ife_hw_mgr_acquire_res_sfe_out_rdi(a1, v2, a2);
        if ( (_DWORD)result )
          return result;
        if ( *(_BYTE *)(a1 + 9378) != 1 )
          goto LABEL_9;
      }
      result = cam_ife_hw_mgr_acquire_res_sfe_out_pix(a1, v2, a2);
      if ( (_DWORD)result )
        return result;
LABEL_9:
      v2 = (__int64 *)*v2;
      if ( v2 == v3 )
        return 0;
    }
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    2,
    "cam_ife_hw_mgr_acquire_res_sfe_out",
    3288,
    "SFE src list empty");
  return 0;
}
