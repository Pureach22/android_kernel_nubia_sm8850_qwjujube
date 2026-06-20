__int64 __fastcall tgt_p2p_scan_event_cb(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return p2p_scan_event_cb(a4, a5, a6, a7, a8, a9, a10, a11, a1, a2, a3);
}
