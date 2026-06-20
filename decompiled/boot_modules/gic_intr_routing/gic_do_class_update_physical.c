__int64 __fastcall gic_do_class_update_physical(__int64 a1, unsigned int a2, char a3, char a4)
{
  int v4; // w21
  __int64 v5; // x23
  char v6; // w19
  unsigned int v7; // w21
  __int64 v8; // x22
  int v9; // w0

  if ( (a3 & 1) != 0 )
    v4 = 2;
  else
    v4 = 0;
  v5 = a1 + 57352;
  v6 = a2;
  v7 = v4 & 0xFFFFFFFE | a4 & 1;
  v8 = (a2 >> 2) & 0x3FFFFFFC;
  raw_spin_lock(&gic_class_lock);
  v9 = readl_relaxed(v5 + v8);
  writel_relaxed(v9 & ~(3 << (4 * (v6 & 0xF))) | (v7 << (4 * (v6 & 0xF))), (unsigned int *)(v5 + v8));
  return raw_spin_unlock(&gic_class_lock);
}
