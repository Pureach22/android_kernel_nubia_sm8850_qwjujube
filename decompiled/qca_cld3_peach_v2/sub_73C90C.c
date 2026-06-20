__int64 __fastcall sub_73C90C(__int64 a1, __int64 a2)
{
  __int64 v2; // x19

  if ( (v2 & 0x2000000000LL) != 0 )
    JUMPOUT(0x73A80C);
  return wmi_unified_set_del_pmkid_cache(a1, a2);
}
