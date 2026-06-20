__int64 __fastcall ipa_nat_ipv4_index_stringify_entry_v_3_0(unsigned __int16 *a1, __int64 a2, __int64 a3)
{
  return scnprintf(a2, a3, "\t\tTable_Entry=%d  Next_Index=%d\n", *a1, a1[1]);
}
