__int64 __fastcall populate_ibs_0(__int64 result, _DWORD *a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  int v5; // w10
  _DWORD *v6; // x8
  _QWORD *i; // x10

  if ( *(_DWORD *)(a3 + 160) < 0x53u )
  {
    v6 = a2 + 8;
  }
  else
  {
    if ( (*(_QWORD *)(a3 + 56) & 0x20LL) != 0 )
      v3 = 24624;
    else
      v3 = 24616;
    v4 = *(_QWORD *)(result + v3);
    v5 = *(_DWORD *)(v4 + 184);
    a2[2] |= 0x200u;
    a2[7] = v5;
    v6 = *(_DWORD **)(v4 + 8);
  }
  for ( i = *(_QWORD **)(a3 + 88); i != (_QWORD *)(a3 + 88); i = (_QWORD *)*i )
  {
    *(_QWORD *)v6 = i[4];
    v6[2] = i[5];
    v6 += 3;
  }
  a2[6] = *(_DWORD *)(a3 + 160);
  return result;
}
