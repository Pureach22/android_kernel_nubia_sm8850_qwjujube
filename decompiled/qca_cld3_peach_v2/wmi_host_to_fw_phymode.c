__int64 __fastcall wmi_host_to_fw_phymode(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x27 )
    return 33;
  else
    return dword_AD8F10[a1 - 1];
}
