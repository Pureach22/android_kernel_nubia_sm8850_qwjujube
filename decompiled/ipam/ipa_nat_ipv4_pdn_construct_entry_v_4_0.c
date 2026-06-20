_DWORD *__fastcall ipa_nat_ipv4_pdn_construct_entry_v_4_0(_DWORD *result, __int64 a2)
{
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_DWORD *)a2 = *result;
  *(_DWORD *)(a2 + 4) = result[1];
  *(_DWORD *)(a2 + 8) = result[2];
  return result;
}
