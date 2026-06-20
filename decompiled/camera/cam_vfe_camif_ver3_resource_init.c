__int64 __fastcall cam_vfe_camif_ver3_resource_init(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  unsigned int v3; // w19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    if ( (unsigned int)(*(_DWORD *)(v1 + 22688) - 1) > 1 )
    {
      result = 0;
    }
    else
    {
      result = cam_vfe_soc_enable_clk(*(_QWORD *)(v1 + 40), "ife_dsp_clk");
      if ( (_DWORD)result )
      {
        v3 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_camif_ver3_resource_init",
          327,
          "failed to enable dsp clk, rc = %d",
          result);
        result = v3;
      }
    }
    *(_QWORD *)(v1 + 22808) = 0;
    *(_QWORD *)(v1 + 22800) = 0;
    *(_QWORD *)(v1 + 22792) = 0;
    *(_QWORD *)(v1 + 22784) = 0;
    *(_QWORD *)(v1 + 22776) = 0;
    *(_QWORD *)(v1 + 22768) = 0;
    *(_QWORD *)(v1 + 22760) = 0;
    *(_QWORD *)(v1 + 22752) = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_resource_init",
      313,
      "Error Invalid input arguments");
    return 4294967274LL;
  }
  return result;
}
