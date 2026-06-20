_DWORD *__fastcall ipclite_atomic_init_u32(_DWORD *result, int a2)
{
  if ( result )
  {
    *result = a2;
  }
  else
  {
    __break(0x800u);
    return (_DWORD *)ipclite_atomic_init_i32();
  }
  return result;
}
