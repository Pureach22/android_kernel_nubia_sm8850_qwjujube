__int64 __fastcall ieee80211_check_combinations(__int64 a1, _QWORD *a2, int a3, unsigned __int8 a4, int a5)
{
  __int64 v9; // x20
  __int64 v10; // x24
  __int64 result; // x0
  _QWORD *v12; // x2
  int v13; // [xsp+4h] [xbp-4Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-48h]
  _QWORD v15[6]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v16; // [xsp+40h] [xbp-10h]
  __int64 v17; // [xsp+48h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 1616);
  v10 = *(unsigned int *)(a1 + 24);
  v14 = 0;
  memset(v15, 0, sizeof(v15));
  v16 = 0;
  v13 = a5;
  BYTE4(v14) = a4;
  if ( (unsigned int)_sw_hweight32(a4) < 2 && (!a2 || a3 || *a2) && (unsigned int)v10 < 0xD )
  {
    if ( (*(_DWORD *)(a1 + 4720) | 4) == 7 )
      HIDWORD(v16) = *(unsigned __int16 *)(a1 + 4858);
    if ( (cfg80211_iftype_allowed(*(_QWORD *)(v9 + 72), (unsigned int)v10, 0, 1) & 1) != 0 )
    {
      if ( a4 )
        result = 4294967274LL;
      else
        result = 0;
    }
    else
    {
      if ( a2 )
        LODWORD(v14) = 1;
      if ( (_DWORD)v10 )
        *((_DWORD *)v15 + v10) = 1;
      if ( a3 )
        v12 = nullptr;
      else
        v12 = a2;
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, int *, _QWORD *, __int64))ieee80211_fill_ifcomb_params)(
                           v9,
                           &v13,
                           v12,
                           a1) != 1
        || BYTE4(v14) )
      {
        result = cfg80211_check_combinations(*(_QWORD *)(v9 + 72), &v13);
      }
      else
      {
        result = 0;
      }
    }
  }
  else
  {
    __break(0x800u);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
