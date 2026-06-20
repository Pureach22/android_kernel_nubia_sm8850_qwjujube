__int64 __fastcall synx_hwfence_get_fence(_DWORD *a1, unsigned int a2)
{
  __int64 v2; // x30

  if ( a1
    && (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL
    && (a2 & 0x80000000) != 0
    && (unsigned int)(*a1 - 4096) > 0xFFFFF3FF )
  {
    return hw_fence_interop_get_fence(a2);
  }
  printk(&unk_25E32, "synx_hwfence_get_fence", 497, v2, a1);
  return -22;
}
