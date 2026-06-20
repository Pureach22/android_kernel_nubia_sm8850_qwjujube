__int64 __fastcall sub_156460(__int64 a1, __int64 a2)
{
  __int64 v2; // x13

  if ( (v2 & 0x400000000LL) == 0 )
    JUMPOUT(0x150258);
  return cam_cpas_hw_probe(a1, a2);
}
