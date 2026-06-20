__int64 __fastcall cfg80211_mlme_disassoc(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  bool v4; // zf
  __int64 result; // x0
  __int64 v6; // x8
  _QWORD *v7; // x0
  __int64 (__fastcall *v8)(_QWORD); // x8

  _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(a2 + 992);
  if ( (*(_BYTE *)(v3 + 164) & 1) != 0
    && (*(_DWORD *)(v3 + 280) == *(_DWORD *)a3
      ? (v4 = *(unsigned __int16 *)(v3 + 284) == *(unsigned __int16 *)(a3 + 4))
      : (v4 = 0),
        v4) )
  {
    v6 = *a1;
    v7 = a1 + 124;
    v8 = *(__int64 (__fastcall **)(_QWORD))(v6 + 360);
    if ( *((_DWORD *)v8 - 1) != -61890005 )
      __break(0x8228u);
    result = v8(v7);
    if ( !(_DWORD)result )
    {
      result = 0;
      if ( (*(_BYTE *)(v3 + 164) & 1) != 0 )
        __break(0x800u);
    }
  }
  else
  {
    result = 4294967189LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
