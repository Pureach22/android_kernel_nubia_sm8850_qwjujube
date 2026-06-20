__int64 __fastcall cam_vfe_resource_deinit(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  unsigned int v4; // w20
  int v5; // w6
  const char *v6; // x7
  unsigned int v7; // w19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    if ( (unsigned int)(*(_DWORD *)(v1 + 22672) - 1) > 1 )
    {
      result = 0;
    }
    else
    {
      result = cam_vfe_soc_disable_clk(*(_QWORD *)(v1 + 8), "ife_dsp_clk");
      if ( (_DWORD)result )
      {
        v4 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_resource_deinit",
          2918,
          "VFE:%u failed to disable dsp clk",
          *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
        result = v4;
      }
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v5 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL);
      v6 = (const char *)(a1 + 128);
      v7 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_resource_deinit",
        2923,
        "VFE:%u Res: %s DeInit Done",
        v5,
        v6);
      return v7;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_resource_deinit",
      2906,
      "Error Invalid input arguments");
    return 4294967274LL;
  }
  return result;
}
