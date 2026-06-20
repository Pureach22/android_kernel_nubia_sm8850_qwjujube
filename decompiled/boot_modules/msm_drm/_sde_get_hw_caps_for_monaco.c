_DWORD *__fastcall sde_get_hw_caps_for_monaco(_DWORD *result)
{
  unsigned __int64 v7; // x10

  _X9 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X9] }
  do
    v7 = __ldxr(_X9);
  while ( __stxr(v7 | 0x200000, _X9) );
  result[5448] = 24;
  result[10] = 2;
  result[7] = 256;
  result[5398] = 8;
  result[5369] = 1;
  return result;
}
