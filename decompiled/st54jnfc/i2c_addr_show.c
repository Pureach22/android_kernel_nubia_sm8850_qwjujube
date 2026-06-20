__int64 __fastcall i2c_addr_show(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a1 == 32 )
    return -19;
  else
    return (int)scnprintf(a3, 4096, "0x%.2x\n", *(unsigned __int16 *)(a1 - 30));
}
