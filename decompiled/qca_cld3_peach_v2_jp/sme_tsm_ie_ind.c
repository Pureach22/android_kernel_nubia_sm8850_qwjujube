__int64 __fastcall sme_tsm_ie_ind(__int64 a1, __int64 a2)
{
  unsigned int v3; // w19
  __int64 result; // x0
  __int16 v6; // w8
  __int64 v7; // x21

  v3 = *(unsigned __int8 *)(a2 + 4);
  result = _qdf_mem_malloc(0x180u, "sme_tsm_ie_ind", 1633);
  if ( result )
  {
    *(_BYTE *)(result + 98) = *(_BYTE *)a2;
    *(_BYTE *)(result + 99) = *(_BYTE *)(a2 + 1);
    v6 = *(_WORD *)(a2 + 2);
    v7 = result;
    *(_WORD *)(result + 100) = v6;
    csr_roam_call_callback(a1, v3, result, 34, 0);
    return _qdf_mem_free(v7);
  }
  return result;
}
