__int64 __fastcall sub_1976D8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( (a5 & 0x4000000000LL) != 0 )
    JUMPOUT(0x1918BC);
  return target_if_vdev_mgr_fils_enable_send();
}
