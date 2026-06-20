__int64 sub_C95CC()
{
  __asm { STZ2G           X22, [X27],#0xB70 }
  return gen8_hfi_queue_read();
}
