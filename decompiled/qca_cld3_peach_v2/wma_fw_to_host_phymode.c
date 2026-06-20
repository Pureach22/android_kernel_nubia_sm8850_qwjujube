__int64 __fastcall wma_fw_to_host_phymode(__int64 a1, __int64 a2)
{
  unsigned int v3; // w8

  if ( (unsigned int)a1 < 0xE )
    return dword_B0A4BC[(unsigned int)a1];
  if ( (_DWORD)a1 == 15 )
    v3 = 19;
  else
    v3 = 0;
  if ( (_DWORD)a1 == 14 )
    v3 = 20;
  if ( v3 )
    return v3;
  if ( (unsigned int)(a1 - 16) >= 8 )
    return wma_fw_to_host_phymode_11be(a1, a2);
  return dword_B35628[(unsigned int)(a1 - 16)];
}
