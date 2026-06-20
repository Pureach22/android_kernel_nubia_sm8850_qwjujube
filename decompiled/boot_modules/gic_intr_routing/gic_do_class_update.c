__int64 __fastcall gic_do_class_update(__int64 a1, unsigned int a2, char a3, char a4)
{
  unsigned int v4; // w8
  int v6; // w20
  __int64 v7; // x22
  unsigned int v8; // w20
  __int64 v9; // x21
  char v10; // w23
  int v11; // w0

  if ( byte_7B4C == 1 )
  {
    v4 = ((_WORD)a2 + 32) & 0x1FFF;
    if ( (a3 & 1) != 0 )
      v4 = ((_WORD)a2 + 32) & 0x1FFF | 0x40000000;
    if ( (a4 & 1) != 0 )
      v4 |= 0x80000000;
    return writel_relaxed(v4, (unsigned int *)(a1 + 40));
  }
  else
  {
    if ( (a3 & 1) != 0 )
      v6 = 2;
    else
      v6 = 0;
    v7 = a1 + 57352;
    v8 = v6 & 0xFFFFFFFE | a4 & 1;
    v9 = (a2 >> 2) & 0x3FFFFFFC;
    v10 = a2;
    raw_spin_lock(&gic_class_lock);
    v11 = readl_relaxed((unsigned int *)(v7 + v9));
    writel_relaxed(v11 & ~(3 << (4 * (v10 & 0xF))) | (v8 << (4 * (v10 & 0xF))), (unsigned int *)(v7 + v9));
    return raw_spin_unlock(&gic_class_lock);
  }
}
