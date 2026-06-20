__int64 __fastcall ddrllcc_fp_commit(__int64 a1, _DWORD *a2, unsigned int a3)
{
  __int64 *v3; // x21
  char v4; // w22
  __int64 v6; // x20
  __int64 result; // x0
  unsigned int v8; // w19

  v3 = *(__int64 **)(a1 + 120);
  v4 = a3;
  v6 = *v3;
  if ( (a3 & 1) != 0 )
    *((_DWORD *)v3 + 15) = ((unsigned int)(*((_DWORD *)v3 + 8) * *a2) / *((_DWORD *)v3 + 7)) & 0x3FFF | 0x60000000;
  if ( (a3 & 2) != 0 )
    *((_DWORD *)v3 + 18) = ((unsigned int)(*((_DWORD *)v3 + 12) * a2[3]) / *((_DWORD *)v3 + 11)) & 0x3FFF | 0x60000000;
  result = rpmh_update_fast_path(v6, v3 + 7, 2, a3);
  if ( (result & 0x80000000) != 0 )
  {
    v8 = result;
    dev_err(v6, "Error updating RPMH fast path: %d\n", result);
    return v8;
  }
  else
  {
    if ( (v4 & 1) != 0 )
      *(_DWORD *)(v3[1] + 24) = *a2;
    if ( (v4 & 2) != 0 )
      *(_DWORD *)(v3[2] + 24) = a2[3];
  }
  return result;
}
