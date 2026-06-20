__int64 __fastcall reg_is_chan_disabled(char a1, int a2)
{
  return a1 & 1 | (unsigned int)(a2 == 0);
}
