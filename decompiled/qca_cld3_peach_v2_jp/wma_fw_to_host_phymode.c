__int64 __fastcall wma_fw_to_host_phymode(unsigned int a1)
{
  unsigned int v2; // w8

  if ( a1 < 0xE )
    return dword_A18364[a1];
  if ( a1 == 15 )
    v2 = 19;
  else
    v2 = 0;
  if ( a1 == 14 )
    v2 = 20;
  if ( v2 )
    return v2;
  if ( a1 - 16 >= 8 )
    return 0;
  return dword_A30230[a1 - 16];
}
