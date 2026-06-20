__int64 __fastcall cam_vfe_top_release(__int64 a1, __int64 a2)
{
  unsigned int v2; // w6
  __int64 v4; // [xsp+8h] [xbp-8h]

  if ( a1 && a2 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v4 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_top_release",
        578,
        "Resource in state %d",
        *(_DWORD *)(a2 + 8));
      a2 = v4;
    }
    v2 = *(_DWORD *)(a2 + 8);
    if ( v2 > 1 )
    {
      *(_DWORD *)(a2 + 8) = 1;
      return 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_release",
        581,
        "Error! Resource in Invalid res_state :%d",
        v2);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_release",
      572,
      "Error! Invalid input arguments");
    return 4294967274LL;
  }
}
