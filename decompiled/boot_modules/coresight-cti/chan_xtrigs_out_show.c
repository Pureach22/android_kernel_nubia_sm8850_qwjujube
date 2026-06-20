__int64 __fastcall chan_xtrigs_out_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x23
  __int64 v6; // x20
  int v7; // w22
  __int64 v8; // x25
  __int64 v9; // x24
  __int64 v11; // x0

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  v5 = *(unsigned int *)(v4 + 68);
  if ( (int)v5 < 1 )
  {
    v7 = 0;
LABEL_8:
    *(_WORD *)(a3 + v7) = 10;
    return v7 + 1;
  }
  else
  {
    v6 = 0;
    v7 = 0;
    v8 = v4 + 652;
    v9 = 1LL << *(_BYTE *)(v4 + 129);
    while ( v6 != 128 )
    {
      if ( (*(_DWORD *)(v8 + 4 * v6) & (unsigned int)v9) != 0 )
        v7 += sprintf((char *)(a3 + v7), "%d ", v6);
      if ( v5 == ++v6 )
        goto LABEL_8;
    }
    __break(0x5512u);
    v11 = MEMORY[0x71128BC]();
    return chan_xtrigs_reset_store(v11);
  }
}
