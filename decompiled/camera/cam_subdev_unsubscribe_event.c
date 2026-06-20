__int64 __fastcall cam_subdev_unsubscribe_event(__int64 a1, __int64 a2, __int64 a3)
{
  return v4l2_event_unsubscribe(a2, a3);
}
