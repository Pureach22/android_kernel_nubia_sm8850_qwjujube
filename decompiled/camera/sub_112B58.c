__int64 sub_112B58()
{
  __asm { STTR            X15, [X13,#0x73] }
  return cam_soc_util_power_domain_set_mode();
}
