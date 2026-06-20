__int64 __fastcall hdd_translate_sae_rsn_to_csr_auth(const void *a1, int *a2)
{
  __int64 result; // x0
  int v5; // w8

  result = qdf_mem_cmp(a1, &ccp_rsn_oui_80, 4u);
  if ( (_DWORD)result )
  {
    result = qdf_mem_cmp(a1, &ccp_rsn_oui_90, 4u);
    if ( (_DWORD)result )
      return result;
    v5 = 27;
  }
  else
  {
    v5 = 3;
  }
  *a2 = v5;
  return result;
}
