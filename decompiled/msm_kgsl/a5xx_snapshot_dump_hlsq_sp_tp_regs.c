unsigned __int64 __fastcall a5xx_snapshot_dump_hlsq_sp_tp_regs(_QWORD *a1, _DWORD *a2, unsigned __int64 a3)
{
  int v3; // w9
  unsigned __int64 v4; // x8
  __int64 v6; // x10
  _DWORD *v7; // x11
  char *v8; // x16
  int v9; // w15
  __int64 v10; // x2
  unsigned __int64 v11; // x15
  unsigned __int64 v12; // x16
  int v13; // w17
  __int64 v14; // x0
  _DWORD *v15; // x2
  int v16; // w3

  v3 = (int)off_88E8
     + (_DWORD)off_88A0
     + dword_88B8
     + dword_88D0
     + (unsigned __int64)off_8888
     + (_DWORD)off_8870
     + dword_8858
     + (unsigned __int64)off_8828
     + dword_8840
     + dword_8810
     + dword_87F8
     + dword_8948
     + dword_8930
     + dword_8918
     + dword_8900;
  v4 = (8 * v3) | 4;
  if ( v4 <= a3 )
  {
    v6 = 0;
    v7 = a2 + 1;
    do
    {
      v8 = (char *)&a5xx_hlsq_sp_tp_registers + 24 * v6;
      v9 = *((_DWORD *)v8 + 2);
      if ( v9 )
      {
        v10 = *((_QWORD *)v8 + 2);
        v11 = 0;
        v13 = *((_DWORD *)v8 + 1);
        v12 = *((unsigned int *)v8 + 2);
        v14 = v10 + 0xF504000183573LL;
        v15 = v7;
        do
        {
          *v15 = v13 + v11;
          v16 = *(_DWORD *)(v14 + 4 * v11++);
          v15[1] = v16;
          v15 += 2;
        }
        while ( v11 < v12 );
        v9 = 2 * v12;
      }
      ++v6;
      v7 += v9;
    }
    while ( v6 != 15 );
    *a2 = v3;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a5xx_snapshot_dump_hlsq_sp_tp_regs__rs, "a5xx_snapshot_dump_hlsq_sp_tp_regs") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
    return 0;
  }
  return v4;
}
