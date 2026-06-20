__int64 __fastcall on_interrupt_from(__int64 a1, __int64 a2)
{
  complete(a2 + 8);
  return 1;
}
