__int64 __fastcall ipa_nat_ipv4_pdn_stringify_entry_v_4_0(_DWORD *a1, __int64 a2, __int64 a3)
{
  return scnprintf(a2, a3, "ip=%pI4h src_metadata=0x%X, dst_metadata=0x%X\n", a1, a1[1], a1[2]);
}
