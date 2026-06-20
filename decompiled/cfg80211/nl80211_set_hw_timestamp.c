__int64 __fastcall nl80211_set_hw_timestamp(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x1
  _WORD *v4; // x19
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 result; // x0
  _DWORD *v8; // x8
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (_WORD *)a2[6];
  v3 = a2[7];
  v9 = 0;
  v10 = 0;
  if ( v4[1242] && ((v5 = a2[4], v6 = *(_QWORD *)(v5 + 48), (unsigned __int16)v4[1242] == 0xFFFF) || v6) )
  {
    if ( v6 )
      v9 = v6 + 4;
    LOBYTE(v10) = *(_QWORD *)(v5 + 2592) != 0;
    v8 = *(_DWORD **)(*(_QWORD *)v4 + 984LL);
    if ( v8 )
    {
      if ( *(v8 - 1) != 521547508 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(_WORD *, __int64, __int64 *))v8)(v4 + 496, v3, &v9);
    }
    else
    {
      result = 4294967201LL;
    }
  }
  else
  {
    result = 4294967201LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
