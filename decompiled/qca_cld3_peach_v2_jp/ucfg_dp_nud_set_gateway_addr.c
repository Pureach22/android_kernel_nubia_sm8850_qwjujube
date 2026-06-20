__int64 __fastcall ucfg_dp_nud_set_gateway_addr(__int64 a1, __int64 a2)
{
  return dp_nud_set_gateway_addr(a1, a2 & 0xFFFFFFFFFFFFLL);
}
