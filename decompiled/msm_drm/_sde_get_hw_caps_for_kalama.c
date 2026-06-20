__int64 __fastcall sde_get_hw_caps_for_kalama(__int64 result)
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
  unsigned __int64 v58; // x9
  unsigned __int64 v61; // x9
  unsigned __int64 v64; // x9
  unsigned __int64 v67; // x9
  unsigned __int64 v70; // x9
  unsigned __int64 v73; // x9
  unsigned __int64 v76; // x10
  unsigned __int64 v79; // x10
  unsigned __int64 v82; // x10
  unsigned __int64 v85; // x10

  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stxr(v7 | 0x40, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 | 0x80, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 | 0x20, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 | 4, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 | 0x10, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 0x200000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 | 0x400, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v28 = __ldxr(_X8);
  while ( __stxr(v28 | 0x100000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v31 = __ldxr(_X8);
  while ( __stxr(v31 | 0x20000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 680);
  __asm { PRFM            #0x11, [X8] }
  do
    v34 = __ldxr(_X8);
  while ( __stxr(v34 | 0x200, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v37 = __ldxr(_X8);
  while ( __stxr(v37 | 0x10000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v40 = __ldxr(_X8);
  while ( __stxr(v40 | 0x8000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v43 = __ldxr(_X8);
  while ( __stxr(v43 | 0x40000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v46 = __ldxr(_X8);
  while ( __stxr(v46 | 0x2000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v49 = __ldxr(_X8);
  while ( __stxr(v49 | 0x40000, _X8) );
  _X8 = (unsigned __int64 *)(result + 680);
  __asm { PRFM            #0x11, [X8] }
  do
    v52 = __ldxr(_X8);
  while ( __stxr(v52 | 0x800, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v55 = __ldxr(_X8);
  while ( __stxr(v55 | 0x800000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v58 = __ldxr(_X8);
  while ( __stxr(v58 | 0x4000000000LL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v61 = __ldxr(_X8);
  while ( __stxr(v61 | 0x1000000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v64 = __ldxr(_X8);
  while ( __stxr(v64 | 0x400000, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v67 = __ldxr(_X8);
  while ( __stxr(v67 | 0x8000000000LL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v70 = __ldxr(_X8);
  while ( __stxr(v70 | 0x10000000000LL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v73 = __ldxr(_X8);
  while ( __stxr(v73 | 0x800000000LL, _X8) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v76 = __ldxr(_X9);
  while ( __stxr(v76 | 0x20000000000LL, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v79 = __ldxr(_X9);
  while ( __stxr(v79 | 0x40000000000LL, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v82 = __ldxr(_X9);
  while ( __stxr(v82 | 0x100, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v85 = __ldxr(_X9);
  while ( __stxr(v85 | 0x1000000000LL, _X9) );
  *(_QWORD *)(result + 21612) = 0x100000001LL;
  *(_DWORD *)(result + 21792) = 40;
  *(_DWORD *)(result + 22144) = 1;
  *(_QWORD *)(result + 21592) = 0x2B9800000008LL;
  *(_BYTE *)(result + 22016) = 1;
  *(_QWORD *)(result + 40) = 0x20100000002LL;
  *(_QWORD *)(result + 28) = 0x20000000100LL;
  *(_DWORD *)(result + 21976) = 260;
  *(_DWORD *)(result + 640) = 344;
  *(_QWORD *)(result + 20064) = 0xA00000005LL;
  *(_QWORD *)(result + 20080) = 0xA00000005LL;
  return result;
}
