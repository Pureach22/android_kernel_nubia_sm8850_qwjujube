__int64 __fastcall gic_do_class_update_virtual(__int64 a1, __int16 a2, char a3, char a4)
{
  unsigned int v4; // w8

  v4 = a2 & 0x1FFF | 0x40000000;
  if ( (a3 & 1) == 0 )
    v4 = a2 & 0x1FFF;
  if ( (a4 & 1) != 0 )
    v4 |= 0x80000000;
  return writel_relaxed(v4, a1 + 40);
}
