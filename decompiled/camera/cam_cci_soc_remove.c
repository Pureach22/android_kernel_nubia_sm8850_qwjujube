__int64 __fastcall cam_cci_soc_remove(__int64 a1, __int64 a2)
{
  return cam_soc_util_release_platform_resource(a2 + 384);
}
