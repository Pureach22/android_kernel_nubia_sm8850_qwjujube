__int64 __fastcall sub_1AA23C(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21

  if ( (v3 & 0x8000000000LL) != 0 )
    JUMPOUT(0x1AC210);
  return ipa_rm_resource_producer_notify_clients(a1, a2, a3);
}
