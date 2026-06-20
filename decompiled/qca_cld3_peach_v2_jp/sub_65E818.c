__int64 __fastcall sub_65E818(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x6657EC);
  return ucfg_fwol_get_enable_secondary_rate(a1, a2);
}
