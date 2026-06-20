__int64 __fastcall adreno_hwsched_poll_msg_queue_write_index(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21

  v1 = *(_QWORD *)(a1 + 8);
  v2 = -250LL - jiffies;
  while ( *(_DWORD *)(v1 + 116) == *(_DWORD *)(v1 + 112) )
  {
    usleep_range_state(26, 100, 2);
    __yield();
    if ( v2 + jiffies >= 0 )
    {
      if ( *(_DWORD *)(v1 + 116) == *(_DWORD *)(v1 + 112) )
        return 4294967186LL;
      break;
    }
  }
  __dsb(0xDu);
  return 0;
}
