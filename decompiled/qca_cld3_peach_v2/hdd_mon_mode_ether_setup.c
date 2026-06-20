__int64 *__fastcall hdd_mon_mode_ether_setup(__int64 *result)
{
  __int64 v1; // x9

  result[2] = 0;
  *((_WORD *)result + 272) = 803;
  *((_DWORD *)result + 14) = 1500;
  *((_WORD *)result + 90) = 14;
  v1 = *result;
  *((_BYTE *)result + 824) = 6;
  *((_DWORD *)result + 278) = 1000;
  *((_DWORD *)result + 44) = 4098;
  *result = v1 | 0x800;
  *((_DWORD *)result + 260) = -1;
  *((_WORD *)result + 522) = -1;
  return result;
}
