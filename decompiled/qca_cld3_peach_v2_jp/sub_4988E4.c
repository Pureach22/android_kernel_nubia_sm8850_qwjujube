__int64 __fastcall sub_4988E4(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30

  if ( v3 )
    JUMPOUT(0x4DD09C);
  return wma_mlme_vdev_notify_down_complete(a1, a2, a3);
}
