__int64 __fastcall cam_cci_component_unbind(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v4; // x21
  const char *v6; // x5
  __int64 v7; // x4

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
  {
    v6 = "Error No data in subdev";
    v7 = 801;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x4000,
             1,
             "cam_cci_component_unbind",
             v7,
             v6);
  }
  v2 = *(_QWORD *)(v1 + 240);
  if ( !v2 )
  {
    v6 = "Error No data in cci_dev";
    v7 = 807;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x4000,
             1,
             "cam_cci_component_unbind",
             v7,
             v6);
  }
  v4 = a1 - 16;
  cam_cpas_unregister_client(*(_DWORD *)(v2 + 5816));
  debugfs_root_0 = 0;
  cam_cci_soc_remove(v4, v2);
  if ( (cam_unregister_subdev(v2 + 5312) & 0x80000000) != 0 )
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_component_unbind",
      821);
  return devm_kfree(a1);
}
