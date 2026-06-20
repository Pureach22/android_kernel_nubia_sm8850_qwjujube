__int64 __fastcall cam_subscribe_event(__int64 a1, __int64 a2)
{
  dword_2FDAA0 |= 1 << *(_DWORD *)(a2 + 4);
  return v4l2_event_subscribe(a1, a2, 30, &g_cam_v4l2_ops);
}
