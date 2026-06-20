__int64 sub_2256E8()
{
  __asm { PRFM            #0x16, [X14],#0xE0 }
  return wmi_host_to_fw_phymode();
}
