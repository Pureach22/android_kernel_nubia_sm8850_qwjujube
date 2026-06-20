_DWORD *__fastcall sde_get_hw_caps_for_sdmshrike(_DWORD *result)
{
  unsigned __int64 v7; // x10
  unsigned __int64 v10; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v16; // x10
  unsigned __int64 v19; // x10
  unsigned __int64 v22; // x10

  _X9 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X9] }
  do
    v7 = __ldxr(_X9);
  while ( __stxr(v7 | 4, _X9) );
  result[5448] = 24;
  result[5398] = 8;
  result[10] = 2;
  result[7] = 256;
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 | 0x800, _X8) );
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 | 0x10000, _X8) );
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 & 0xFFFFFFFEFFFFFFFFLL, _X8) );
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 & 0xFFFFFFFDFFFFFFFFLL, _X8) );
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 & 0xFFFFFFFBFFFFFFFFLL, _X8) );
  return result;
}
