__int64 sub_1530F0()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cam_cpas_is_fw_based_sys_caching_supported();
}
