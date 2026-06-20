__int64 __fastcall cnss_set_pin_connect_status(__int64 result)
{
  unsigned __int64 v7; // x9
  unsigned __int64 v10; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v16; // x9
  unsigned __int64 v19; // x9
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x9
  unsigned __int64 v28; // x9
  unsigned __int64 v29[2]; // [xsp+0h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  _X8 = v29;
  __asm { PRFM            #0x11, [X8,#0x10+var_10] }
  do
    v7 = __ldxr(v29);
  while ( __stxr(v7 | 1, v29) );
  _X8 = v29;
  __asm { PRFM            #0x11, [X8,#0x10+var_10] }
  do
    v10 = __ldxr(v29);
  while ( __stxr(v10 | 4, v29) );
  _X8 = v29;
  __asm { PRFM            #0x11, [X8,#0x10+var_10] }
  do
    v13 = __ldxr(v29);
  while ( __stxr(v13 | 2, v29) );
  _X8 = v29;
  __asm { PRFM            #0x11, [X8,#0x10+var_10] }
  do
    v16 = __ldxr(v29);
  while ( __stxr(v16 | 0x10, v29) );
  _X8 = v29;
  __asm { PRFM            #0x11, [X8,#0x10+var_10] }
  do
    v19 = __ldxr(v29);
  while ( __stxr(v19 | 8, v29) );
  _X8 = v29;
  __asm { PRFM            #0x11, [X8,#0x10+var_10] }
  do
    v22 = __ldxr(v29);
  while ( __stxr(v22 | 0x40, v29) );
  _X8 = v29;
  __asm { PRFM            #0x11, [X8,#0x10+var_10] }
  do
    v25 = __ldxr(v29);
  while ( __stxr(v25 | 0x20, v29) );
  _X8 = v29;
  __asm { PRFM            #0x11, [X8,#0x10+var_10] }
  do
    v28 = __ldxr(v29);
  while ( __stxr(v28 | 0x80, v29) );
  *(_DWORD *)(result + 6252) = v29[0];
  _ReadStatusReg(SP_EL0);
  return result;
}
