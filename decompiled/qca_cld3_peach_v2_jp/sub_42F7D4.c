__int64 __fastcall sub_42F7D4(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x28

  if ( (v3 & 0x100000000000LL) != 0 )
    JUMPOUT(0x436F4C);
  return sme_oem_data_cmd(a1, a2, a3);
}
