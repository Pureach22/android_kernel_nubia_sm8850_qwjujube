__int64 __fastcall sub_7150F0(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x71C0C4);
  return ucfg_fwol_get_enable_secondary_rate(a1, a2);
}
