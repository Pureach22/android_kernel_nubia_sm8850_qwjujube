_DWORD *__fastcall ipa_nat_ipv4_pdn_parse_entry_v_4_0(_DWORD *result, _DWORD *a2)
{
  *result = *a2;
  result[1] = a2[1];
  result[2] = a2[2];
  return result;
}
