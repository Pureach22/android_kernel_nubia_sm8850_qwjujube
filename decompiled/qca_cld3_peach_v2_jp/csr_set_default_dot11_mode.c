__int64 __fastcall csr_set_default_dot11_mode(__int64 a1)
{
  __int64 result; // x0

  result = csr_translate_to_wni_cfg_dot11_mode(a1, *(unsigned int *)(a1 + 17132));
  *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5748LL) = result;
  return result;
}
