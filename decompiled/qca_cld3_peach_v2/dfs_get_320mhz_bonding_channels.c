__int64 __fastcall dfs_get_320mhz_bonding_channels(__int64 result, _WORD *a2, _BYTE *a3)
{
  *a3 = 12;
  *a2 = result - 150;
  a2[2] = result - 110;
  a2[3] = result - 90;
  a2[4] = result - 70;
  a2[5] = result - 50;
  a2[6] = result - 30;
  a2[7] = result - 10;
  a2[8] = result + 10;
  a2[9] = result + 30;
  a2[10] = result + 50;
  a2[11] = result + 70;
  a2[12] = result + 90;
  a2[13] = result + 110;
  a2[14] = result + 130;
  a2[1] = result - 130;
  a2[15] = result + 150;
  return result;
}
