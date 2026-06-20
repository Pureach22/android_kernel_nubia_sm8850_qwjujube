__int64 __fastcall _raise_interrupt_iris4(__int64 a1)
{
  return _write_register(a1, 0xA0150u, 1u);
}
