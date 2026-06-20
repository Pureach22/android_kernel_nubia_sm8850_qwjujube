__int64 __fastcall wmi_host_to_fw_phymode(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x1D )
    return 24;
  else
    return dword_9E70C0[a1 - 1];
}
