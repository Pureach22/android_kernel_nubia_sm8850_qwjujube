__int64 __fastcall cam_csiphy_component_unbind(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  const char *v5; // x5
  __int64 v6; // x4

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 240);
    if ( v2 )
    {
      root_dentry = 0;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000,
        3,
        "cam_csiphy_component_unbind",
        686,
        "Unbind CSIPHY component");
      cam_cpas_unregister_client(*(_DWORD *)(v2 + 88));
      cam_csiphy_soc_release(v2);
      mutex_lock(v2 + 24);
      cam_csiphy_shutdown(v2);
      mutex_unlock(v2 + 24);
      cam_unregister_subdev(v2 + 128);
      *(_QWORD *)(a1 + 152) = 0;
      *(_QWORD *)(v2 + 376) = 0;
      return devm_kfree(a1);
    }
    v5 = "Error No data in csiphy_dev";
    v6 = 676;
  }
  else
  {
    v5 = "Error No data in subdev";
    v6 = 669;
  }
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           0x8000,
           1,
           "cam_csiphy_component_unbind",
           v6,
           v5);
}
