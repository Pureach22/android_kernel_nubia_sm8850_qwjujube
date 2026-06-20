__int64 __fastcall ipa_nat_ipv6ct_stringify_entry_v_4_5(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w0
  const char *v7; // x3
  const char *v8; // x4

  v6 = ipa_nat_ipv6ct_stringify_entry_v_4_0(a1, a2, a3);
  if ( (*(_QWORD *)(a1 + 40) & 0x1000000000000LL) != 0 )
    v7 = "Enabled";
  else
    v7 = "Disabled";
  if ( (*(_QWORD *)(a1 + 32) & 0x2000LL) != 0 )
    v8 = "System";
  else
    v8 = "Local";
  return (unsigned int)scnprintf(
                         a2 + v6,
                         a3 - v6,
                         "\t\tucp=%s address=%s uc_activation_index=%d\n",
                         v7,
                         v8,
                         *(_QWORD *)(a1 + 32) & 0x1FFFLL)
       + v6;
}
