__int64 __fastcall cti_channel_gate_op(__int64 a1, int a2, unsigned int a3)
{
  __int64 *v3; // x20
  __int64 v5; // x21
  int v6; // w8
  unsigned int v7; // w19
  unsigned int v8; // w19
  int v9; // w8
  int v10; // w21
  __int64 v11; // x8
  __int64 v12; // x8

  v3 = *(__int64 **)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( *((_DWORD *)v3 + 16) > a3 )
  {
    v5 = 1LL << a3;
    raw_spin_lock(v3 + 7);
    v6 = *((_DWORD *)v3 + 291);
    if ( a2 == 1 )
    {
      v7 = v6 & ~(_DWORD)v5;
    }
    else
    {
      if ( a2 )
      {
        v8 = -22;
LABEL_15:
        raw_spin_unlock(v3 + 7);
        return v8;
      }
      v7 = v6 | v5;
    }
    v9 = *((unsigned __int8 *)v3 + 77);
    *((_DWORD *)v3 + 291) = v7;
    if ( v9 == 1 && *((_BYTE *)v3 + 76) == 1 )
    {
      v10 = *((unsigned __int8 *)v3 + 1200);
      writel_relaxed(0xC5ACCE55, (unsigned int *)(*v3 + 4016));
      __dsb(0xFu);
      v11 = *v3;
      if ( v10 == 1 )
        writel_relaxed(v7, (unsigned int *)(v11 + 136));
      else
        writel_relaxed(v7, (unsigned int *)(v11 + 320));
      v12 = *v3;
      __dsb(0xFu);
      writel_relaxed(0, (unsigned int *)(v12 + 4016));
    }
    v8 = 0;
    goto LABEL_15;
  }
  return (unsigned int)-22;
}
