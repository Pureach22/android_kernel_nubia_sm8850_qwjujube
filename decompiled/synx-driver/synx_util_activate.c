__int64 __fastcall synx_util_activate(unsigned __int64 a1)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a1 <= 0xFFFFFFFFFFFFF000LL )
    {
      dma_fence_enable_sw_signaling(*(_QWORD *)(a1 + 64));
      return 0;
    }
  }
  return result;
}
