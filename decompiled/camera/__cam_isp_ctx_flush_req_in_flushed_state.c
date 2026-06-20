__int64 __fastcall _cam_isp_ctx_flush_req_in_flushed_state(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  __int64 v5; // x21

  v2 = *(_QWORD *)(a2 + 16);
  if ( v2 > *(unsigned int *)(a1 + 464) )
    *(_DWORD *)(a1 + 464) = v2;
  v5 = *(_QWORD *)(a1 + 256);
  *(_BYTE *)(v5 + 45753) = *(_BYTE *)(a2 + 24);
  if ( !*(_DWORD *)(a2 + 8) )
  {
    if ( *(_DWORD *)(a1 + 240) > 3u )
    {
      raw_spin_lock_bh(a1 + 120);
      *(_DWORD *)(a1 + 240) = 4;
      *(_DWORD *)(v5 + 20) = 6;
      raw_spin_unlock_bh(a1 + 120);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "__cam_isp_ctx_flush_req_in_flushed_state",
        6636,
        "Last request id to flush is %lld, ctx_id:%u link: 0x%x",
        *(_QWORD *)(a2 + 16),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      *(_DWORD *)(a1 + 464) = *(_QWORD *)(a2 + 16);
      raw_spin_lock_bh(a1 + 120);
      if ( *(_QWORD *)(a1 + 160) != a1 + 160 )
        _cam_isp_ctx_flush_req(a1, a1 + 160, a2);
      if ( *(_QWORD *)(a1 + 128) != a1 + 128 )
        _cam_isp_ctx_flush_req(a1, a1 + 128, a2);
      *(_DWORD *)(v5 + 37320) = 0;
      if ( *(_QWORD *)(a1 + 144) != a1 + 144 )
        _cam_isp_ctx_flush_req(a1, a1 + 144, a2);
      *(_BYTE *)(v5 + 45741) = 0;
      raw_spin_unlock_bh(a1 + 120);
    }
    else
    {
      *(_DWORD *)(a1 + 240) = 2;
    }
  }
  *(_DWORD *)(v5 + 37376) = 0;
  *(_DWORD *)(v5 + 37388) = 0;
  *(_BYTE *)(v5 + 45746) = 0;
  *(_DWORD *)(v5 + 45700) = 0;
  *(_DWORD *)(v5 + 24) = 0;
  *(_DWORD *)(v5 + 45584) = 0;
  *(_DWORD *)(v5 + 45572) = 0;
  return 0;
}
