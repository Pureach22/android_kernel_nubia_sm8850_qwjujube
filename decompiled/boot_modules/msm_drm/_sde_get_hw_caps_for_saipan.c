_DWORD *__fastcall sde_get_hw_caps_for_saipan(_DWORD *result)
{
  unsigned __int64 v7; // x9
  unsigned __int64 v10; // x9
  unsigned __int64 v13; // x10
  unsigned __int64 v16; // x9
  unsigned __int64 v19; // x9
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x9
  unsigned __int64 v28; // x9

  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stxr(v7 | 8, _X8) );
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 | 4, _X8) );
  _X9 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X9] }
  do
    v13 = __ldxr(_X9);
  while ( __stxr(v13 | 0x200000, _X9) );
  result[5448] = 40;
  result[10] = 2;
  result[7] = 256;
  result[5398] = 8;
  result[5369] = 3697;
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 | 0x400, _X8) );
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 | 0x100000, _X8) );
  _X8 = (unsigned __int64 *)(result + 170);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 0x100, _X8) );
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 | 0x10000, _X8) );
  result[11] = 256;
  _X8 = (unsigned __int64 *)(result + 5502);
  __asm { PRFM            #0x11, [X8] }
  do
    v28 = __ldxr(_X8);
  while ( __stxr(v28 | 0x10000000, _X8) );
  return result;
}
