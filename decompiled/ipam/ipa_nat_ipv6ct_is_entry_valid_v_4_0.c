bool __fastcall ipa_nat_ipv6ct_is_entry_valid_v_4_0(__int64 a1)
{
  unsigned __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 32);
  return HIBYTE(v1) != 255 && (v1 & 0x80000000) != 0LL;
}
