void __fastcall lim_update_vhtcaps_assoc_resp(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w9
  unsigned int v4; // w11
  unsigned int v5; // w8

  v3 = *(unsigned __int8 *)(a3 + 3);
  v4 = *(unsigned __int16 *)(a3 + 4);
  v5 = (((v3 >> 6) & 1) << 22) & 0xFC7FFFFF
     | ((v4 & 7) << 23)
     | *(unsigned __int16 *)(a3 + 1)
     | ((v3 & 7) << 16) & 0xFFC7FFFF
     | (((v3 >> 3) & 1) << 19) & 0xFFCFFFFF
     | (((v3 >> 4) & 1) << 20) & 0xFFDFFFFF
     | (((v3 >> 5) & 1) << 21);
  *(_DWORD *)(a2 + 176) = (v4 << 23) & 0xC0000000
                        | (((v4 >> 6) & 1) << 29)
                        | (((v4 >> 5) & 1) << 28)
                        | (((v4 >> 3) & 3) << 26)
                        | v5;
  *(_BYTE *)(a2 + 56) = v5 >> 23;
}
