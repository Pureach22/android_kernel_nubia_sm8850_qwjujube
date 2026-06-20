void __fastcall convert_erp_info(__int64 a1, _BYTE *a2, __int64 a3)
{
  int v3; // w9
  unsigned int v4; // w9

  v3 = *a2 & 0xFE | *(_BYTE *)(a3 + 1) & 1;
  *a2 = v3;
  v4 = v3 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a3 + 1) >> 1) & 1));
  *a2 = v4;
  *a2 = v4 & 0xFB | *(_BYTE *)(a3 + 1) & 4;
}
