__int64 __fastcall hw_fence_update_queue_payload(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        int a9)
{
  unsigned int v12; // w8
  __int64 (*v13)(void); // x8
  __int64 result; // x0

  *(_WORD *)(a2 + 6) = 256;
  *(_WORD *)(a2 + 4) = a3;
  *(_DWORD *)a2 = 64;
  *(_QWORD *)(a2 + 8) = a4;
  *(_QWORD *)(a2 + 16) = a5;
  if ( a1 )
    v12 = (*(_DWORD *)(a1 + 12) << 27) | 0x80000000;
  else
    v12 = 0x80000000;
  *(_QWORD *)(a2 + 40) = a8;
  *(_QWORD *)(a2 + 24) = v12 | (unsigned int)a6;
  *(_QWORD *)(a2 + 32) = a7;
  v13 = (__int64 (*)(void))arch_timer_read_counter;
  *(_DWORD *)(a2 + 48) = a9;
  if ( *((_DWORD *)v13 - 1) != -1073338243 )
    __break(0x8228u);
  result = v13();
  *(_QWORD *)(a2 + 52) = result;
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    return printk(&unk_24378, "hw_fence_update_queue_payload", 408, a3, a6);
  return result;
}
