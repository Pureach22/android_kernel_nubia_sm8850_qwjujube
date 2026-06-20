__int64 __fastcall cam_cpas_subdev_register(__int64 a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  unsigned int v3; // w19

  v1 = g_cpas_intf;
  if ( !g_cpas_intf )
    return 4294967274LL;
  *(_QWORD *)(g_cpas_intf + 416) = "cam-cpas";
  *(_QWORD *)(v1 + 432) = v1;
  *(_QWORD *)(v1 + 400) = &cpas_subdev_ops;
  *(_QWORD *)(v1 + 408) = &cpas_subdev_intern_ops;
  *(_DWORD *)(v1 + 424) = 12;
  *(_QWORD *)(v1 + 8) = a1;
  *(_DWORD *)(v1 + 440) = 65543;
  *(_DWORD *)(v1 + 472) = 3;
  result = cam_register_subdev(v1 + 8);
  if ( (_DWORD)result )
  {
    v3 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_subdev_register",
      2055,
      "failed register subdev: %s!",
      "cam-cpas");
    return v3;
  }
  else
  {
    *(_QWORD *)(*(_QWORD *)g_cpas_intf + 168LL) = g_cpas_intf;
  }
  return result;
}
