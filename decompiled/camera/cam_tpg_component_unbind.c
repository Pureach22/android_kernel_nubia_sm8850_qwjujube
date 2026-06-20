__int64 __fastcall cam_tpg_component_unbind(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x200000000LL,
             1,
             "cam_tpg_component_unbind",
             388,
             "Error No data in tpg_dev");
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "cam_tpg_component_unbind",
    392,
    "Unbind TPG component");
  cam_cpas_unregister_client(*(_DWORD *)(v1 + 4120));
  cam_soc_util_release_platform_resource(v1 + 544);
  *(_QWORD *)(a1 + 152) = 0;
  *(_QWORD *)(v1 + 320) = 0;
  return cam_unregister_subdev(v1 + 72);
}
