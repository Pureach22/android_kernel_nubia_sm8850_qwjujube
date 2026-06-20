__int64 __fastcall gen7_preemption_post_ibsubmit(_QWORD *a1, __int64 a2)
{
  unsigned __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x10
  unsigned __int64 v6; // x10
  _QWORD *v7; // x10

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
  v7 = (_QWORD *)(a2 + 4LL * (unsigned int)v3);
  *(_DWORD *)(a2 + 4LL * ((unsigned int)v3 | 2)) = 1886060548;
  *v7 = 0x370970001LL;
  *(_QWORD *)((char *)v7 + 12) = 0;
  *(_QWORD *)((char *)v7 + 20) = 1;
  return (unsigned int)(v3 + 7);
}
