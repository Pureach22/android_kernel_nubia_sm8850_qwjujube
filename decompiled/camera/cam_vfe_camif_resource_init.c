__int64 __fastcall cam_vfe_camif_resource_init(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  unsigned int v3; // w20

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    if ( (unsigned int)(*(_DWORD *)(v1 + 22632) - 1) > 1 )
    {
      result = 0;
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
          "cam_vfe_camif_resource_init",
          309,
          "failed to enable dsp clk");
        result = v3;
      }
    }
    *(_QWORD *)(v1 + 22744) = 0;
    *(_QWORD *)(v1 + 22736) = 0;
    *(_QWORD *)(v1 + 22728) = 0;
    *(_QWORD *)(v1 + 22720) = 0;
    *(_QWORD *)(v1 + 22712) = 0;
    *(_QWORD *)(v1 + 22704) = 0;
    *(_QWORD *)(v1 + 22696) = 0;
    *(_QWORD *)(v1 + 22688) = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_resource_init",
      297,
      "Error Invalid input arguments");
    return 4294967274LL;
  }
  return result;
}
