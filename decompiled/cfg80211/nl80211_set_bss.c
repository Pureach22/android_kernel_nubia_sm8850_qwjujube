__int64 __fastcall nl80211_set_bss(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x1
  _BYTE *v4; // x19
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 result; // x0
  int v8; // w8
  __int64 (__fastcall *v9)(_QWORD); // x8

  _ReadStatusReg(SP_EL0);
  v2 = a2[4];
  v4 = (_BYTE *)a2[6];
  v3 = a2[7];
  v5 = *(_QWORD *)(v2 + 1296);
  if ( (!v5 || *(_DWORD *)(*(_QWORD *)(v3 + 992) + 8LL) == 9 && (!*(_BYTE *)(v5 + 4) || (v4[1101] & 8) != 0))
    && ((v6 = *(_QWORD *)(v2 + 1304)) == 0
     || *(_DWORD *)(*(_QWORD *)(v3 + 992) + 8LL) == 9 && (!*(_BYTE *)(v6 + 4) || (v4[1101] & 0x10) != 0)) )
  {
    if ( *(_QWORD *)(*(_QWORD *)v4 + 280LL) && ((v8 = *(_DWORD *)(*(_QWORD *)(v3 + 992) + 8LL), v8 == 9) || v8 == 3) )
    {
      v9 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v4 + 280LL);
      if ( *((_DWORD *)v9 - 1) != 1986351093 )
        __break(0x8228u);
      result = v9(v4 + 992);
    }
    else
    {
      result = 4294967201LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
