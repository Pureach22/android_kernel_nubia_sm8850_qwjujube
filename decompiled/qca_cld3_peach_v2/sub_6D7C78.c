__int64 __fastcall sub_6D7C78(__int64 a1, __int64 a2, __int64 a3)
{
  __int16 v3; // w30

  if ( (v3 & 0x4000) == 0 )
    JUMPOUT(0x6DE4F0);
  return ml_nlink_convert_vdev_ids_to_link_bitmap(a1, a2, a3);
}
