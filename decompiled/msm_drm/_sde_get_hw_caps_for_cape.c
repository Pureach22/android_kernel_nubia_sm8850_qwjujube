__int64 __fastcall sde_get_hw_caps_for_cape(__int64 result)
{
  unsigned __int64 v7; // x10
  unsigned __int64 v10; // x10
  unsigned __int64 v13; // x10
  unsigned __int64 v16; // x10
  unsigned __int64 v19; // x10
  unsigned __int64 v22; // x10
  unsigned __int64 v25; // x10
  unsigned __int64 v28; // x10
  unsigned __int64 v31; // x10
  unsigned __int64 v34; // x10
  unsigned __int64 v37; // x10
  unsigned __int64 v40; // x10
  unsigned __int64 v43; // x10
  unsigned __int64 v46; // x10
  unsigned __int64 v49; // x10
  unsigned __int64 v52; // x10
  unsigned __int64 v55; // x10
  unsigned __int64 v58; // x9
  unsigned __int64 v61; // x9
  unsigned __int64 v64; // x9
  unsigned __int64 v67; // x9

  *(_DWORD *)(result + 21612) = 1;
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v7 = __ldxr(_X9);
  while ( __stxr(v7 | 0x40, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v10 = __ldxr(_X9);
  while ( __stxr(v10 | 0x20, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v13 = __ldxr(_X9);
  while ( __stxr(v13 | 4, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v16 = __ldxr(_X9);
  while ( __stxr(v16 | 0x10, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v19 = __ldxr(_X9);
  while ( __stxr(v19 | 0x200000, _X9) );
  *(_DWORD *)(result + 21792) = 40;
  *(_DWORD *)(result + 40) = 2;
  *(_DWORD *)(result + 21592) = 8;
  *(_DWORD *)(result + 28) = 256;
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v22 = __ldxr(_X9);
  while ( __stxr(v22 | 0x400, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v25 = __ldxr(_X9);
  while ( __stxr(v25 | 0x100000, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v28 = __ldxr(_X9);
  while ( __stxr(v28 | 0x20000000, _X9) );
  _X9 = (unsigned __int64 *)(result + 680);
  __asm { PRFM            #0x11, [X9] }
  do
    v31 = __ldxr(_X9);
  while ( __stxr(v31 | 0x200, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v34 = __ldxr(_X9);
  while ( __stxr(v34 | 0x10000, _X9) );
  *(_DWORD *)(result + 44) = 513;
  *(_DWORD *)(result + 21976) = 258;
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v37 = __ldxr(_X9);
  while ( __stxr(v37 | 0x8000000, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v40 = __ldxr(_X9);
  while ( __stxr(v40 | 0x40000000, _X9) );
  *(_DWORD *)(result + 640) = 344;
  _X9 = (unsigned __int64 *)(result + 21696);
  __asm { PRFM            #0x11, [X9] }
  do
    v43 = __ldxr(_X9);
  while ( __stxr(v43 | 1, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v46 = __ldxr(_X9);
  while ( __stxr(v46 | 0x2000000, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v49 = __ldxr(_X9);
  while ( __stxr(v49 | 0x40000, _X9) );
  _X9 = (unsigned __int64 *)(result + 680);
  __asm { PRFM            #0x11, [X9] }
  do
    v52 = __ldxr(_X9);
  while ( __stxr(v52 | 0x800, _X9) );
  _X9 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X9] }
  do
    v55 = __ldxr(_X9);
  while ( __stxr(v55 | 0x800000, _X9) );
  *(_QWORD *)(result + 20064) = 0x100000000LL;
  *(_QWORD *)(result + 20080) = 0x100000000LL;
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
  while ( __stxr(v67 | 0x800000000LL, _X8) );
  return result;
}
