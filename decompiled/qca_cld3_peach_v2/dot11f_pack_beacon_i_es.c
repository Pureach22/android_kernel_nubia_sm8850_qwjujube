__int64 __fastcall dot11f_pack_beacon_i_es(__int64 a1, __int64 a2, char *a3, unsigned int a4, _DWORD *a5)
{
  *a5 = 0;
  return pack_core(a1, a2, a3, a4, a5, (__int64)&FFS_BeaconIEs, IES_BeaconIEs);
}
