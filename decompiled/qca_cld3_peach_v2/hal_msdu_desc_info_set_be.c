void __fastcall hal_msdu_desc_info_set_be(__int64 a1, _DWORD *a2, char a3, __int16 a4)
{
  int v4; // w9

  v4 = a2[1] | a3 & 0x1F;
  *a2 |= (8 * (a4 & 0x3FFF)) | 0xC0003;
  a2[1] = v4;
}
