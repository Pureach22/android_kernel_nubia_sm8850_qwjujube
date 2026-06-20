__int64 __fastcall populate_dot11f_wmm_caps(__int64 result)
{
  char v1; // w9

  v1 = *(_BYTE *)(result + 2) & 0xF | 0x20;
  *(_WORD *)result = 257;
  *(_BYTE *)(result + 2) = v1;
  return result;
}
