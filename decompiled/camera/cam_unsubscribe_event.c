__int64 __fastcall cam_unsubscribe_event(__int64 a1, __int64 a2)
{
  dword_2FDAA0 &= ~(1 << *(_DWORD *)(a2 + 4));
  return v4l2_event_unsubscribe();
}
