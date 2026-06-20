__int64 __fastcall sub_436460(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x17

  if ( (v3 & 0x20000000000000LL) == 0 )
    JUMPOUT(0x43D1E0);
  return sme_update_add_ie(a1, a2, a3);
}
