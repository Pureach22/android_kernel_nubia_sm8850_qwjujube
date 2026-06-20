__int64 __fastcall cam_subdev_subscribe_event(__int64 a1, __int64 a2, __int64 a3)
{
  return v4l2_event_subscribe(a2, a3, 30, 0);
}
