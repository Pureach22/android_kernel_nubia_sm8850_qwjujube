__int64 __usercall sub_147314@<X0>(__int64 a1@<X8>)
{
  atomic_load_explicit((atomic_uint *volatile)(a1 - 232), memory_order_acquire);
  return reg_dma_buf_init();
}
