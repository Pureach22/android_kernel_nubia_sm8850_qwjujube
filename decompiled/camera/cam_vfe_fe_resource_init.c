__int64 __fastcall cam_vfe_fe_resource_init(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  unsigned int v3; // w19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    if ( (unsigned int)(*(_DWORD *)(v1 + 52) - 1) > 1 )
    {
      return 0;
    }
    else
    {
      result = cam_vfe_soc_enable_clk(*(_QWORD *)(v1 + 40), "ife_dsp_clk");
      if ( (_DWORD)result )
      {
        v3 = result;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_fe_resource_init",
          216,
          "failed to enable dsp clk");
        return v3;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_fe_resource_init",
      204,
      "Error Invalid input arguments");
    return 4294967274LL;
  }
  return result;
}
