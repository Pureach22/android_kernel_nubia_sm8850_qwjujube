bool __fastcall valid_wmm(_BYTE *a1)
{
  return -1 << (*a1 >> 4) > (unsigned int)(-1 << (*a1 & 0xF))
      && a1[1]
      && -1 << (a1[4] >> 4) > (unsigned int)(-1 << (a1[4] & 0xF))
      && a1[5]
      && -1 << (a1[8] >> 4) > (unsigned int)(-1 << (a1[8] & 0xF))
      && a1[9]
      && -1 << (a1[12] >> 4) > (unsigned int)(-1 << (a1[12] & 0xF))
      && a1[13]
      && -1 << (a1[16] >> 4) > (unsigned int)(-1 << (a1[16] & 0xF))
      && a1[17]
      && -1 << (a1[20] >> 4) > (unsigned int)(-1 << (a1[20] & 0xF))
      && a1[21]
      && -1 << (a1[24] >> 4) > (unsigned int)(-1 << (a1[24] & 0xF))
      && a1[25]
      && -1 << (a1[28] >> 4) > (unsigned int)(-1 << (a1[28] & 0xF))
      && a1[29] != 0;
}
