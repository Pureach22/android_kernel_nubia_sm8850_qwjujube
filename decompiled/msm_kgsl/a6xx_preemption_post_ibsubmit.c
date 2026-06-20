__int64 __fastcall a6xx_preemption_post_ibsubmit(_QWORD *a1, __int64 a2)
{
  unsigned __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x10
  unsigned __int64 v6; // x10
  __int64 v7; // x10

  if ( (a1[1780] & 0x200) == 0 )
    return 0;
  v3 = a1[2455];
  if ( v3 )
  {
    v4 = *(int *)(v3 + 28);
    v5 = *(_QWORD *)(a1[2562] + 24LL);
    *(_QWORD *)(a2 + 12) = 0;
    v3 = v5 + 8 * v4;
    v6 = HIDWORD(v3);
    *(_DWORD *)a2 = 1883045892;
    *(_DWORD *)(a2 + 4) = v3;
    LODWORD(v3) = 5;
    *(_DWORD *)(a2 + 8) = v6;
  }
  v7 = a2 + 4LL * (unsigned int)v3;
  *(_DWORD *)(a2 + 4LL * ((unsigned int)v3 | 2)) = 0;
  *(_DWORD *)v7 = 1886060548;
  *(_DWORD *)(v7 + 4) = 0;
  *(_QWORD *)(v7 + 12) = 1;
  return (unsigned int)(v3 + 5);
}
