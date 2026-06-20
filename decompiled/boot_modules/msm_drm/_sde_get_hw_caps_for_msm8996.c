__int64 __fastcall sde_get_hw_caps_for_msm8996(__int64 result)
{
  unsigned __int64 v7; // x9
  unsigned __int64 v10; // x10
  unsigned __int64 v13; // x10
  unsigned __int64 v16; // x10
  unsigned __int64 v19; // x10
  unsigned __int64 v22; // x10
  unsigned __int64 v25; // x10

  *(_DWORD *)(result + 21792) = 21;
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stxr(v7 | 0x800, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 & 0xFFFFFFFFFFFFEFFFLL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 & 0xFFFFFFFFFFF7FFFFLL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 & 0xFFFFFFFFFBFFFFFFLL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 & 0xFFFFFFFEFFFFFFFFLL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 & 0xFFFFFFFDFFFFFFFFLL, _X8) );
  _X8 = (unsigned __int64 *)(result + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 & 0xFFFFFFFBFFFFFFFFLL, _X8) );
  return result;
}
