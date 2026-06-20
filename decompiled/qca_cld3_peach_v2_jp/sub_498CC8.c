__int64 __fastcall sub_498CC8(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30

  if ( v3 )
    JUMPOUT(0x4DD480);
  return wma_mon_mlme_vdev_up_send(a1, a2, a3);
}
