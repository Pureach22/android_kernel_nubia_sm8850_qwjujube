__int64 __fastcall wma_fw_to_host_phymode_11be(int a1)
{
  if ( (unsigned int)(a1 - 24) > 8 )
    return 0;
  else
    return dword_B0A4F4[a1 - 24];
}
