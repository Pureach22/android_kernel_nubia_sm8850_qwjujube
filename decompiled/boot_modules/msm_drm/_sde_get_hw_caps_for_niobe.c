__int64 __fastcall sde_get_hw_caps_for_niobe(__int64 result)
{
  unsigned __int64 v7; // x9
  unsigned __int64 v10; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v16; // x9
  unsigned __int64 v19; // x9
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x9
  unsigned __int64 v28; // x9
  unsigned __int64 v31; // x9
  unsigned __int64 v34; // x9
  unsigned __int64 v37; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v43; // x9
  unsigned __int64 v46; // x9
  unsigned __int64 v49; // x9
  unsigned __int64 v52; // x9
  unsigned __int64 v55; // x9
  unsigned __int64 v58; // x10

  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stxr(v7 | 4, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 | 0x400, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 | 0x20000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 | 0x10000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 | 0x8000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 0x40000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 | 0x2000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v28 = __ldxr(_X8);
  while ( __stxr(v28 | 0x40000, _X8) );
  _X8 = (unsigned __int64 *)(result + 680);
  __asm { PRFM            #0x11, [X8] }
  do
    v31 = __ldxr(_X8);
  while ( __stxr(v31 | 0x800, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v34 = __ldxr(_X8);
  while ( __stxr(v34 | 0x4000000000LL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v37 = __ldxr(_X8);
  while ( __stxr(v37 | 0x1000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v40 = __ldxr(_X8);
  while ( __stxr(v40 | 0x8000000000LL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v43 = __ldxr(_X8);
  while ( __stxr(v43 | 0x10000000000LL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v46 = __ldxr(_X8);
  while ( __stxr(v46 | 0x2000000000000LL, _X8) );
  _X8 = (unsigned __int64 *)(result + 680);
  __asm { PRFM            #0x11, [X8] }
  do
    v49 = __ldxr(_X8);
  while ( __stxr(v49 | 0x4000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v52 = __ldxr(_X8);
  while ( __stxr(v52 | 0x800000000000LL, _X8) );
  _X8 = (unsigned __int64 *)(result + 680);
  __asm { PRFM            #0x11, [X8] }
  do
    v55 = __ldxr(_X8);
  while ( __stxr(v55 | 0x8000, _X8) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v58 = __ldxr(_X9);
  while ( __stxr(v58 | 0x1000000000LL, _X9) );
  *(_DWORD *)(result + 21612) = 1;
  *(_DWORD *)(result + 22144) = 2;
  *(_DWORD *)(result + 21792) = 40;
  *(_QWORD *)(result + 21592) = 0x354800000008LL;
  *(_QWORD *)(result + 40) = 0x20100000002LL;
  *(_DWORD *)(result + 28) = 256;
  *(_DWORD *)(result + 640) = 348;
  *(_DWORD *)(result + 56) = 41;
  return result;
}
