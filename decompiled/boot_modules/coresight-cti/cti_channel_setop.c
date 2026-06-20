__int64 __fastcall cti_channel_setop(__int64 a1, int a2, unsigned int a3)
{
  __int64 *v3; // x21
  __int64 v5; // x19
  int v6; // w8
  int v7; // w9
  __int64 v8; // x20
  unsigned int v9; // w19
  int v10; // w8
  __int64 v11; // x10
  bool v12; // zf
  __int64 v13; // x9
  __int64 v14; // x8

  v3 = *(__int64 **)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( *((_DWORD *)v3 + 16) > a3 )
  {
    v5 = 1LL << a3;
    raw_spin_lock(v3 + 7);
    v6 = *((_DWORD *)v3 + 33);
    if ( a2 == 2 )
    {
      v10 = v6 & ~(_DWORD)v5;
      v11 = 12;
      v12 = *((_BYTE *)v3 + 1200) == 0;
      v13 = 28;
    }
    else
    {
      if ( a2 != 1 )
      {
        if ( a2 )
        {
          v9 = -22;
LABEL_20:
          raw_spin_unlock(v3 + 7);
          return v9;
        }
        v7 = *((unsigned __int8 *)v3 + 1200);
        LODWORD(v5) = v6 | v5;
        *((_DWORD *)v3 + 33) = v5;
        if ( v7 )
          v8 = 4;
        else
          v8 = 20;
LABEL_15:
        if ( *((_BYTE *)v3 + 77) == 1 && *((_BYTE *)v3 + 76) == 1 )
        {
          writel_relaxed(0xC5ACCE55, (unsigned int *)(*v3 + 4016));
          __dsb(0xFu);
          writel_relaxed(v5, (unsigned int *)(*v3 + v8));
          v14 = *v3;
          __dsb(0xFu);
          writel_relaxed(0, (unsigned int *)(v14 + 4016));
        }
        v9 = 0;
        goto LABEL_20;
      }
      v10 = v6 & ~(_DWORD)v5;
      v11 = 8;
      v12 = *((_BYTE *)v3 + 1200) == 0;
      v13 = 24;
    }
    if ( v12 )
      v8 = v13;
    else
      v8 = v11;
    *((_DWORD *)v3 + 33) = v10;
    goto LABEL_15;
  }
  return (unsigned int)-22;
}
