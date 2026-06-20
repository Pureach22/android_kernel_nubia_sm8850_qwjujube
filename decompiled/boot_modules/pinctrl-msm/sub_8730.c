__int64 sub_8730()
{
  __int64 v0; // x14

  if ( (v0 & 0x1000000000000000LL) != 0 )
    JUMPOUT(0xAB78);
  return msm_spare_write();
}
