__int64 __fastcall sde_get_hw_caps_for_sun(__int64 result)
{
  unsigned __int64 v7; // x9
  unsigned __int64 v9; // x9
  unsigned __int64 v11; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v15; // x9
  unsigned __int64 v17; // x9
  unsigned __int64 v19; // x9
  unsigned __int64 v21; // x9
  unsigned __int64 v23; // x9
  unsigned __int64 v26; // x10
  unsigned __int64 v28; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v32; // x9
  unsigned __int64 v34; // x9
  unsigned __int64 v36; // x9
  unsigned __int64 v38; // x9
  unsigned __int64 v41; // x10
  unsigned __int64 v43; // x9
  unsigned __int64 v45; // x9
  unsigned __int64 v47; // x9
  unsigned __int64 v49; // x9
  unsigned __int64 v51; // x9
  unsigned __int64 v53; // x9
  unsigned __int64 v55; // x9
  unsigned __int64 v58; // x10
  unsigned __int64 v61; // x10
  unsigned __int64 v63; // x9
  unsigned __int64 v65; // x9
  unsigned __int64 v67; // x10
  unsigned __int64 v69; // x10
  unsigned __int64 v71; // x10
  unsigned __int64 v73; // x10

  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stxr(v7 | 0x40, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 | 0x80, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 | 0x20, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 | 4, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 | 0x10, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stxr(v17 | 0x200000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 | 0x400, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v21 = __ldxr(_X8);
  while ( __stxr(v21 | 0x100000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v23 = __ldxr(_X8);
  while ( __stxr(v23 | 0x20000000, _X8) );
  _X9 = (unsigned __int64 *)(result + 680);
  __asm { PRFM            #0x11, [X9] }
  do
    v26 = __ldxr(_X9);
  while ( __stxr(v26 | 0x200, _X9) );
  __asm { PRFM            #0x11, [X8] }
  do
    v28 = __ldxr(_X8);
  while ( __stxr(v28 | 0x10000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v30 = __ldxr(_X8);
  while ( __stxr(v30 | 0x8000000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v32 = __ldxr(_X8);
  while ( __stxr(v32 | 0x40000000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v34 = __ldxr(_X8);
  while ( __stxr(v34 | 0x2000000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v36 = __ldxr(_X8);
  while ( __stxr(v36 | 0x40000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v38 = __ldxr(_X8);
  while ( __stxr(v38 | 0x800000000000LL, _X8) );
  _X9 = (unsigned __int64 *)(result + 680);
  __asm { PRFM            #0x11, [X9] }
  do
    v41 = __ldxr(_X9);
  while ( __stxr(v41 | 0x800, _X9) );
  __asm { PRFM            #0x11, [X8] }
  do
    v43 = __ldxr(_X8);
  while ( __stxr(v43 | 0x800000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v45 = __ldxr(_X8);
  while ( __stxr(v45 | 0x4000000000LL, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v47 = __ldxr(_X8);
  while ( __stxr(v47 | 0x1000000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v49 = __ldxr(_X8);
  while ( __stxr(v49 | 0x400000, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v51 = __ldxr(_X8);
  while ( __stxr(v51 | 0x8000000000LL, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v53 = __ldxr(_X8);
  while ( __stxr(v53 | 0x10000000000LL, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v55 = __ldxr(_X8);
  while ( __stxr(v55 | 0x800000000LL, _X8) );
  _X9 = (unsigned __int64 *)(result + 21696);
  __asm { PRFM            #0x11, [X9] }
  do
    v58 = __ldxr(_X9);
  while ( __stxr(v58 | 1, _X9) );
  _X9 = (unsigned __int64 *)(result + 21696);
  __asm { PRFM            #0x11, [X9] }
  do
    v61 = __ldxr(_X9);
  while ( __stxr(v61 | 4, _X9) );
  __asm { PRFM            #0x11, [X8] }
  do
    v63 = __ldxr(_X8);
  while ( __stxr(v63 | 0x20000000000LL, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v65 = __ldxr(_X8);
  while ( __stxr(v65 | 0x40000000000LL, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v67 = __ldxr(_X8);
  while ( __stxr(v67 | 0x100, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v69 = __ldxr(_X8);
  while ( __stxr(v69 | 0x1000000000LL, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v71 = __ldxr(_X8);
  while ( __stxr(v71 | 0x400000000000LL, _X8) );
  __asm { PRFM            #0x11, [X8] }
  do
    v73 = __ldxr(_X8);
  while ( __stxr(v73 | 0x1000000000000LL, _X8) );
  *(_QWORD *)(result + 21612) = 0x100000001LL;
  *(_DWORD *)(result + 22144) = 2;
  *(_DWORD *)(result + 21596) = 11160;
  *(_DWORD *)(result + 21792) = 40;
  *(_QWORD *)(result + 40) = 0x20200000002LL;
  *(_QWORD *)(result + 28) = 0x20000000100LL;
  *(_DWORD *)(result + 21976) = 260;
  *(_DWORD *)(result + 640) = 348;
  *(_QWORD *)(result + 21588) = 0x8000927C0LL;
  *(_QWORD *)(result + 20064) = 0xA00000005LL;
  *(_QWORD *)(result + 20080) = 0xA00000005LL;
  *(_BYTE *)(result + 22016) = 1;
  *(_QWORD *)(result + 22024) = 38400000;
  return result;
}
