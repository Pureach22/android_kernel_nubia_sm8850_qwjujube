__int64 __fastcall sub_FEEB4(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v8; // w28

  *a2 = a8;
  a2[1] = v8;
  return cam_req_mgr_cb_notify_stop(a1, a2 + 35);
}
