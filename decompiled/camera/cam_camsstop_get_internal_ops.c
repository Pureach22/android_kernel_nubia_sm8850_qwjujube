__int64 __fastcall cam_camsstop_get_internal_ops(_QWORD *a1)
{
  if ( a1 )
  {
    a1[2] = 0;
    a1[3] = cam_camsstop_setup_regbase_indices;
    a1[4] = 0;
    a1[5] = 0;
    *a1 = cam_camsstop_get_hw_info;
    a1[1] = 0;
    a1[6] = 0;
    a1[7] = 0;
    a1[8] = 0;
    a1[9] = 0;
    a1[10] = 0;
    a1[11] = 0;
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_camsstop_get_internal_ops",
      71,
      "invalid NULL param");
    return 4294967274LL;
  }
}
