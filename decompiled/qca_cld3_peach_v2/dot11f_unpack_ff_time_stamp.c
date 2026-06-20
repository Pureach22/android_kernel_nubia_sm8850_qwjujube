void *__fastcall dot11f_unpack_ff_time_stamp(int a1, __int64 a2, __int64 a3)
{
  qdf_mem_copy((void *)a3, (const void *)a2, 4u);
  return qdf_mem_copy((void *)(a3 + 4), (const void *)(a2 + 4), 4u);
}
