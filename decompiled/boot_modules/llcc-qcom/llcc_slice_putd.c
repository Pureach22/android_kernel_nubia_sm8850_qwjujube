_DWORD *__fastcall llcc_slice_putd(_DWORD *result)
{
  if ( result && (unsigned __int64)result <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( result[4] )
    {
      result = (_DWORD *)_warn_printk(" Slice %d is still active\n", *result);
      __break(0x800u);
    }
  }
  return result;
}
