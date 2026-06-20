__int64 __fastcall sme_unprotected_mgmt_frm_ind(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v3; // w19
  __int64 result; // x0
  int v6; // w8
  __int64 v7; // x21

  v3 = *a2;
  result = _qdf_mem_malloc(0x180u, "sme_unprotected_mgmt_frm_ind", 1372);
  if ( result )
  {
    v6 = a2[2];
    *(_QWORD *)(result + 8) = a2 + 3;
    *(_DWORD *)result = v6;
    LOBYTE(v6) = a2[1];
    v7 = result;
    *(_BYTE *)(result + 4) = v6;
    csr_roam_call_callback(a1, v3, result, 33, 0);
    return _qdf_mem_free(v7);
  }
  return result;
}
