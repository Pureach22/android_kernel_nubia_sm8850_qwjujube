__int64 sub_244E68()
{
  __asm { PRFM            #0x16, [X14],#0xE0 }
  return wmi_host_to_fw_phymode();
}
