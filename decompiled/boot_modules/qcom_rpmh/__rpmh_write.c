__int64 __fastcall _rpmh_write(__int64 a1, int a2, __int64 a3)
{
  __int64 v5; // x20
  unsigned int v6; // w23
  unsigned int v7; // w26
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 v10; // x9
  _DWORD *v11; // x8
  __int64 v12; // x12
  unsigned __int64 v13; // x22
  int v14; // w9
  int v15; // w10
  int v16; // w8
  int v17; // w8
  bool v18; // w8

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( *(_DWORD *)(a3 + 8) )
  {
    v6 = 0;
    v7 = a2 - 1;
    do
    {
      v8 = *(_QWORD *)(a3 + 16);
      v9 = raw_spin_lock_irqsave(v5 + 1152);
      v10 = *(unsigned int *)(v5 + 1632);
      if ( (unsigned int)v10 > 0xF9 )
        goto LABEL_27;
      v11 = (_DWORD *)(v8 + 12LL * (int)v6);
      if ( (_DWORD)v10 )
      {
        v12 = *(unsigned int *)(v5 + 1632);
        v13 = *(_QWORD *)(v5 + 1640);
        while ( *(_DWORD *)v13 != *v11 )
        {
          --v12;
          v13 += 32LL;
          if ( !v12 )
            goto LABEL_10;
        }
      }
      else
      {
        v10 = 0;
LABEL_10:
        v13 = *(_QWORD *)(v5 + 1640) + 32 * v10;
        *(_QWORD *)(v13 + 4) = -1;
        ++*(_DWORD *)(v5 + 1632);
      }
      if ( !v13 )
      {
LABEL_27:
        raw_spin_unlock_irqrestore(v5 + 1152, v9);
        LODWORD(v13) = -12;
        return (unsigned int)v13;
      }
      v15 = *(_DWORD *)(v13 + 4);
      v14 = *(_DWORD *)(v13 + 8);
      *(_DWORD *)v13 = *v11;
      if ( v7 >= 2 )
      {
        if ( a2 || (v17 = v11[1], *(_DWORD *)(v13 + 4) = v17, v17 == v15) )
        {
LABEL_19:
          v18 = 0;
          goto LABEL_20;
        }
      }
      else
      {
        v16 = v11[1];
        *(_DWORD *)(v13 + 8) = v16;
        if ( v16 == v14 )
          goto LABEL_19;
        v14 = v16;
        v17 = v15;
      }
      if ( v17 == -1 )
        goto LABEL_19;
      v18 = v14 != -1;
LABEL_20:
      *(_BYTE *)(v5 + 1156) |= v18;
      raw_spin_unlock_irqrestore(v5 + 1152, v9);
      if ( v13 >= 0xFFFFFFFFFFFFF001LL )
        return (unsigned int)v13;
      ++v6;
    }
    while ( v6 < *(_DWORD *)(a3 + 8) );
  }
  if ( a2 == 2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      __break(0x800u);
    LODWORD(v13) = rpmh_rsc_get_channel(v5);
    if ( (v13 & 0x80000000) == 0 )
      LODWORD(v13) = rpmh_rsc_send_data(v5, (unsigned int *)a3, v13);
  }
  else
  {
    if ( *(_QWORD *)(a3 + 216) )
      complete();
    LODWORD(v13) = 0;
  }
  return (unsigned int)v13;
}
