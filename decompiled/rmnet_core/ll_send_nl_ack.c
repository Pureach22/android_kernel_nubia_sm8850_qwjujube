__int64 __fastcall ll_send_nl_ack(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  int v3; // w9
  char v4; // w10
  char v5; // w8

  if ( (*(_BYTE *)(result + 144) & 1) != 0 )
  {
    v1 = result;
    result = _kmalloc_cache_noprof(_stack_chk_fail, 2336, 48);
    v2 = result;
    if ( result )
    {
      v3 = *(_DWORD *)(v1 + 196);
      v4 = *(_BYTE *)(v1 + 16);
      *(_DWORD *)(result + 32) = *(_DWORD *)(v1 + 192);
      *(_DWORD *)(result + 36) = v3;
      v5 = *(_BYTE *)(v1 + 131);
      LOBYTE(v3) = *(_BYTE *)(v1 + 128);
      *(_BYTE *)(result + 40) = v4;
      *(_BYTE *)(result + 41) = v5;
      *(_QWORD *)result = 0xFFFFFFFE00000LL;
      *(_BYTE *)(result + 42) = v3;
      *(_QWORD *)(result + 8) = result + 8;
      *(_QWORD *)(result + 16) = result + 8;
      *(_QWORD *)(result + 24) = ll_ack_fn;
      raw_spin_lock_bh(&ll_wq_lock);
      if ( ll_wq )
        queue_work_on(32, ll_wq, v2);
      else
        kfree(v2);
      return raw_spin_unlock_bh(&ll_wq_lock);
    }
  }
  return result;
}
