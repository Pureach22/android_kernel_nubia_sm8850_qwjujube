__int64 __fastcall wlan_hdd_set_pm_qos_request(__int64 result, char a2)
{
  __int64 v2; // x19
  char v3; // w8
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
  unsigned __int64 v41[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = result;
  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41[0] = 0;
  if ( (a2 & 1) != 0 )
  {
    v3 = *(_BYTE *)(result + 1460);
    *(_BYTE *)(result + 1461) = 1;
    if ( (v3 & 1) == 0 )
    {
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v10 = __ldxr(v41);
      while ( __stxr(v10 | 1, v41) );
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v13 = __ldxr(v41);
      while ( __stxr(v13 | 2, v41) );
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v16 = __ldxr(v41);
      while ( __stxr(v16 | 4, v41) );
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v19 = __ldxr(v41);
      while ( __stxr(v19 | 8, v41) );
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v22 = __ldxr(v41);
      while ( __stxr(v22 | 0x10, v41) );
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v25 = __ldxr(v41);
      while ( __stxr(v25 | 0x20, v41) );
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v28 = __ldxr(v41);
      while ( __stxr(v28 | 0x40, v41) );
      result = hdd_pm_qos_update_request(result, v41);
      *(_BYTE *)(v2 + 1460) = 1;
    }
  }
  else
  {
    if ( *(_BYTE *)(result + 1460) == 1 )
    {
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v31 = __ldxr(v41);
      while ( __stxr(v31 | 1, v41) );
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v34 = __ldxr(v41);
      while ( __stxr(v34 | 2, v41) );
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v37 = __ldxr(v41);
      while ( __stxr(v37 | 4, v41) );
      _X8 = v41;
      __asm { PRFM            #0x11, [X8,#0x30+var_30] }
      do
        v40 = __ldxr(v41);
      while ( __stxr(v40 | 8, v41) );
      result = hdd_pm_qos_update_request(result, v41);
      *(_BYTE *)(v2 + 1460) = 0;
    }
    *(_BYTE *)(v2 + 1461) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
