__int64 __fastcall hw_fence_debug_dump_queues(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x30
  __int64 v7; // x19
  unsigned int v8; // w20
  __int64 v9; // x21

  if ( !a3 )
    return printk(&unk_24D9A, "hw_fence_debug_dump_queues", 856, v6, 0, a6);
  if ( *(_DWORD *)(a3 + 136) == 2 )
  {
    v7 = a1;
    v8 = a2;
    v9 = a3;
    ((void (*)(void))dump_queue)();
    a1 = v7;
    a2 = v8;
    a3 = v9;
  }
  return dump_queue(a1, a2, a3, 0);
}
