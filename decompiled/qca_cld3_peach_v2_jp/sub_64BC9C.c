__int64 __fastcall sub_64BC9C(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x29

  if ( (v3 & 0x20000000000LL) == 0 )
    JUMPOUT(0x64E53C);
  return ucfg_twt_requestor_disable(a1, a2, a3);
}
