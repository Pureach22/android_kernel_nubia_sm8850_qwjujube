unsigned __int64 *__fastcall sde_get_hw_caps_for_shima(unsigned __int64 *result)
{
  unsigned __int64 v7; // x9
  unsigned __int64 v10; // x9
  unsigned __int64 v13; // x10
  unsigned __int64 v16; // x9
  unsigned __int64 v19; // x9
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x9
  unsigned __int64 v28; // x9
  unsigned __int64 v31; // x9
  unsigned __int64 v34; // x9
  unsigned __int64 v37; // x9

  _X8 = result + 2751;
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stxr(v7 | 8, _X8) );
  _X8 = result + 2751;
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 | 4, _X8) );
  _X9 = result + 2751;
  __asm { PRFM            #0x11, [X9] }
  do
    v13 = __ldxr(_X9);
  while ( __stxr(v13 | 0x200000, _X9) );
  *((_DWORD *)result + 5448) = 35;
  *((_DWORD *)result + 10) = 2;
  *((_DWORD *)result + 7) = 256;
  *((_DWORD *)result + 5398) = 8;
  *((_DWORD *)result + 5369) = 3697;
  _X8 = result + 2751;
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 | 0x400, _X8) );
  _X8 = result + 2751;
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 | 0x100000, _X8) );
  _X8 = result + 85;
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 0x100, _X8) );
  _X8 = result + 2751;
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 | 0x10000, _X8) );
  *((_DWORD *)result + 11) = 256;
  _X8 = result + 2751;
  __asm { PRFM            #0x11, [X8] }
  do
    v28 = __ldxr(_X8);
  while ( __stxr(v28 | 0x10000000, _X8) );
  _X8 = result + 2751;
  __asm { PRFM            #0x11, [X8] }
  do
    v31 = __ldxr(_X8);
  while ( __stxr(v31 | 0x8000000, _X8) );
  *((_DWORD *)result + 160) = 344;
  _X8 = result + 2751;
  __asm { PRFM            #0x11, [X8] }
  do
    v34 = __ldxr(_X8);
  while ( __stxr(v34 | 0x800000000LL, _X8) );
  _X8 = result + 2712;
  __asm { PRFM            #0x11, [X8] }
  do
    v37 = __ldxr(_X8);
  while ( __stxr(v37 | 1, _X8) );
  return result;
}
