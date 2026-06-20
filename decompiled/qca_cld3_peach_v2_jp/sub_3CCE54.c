__int64 __fastcall sub_3CCE54(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30

  if ( v3 )
    JUMPOUT(0x41160C);
  return lim_sta_mlme_vdev_stop_send(a1, a2, a3);
}
