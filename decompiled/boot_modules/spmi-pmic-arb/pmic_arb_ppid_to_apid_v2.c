__int64 __fastcall pmic_arb_ppid_to_apid_v2(__int64 a1, unsigned __int16 a2)
{
  int v3; // w8
  _QWORD *v4; // x22
  __int64 v5; // x20
  __int64 v7; // x23
  unsigned int (__fastcall *v8)(_QWORD); // x8
  unsigned __int64 v9; // x24
  _BYTE *v10; // x23
  unsigned int (__fastcall *v11)(_QWORD); // x8
  _DWORD *v12; // x8
  unsigned int *v13; // x0
  char v14; // w0
  unsigned __int64 v15; // x0

  v3 = *(__int16 *)(*(_QWORD *)(a1 + 136) + 2LL * a2);
  if ( v3 < 0 )
    return v3 & 0x7FFF;
  v4 = *(_QWORD **)a1;
  v5 = *(unsigned __int16 *)(a1 + 144);
  v7 = *(_QWORD *)(a1 + 152);
  v8 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)a1 + 56LL) + 96LL);
  if ( *((_DWORD *)v8 - 1) != 932471953 )
    __break(0x8228u);
  v9 = v8(v5);
  if ( v4[4] <= v9 )
  {
LABEL_14:
    *(_WORD *)(a1 + 144) = v5 & 0x7FFF;
    if ( (v5 & 0x8000u) != 0LL )
      return v5 & 0x7FFF;
    else
      return 4294967277LL;
  }
  else
  {
    v10 = (_BYTE *)(v7 + 4 * v5 + 3);
    while ( 1 )
    {
      v12 = *(_DWORD **)(v4[7] + 104LL);
      if ( *(v12 - 1) != -395291818 )
        __break(0x8228u);
      v13 = (unsigned int *)((__int64 (__fastcall *)(__int64, _QWORD))v12)(a1, (unsigned int)v5);
      v14 = readl_relaxed(v13);
      *v10 = v14 & 7;
      *(v10 - 1) = v14 & 7;
      v15 = readl_relaxed((unsigned int *)(v4[3] + v9));
      if ( (_DWORD)v15 )
      {
        *(_WORD *)(*(_QWORD *)(a1 + 136) + 2 * ((v15 >> 8) & 0xFFF)) = v5 | 0x8000;
        *(_WORD *)(v10 - 3) = ((unsigned int)v15 >> 8) & 0xFFF;
        if ( (((unsigned int)v15 >> 8) & 0xFFF) == a2 )
          break;
      }
      LODWORD(v5) = v5 + 1;
      v11 = *(unsigned int (__fastcall **)(_QWORD))(v4[7] + 96LL);
      if ( *((_DWORD *)v11 - 1) != 932471953 )
        __break(0x8228u);
      v9 = v11((unsigned int)v5);
      v10 += 4;
      if ( v4[4] <= v9 )
        goto LABEL_14;
    }
    *(_WORD *)(a1 + 144) = v5 & 0x7FFF;
    return v5 & 0x7FFF;
  }
}
