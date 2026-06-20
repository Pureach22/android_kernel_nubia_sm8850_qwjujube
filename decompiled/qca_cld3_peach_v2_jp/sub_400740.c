__int64 __fastcall sub_400740(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x15
  __int64 v4; // x20

  return dot11f_pack_link_recfg_req(a1, a2, a3, v4 ^ ~__ROR8__(v3, 62));
}
