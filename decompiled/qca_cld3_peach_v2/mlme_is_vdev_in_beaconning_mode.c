__int64 __fastcall mlme_is_vdev_in_beaconning_mode(int a1)
{
  unsigned __int64 v1; // t2

  HIDWORD(v1) = a1 - 1;
  LODWORD(v1) = a1 - 1;
  return ((unsigned int)(v1 >> 1) < 6) & (0x27u >> (v1 >> 1));
}
