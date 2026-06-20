__int64 __fastcall _cam_isp_ctx_flush_req_in_ready(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20

  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_flush_req_in_ready",
      6911,
      "try to flush pending list, ctx_id:%u link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  raw_spin_lock_bh(a1 + 120);
  v4 = _cam_isp_ctx_flush_req(a1, a1 + 144, a2);
  if ( *(_QWORD *)(a1 + 144) == a1 + 144 )
    *(_DWORD *)(a1 + 240) = 2;
  raw_spin_unlock_bh(a1 + 120);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_flush_req_in_ready",
      6923,
      "Flush request in ready state. next state %d, ctx_id:%u link: 0x%x",
      *(_DWORD *)(a1 + 240),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  return v4;
}
