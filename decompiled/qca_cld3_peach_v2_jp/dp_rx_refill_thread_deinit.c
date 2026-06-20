__int64 __fastcall dp_rx_refill_thread_deinit(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x1
  __int64 v4; // x1
  __int64 v5; // x1

  *(_QWORD *)(a1 + 168) |= 0x12uLL;
  _wake_up(a1 + 176, 1, 1, 0);
  qdf_wait_single_event(a1 + 128, 0);
  qdf_event_destroy(a1 + 8, v2);
  qdf_event_destroy(a1 + 48, v3);
  qdf_event_destroy(a1 + 88, v4);
  qdf_event_destroy(a1 + 128, v5);
  *(_DWORD *)(a1 + 216) = 0;
  return 0;
}
