__int64 __fastcall cam_vfe_soc_enable_clk(__int64 a1, char *s1)
{
  __int64 result; // x0
  __int64 v4; // x3
  unsigned int v5; // w19

  if ( a1 )
  {
    if ( !strcmp(s1, "ife_dsp_clk") )
    {
      v4 = *(unsigned int *)(*(_QWORD *)(a1 + 3296) + 12LL);
      if ( (_DWORD)v4 == -1 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_soc_enable_clk",
          330,
          "DSP clock not supported for vfe: %d",
          *(_DWORD *)(a1 + 20));
        return 0xFFFFFFFFLL;
      }
      else
      {
        result = cam_soc_util_clk_enable(a1, 0xFFFFFFFF, 1, v4, 0);
        if ( (_DWORD)result )
        {
          v5 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_soc_enable_clk",
            339,
            "Error enable dsp clk failed rc=%d",
            result);
          return v5;
        }
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_soc_enable_clk",
      321,
      "Error Invalid params");
    return 4294967274LL;
  }
  return result;
}
