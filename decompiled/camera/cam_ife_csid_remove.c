__int64 __fastcall cam_ife_csid_remove(__int64 a1)
{
  component_del(a1 + 16, cam_ife_csid_component_ops);
  return cam_soc_util_uninitialize_power_domain(a1 + 16);
}
