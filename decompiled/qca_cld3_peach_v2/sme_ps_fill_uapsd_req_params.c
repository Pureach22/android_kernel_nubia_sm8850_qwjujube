__int64 __fastcall sme_ps_fill_uapsd_req_params(__int64 result, _BYTE *a2, unsigned int a3, _DWORD *a4)
{
  __int64 v4; // x8
  unsigned int v5; // w10
  unsigned int v6; // w11

  v4 = result + 192LL * a3;
  v5 = *(unsigned __int8 *)(v4 + 13212);
  v6 = *(unsigned __int8 *)(v4 + 13209) | v5;
  *a2 = (2 * v6) & 4
      | (v6 >> 2) & 3
      | (8 * (v6 & 1)) & 0x8F
      | ((*(_BYTE *)(v4 + 13208) | (unsigned __int8)v5) << 7)
      | (16 * (((*(unsigned __int8 *)(v4 + 13208) | v5) >> 2) & 3)) & 0xBF
      | ((((*(unsigned __int8 *)(v4 + 13208) | v5) & 2) != 0) << 6);
  LODWORD(v4) = *(_DWORD *)(v4 + 13204) != 0;
  a2[1] = v4;
  *a4 = 2 * v4;
  return result;
}
