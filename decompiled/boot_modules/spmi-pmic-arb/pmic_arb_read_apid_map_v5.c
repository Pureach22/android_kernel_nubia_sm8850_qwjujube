__int64 __fastcall pmic_arb_read_apid_map_v5(__int64 result)
{
  __int64 v1; // x20
  __int16 v2; // w8
  unsigned __int16 v3; // w22
  __int64 v4; // x23
  __int64 v5; // x19
  char *v6; // x24
  __int64 (__fastcall *v7)(_QWORD); // x8
  unsigned __int64 v8; // x21
  _DWORD *v9; // x8
  unsigned int *v10; // x0
  int v11; // w8
  __int64 v12; // x12
  char v13; // w9
  __int64 v14; // x10
  int v15; // w9
  int v16; // w11
  __int64 v17; // x9

  v1 = *(unsigned __int16 *)(result + 52);
  v2 = *(_WORD *)(result + 56);
  v3 = v1 + v2;
  if ( (unsigned int)v1 < (unsigned __int16)(v1 + v2) )
  {
    v4 = *(_QWORD *)result;
    v5 = result;
    v6 = (char *)(*(_QWORD *)(result + 152) + 4 * v1 + 3);
    do
    {
      v7 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v4 + 56) + 96LL);
      if ( *((_DWORD *)v7 - 1) != 932471953 )
        __break(0x8228u);
      result = v7((unsigned int)v1);
      if ( *(_QWORD *)(v4 + 32) <= (unsigned __int64)(unsigned int)result )
        break;
      result = readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 24) + (unsigned int)result));
      if ( (_DWORD)result )
      {
        v8 = (unsigned int)result;
        v9 = *(_DWORD **)(*(_QWORD *)(v4 + 56) + 104LL);
        if ( *(v9 - 1) != -395291818 )
          __break(0x8228u);
        v10 = (unsigned int *)((__int64 (__fastcall *)(__int64, _QWORD))v9)(v5, (unsigned int)v1);
        result = readl_relaxed(v10);
        v11 = result & 7;
        v12 = (v8 >> 8) & 0xFFF;
        if ( (v8 & 0x1000000) != 0 )
          v13 = result & 7;
        else
          v13 = -1;
        *(v6 - 1) = v11;
        *v6 = v13;
        v14 = *(_QWORD *)(v5 + 136);
        v15 = *(__int16 *)(v14 + 2 * v12);
        if ( (v15 & 0x80000000) == 0 || (v16 = *(unsigned __int8 *)(v4 + 49), v11 == v16) )
        {
          *(_WORD *)(v14 + 2 * v12) = v1 | 0x8000;
        }
        else if ( (v8 & 0x1000000) != 0 )
        {
          v17 = *(_QWORD *)(v5 + 152) + 4LL * (v15 & 0x7FFF);
          if ( *(unsigned __int8 *)(v17 + 2) == v16 )
            *(_BYTE *)(v17 + 3) = v11;
        }
        *(_WORD *)(v6 - 3) = ((unsigned int)v8 >> 8) & 0xFFF;
        *(_WORD *)(v5 + 144) = v1;
      }
      LODWORD(v1) = v1 + 1;
      v6 += 4;
    }
    while ( (unsigned __int16)v1 < (unsigned int)v3 );
  }
  return result;
}
