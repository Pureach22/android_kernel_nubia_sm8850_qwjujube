__int64 __fastcall cmdobj_set_flags(__int64 result, __int64 a2)
{
  unsigned __int64 v8; // x8
  unsigned __int64 v11; // x9
  unsigned __int64 v14; // x9
  unsigned __int64 v17; // x9
  unsigned __int64 v20; // x9
  unsigned __int64 v23; // x10
  unsigned __int64 v26; // x9

  _X9 = (unsigned __int64 *)(result + 32);
  __asm { PRFM            #0x11, [X9] }
  do
    v8 = __ldxr(_X9);
  while ( __stlxr(v8 & 0xFFFFFFFFFFEFFFFFLL, _X9) );
  __dmb(0xBu);
  if ( (v8 & 0x100000) != 0 )
  {
    _X8 = (unsigned __int64 *)(a2 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 | 2, _X8) );
  }
  if ( (*(_BYTE *)(result + 200) & 8) == 0 && (*(_BYTE *)(a2 + 24) & 8) == 0 )
  {
    if ( (*(_BYTE *)(result + 202) & 1) == 0 )
      goto LABEL_6;
LABEL_19:
    _X8 = (unsigned __int64 *)(a2 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 | 1, _X8) );
    if ( (*(_QWORD *)(result + 32) & 0x80000) == 0 )
      return result;
    goto LABEL_22;
  }
  _X8 = (unsigned __int64 *)(a2 + 56);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 | 2, _X8) );
  if ( (*(_BYTE *)(result + 202) & 1) != 0 )
    goto LABEL_19;
LABEL_6:
  if ( (*(_QWORD *)(result + 32) & 0x80000) == 0 )
    return result;
LABEL_22:
  _X8 = (unsigned __int64 *)(a2 + 56);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 | 1, _X8) );
  if ( (*(_BYTE *)(a2 + 25) & 1) != 0 )
  {
    _X8 = (unsigned __int64 *)(result + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 & 0xFFFFFFFFFFF7FFFFLL, _X8) );
    _X8 = (unsigned __int64 *)(result + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v26 = __ldxr(_X8);
    while ( __stxr(v26 | 0x100000, _X8) );
  }
  return result;
}
