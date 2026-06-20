__int64 __fastcall cam_vfe_resource_init(__int64 a1)
{
  __int64 v1; // x21
  __int64 result; // x0
  unsigned int v4; // w20
  char v5; // w8
  int v6; // w6
  const char *v7; // x7
  unsigned int v8; // w19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    if ( (unsigned int)(*(_DWORD *)(v1 + 22672) - 1) > 1 )
    {
      result = 0;
    }
    else
    {
      result = cam_vfe_soc_enable_clk(*(_QWORD *)(v1 + 8), "ife_dsp_clk");
      if ( (_DWORD)result )
      {
        v4 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_resource_init",
          2878,
          "VFE:%u failed to enable dsp clk, rc = %d",
          *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
          result);
        result = v4;
      }
    }
    *(_QWORD *)(v1 + 22792) = 0;
    v5 = debug_mdl;
    *(_QWORD *)(v1 + 22784) = 0;
    *(_QWORD *)(v1 + 22776) = 0;
    *(_QWORD *)(v1 + 22768) = 0;
    *(_QWORD *)(v1 + 22760) = 0;
    *(_QWORD *)(v1 + 22752) = 0;
    *(_QWORD *)(v1 + 22744) = 0;
    *(_QWORD *)(v1 + 22736) = 0;
    if ( (v5 & 8) != 0 && !debug_priority )
    {
      v6 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL);
      v7 = (const char *)(a1 + 128);
      v8 = result;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v5 & 8,
        4,
        "cam_vfe_resource_init",
        2892,
        "VFE:%u Res: %s Init Done",
        v6,
        v7);
      return v8;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_resource_init",
      2865,
      "Error Invalid input arguments");
    return 4294967274LL;
  }
  return result;
}
