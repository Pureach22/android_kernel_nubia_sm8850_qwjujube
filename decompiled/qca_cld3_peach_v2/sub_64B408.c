__int64 __fastcall sub_64B408(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { STGP            X4, X10, [X25,#-0xA8]! }
  return dp_rx_pdev_mon_buf_buffers_alloc(a1, a2, a3, a4, _X4);
}
