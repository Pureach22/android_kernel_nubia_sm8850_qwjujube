__int64 __fastcall cfg80211_mlme_deauth(__int64 *a1, __int64 a2, int *a3, __int64 a4, __int64 a5, __int64 a6, char a7)
{
  __int64 v7; // x8
  int v8; // w9
  int v9; // w10
  __int64 result; // x0
  __int64 v11; // x8
  _QWORD *v12; // x0
  __int64 (__fastcall *v13)(_QWORD); // x8

  _ReadStatusReg(SP_EL0);
  v7 = *(_QWORD *)(a2 + 992);
  if ( (a7 & 1) != 0 )
  {
    if ( (*(_BYTE *)(v7 + 164) & 1) == 0
      || (v8 = *((unsigned __int16 *)a3 + 2),
          v9 = *a3,
          *a3 ^ *(_DWORD *)(v7 + 280) | (unsigned __int16)(v8 ^ *(_WORD *)(v7 + 284))) )
    {
      result = 0;
      goto LABEL_13;
    }
  }
  else
  {
    v9 = *a3;
    v8 = *((unsigned __int16 *)a3 + 2);
  }
  if ( !(v9 ^ *(_DWORD *)(v7 + 136) | v8 ^ *(unsigned __int16 *)(v7 + 140))
    || (*(_BYTE *)(v7 + 164) & 1) != 0 && !(*(_DWORD *)(v7 + 280) ^ v9 | *(unsigned __int16 *)(v7 + 284) ^ v8) )
  {
    *(_DWORD *)(v7 + 100) = 0;
  }
  v11 = *a1;
  v12 = a1 + 124;
  v13 = *(__int64 (__fastcall **)(_QWORD))(v11 + 352);
  if ( *((_DWORD *)v13 - 1) != 444399895 )
    __break(0x8228u);
  result = v13(v12);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
