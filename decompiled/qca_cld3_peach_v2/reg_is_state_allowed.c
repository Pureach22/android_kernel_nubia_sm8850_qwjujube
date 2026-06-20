bool __fastcall reg_is_state_allowed(int a1)
{
  return (a1 & 0xFFFFFFFB) != 0;
}
