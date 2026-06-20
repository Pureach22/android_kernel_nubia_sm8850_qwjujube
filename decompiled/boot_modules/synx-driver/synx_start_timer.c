__int64 __fastcall synx_start_timer(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 result; // x0
  unsigned int v5; // w20

  init_timer_key(a1 + 24, synx_timer_cb, 0, 0, 0);
  v2 = jiffies;
  v3 = _msecs_to_jiffies(*(unsigned int *)(a1 + 64));
  result = mod_timer(a1 + 24, v3 + v2);
  if ( (synx_debug & 0x10) != 0 )
  {
    v5 = result;
    printk(&unk_25D3A, "verb", "synx_start_timer", 1081, a1, *(_QWORD *)(a1 + 64));
    return v5;
  }
  return result;
}
