__int64 __fastcall sub_69E0(__int64 a1, __int64 a2)
{
  __int64 v2; // x20

  if ( (v2 & 0x2000000000000000LL) == 0 )
    JUMPOUT(0xA848);
  return qfprom_read(a1, a2);
}
