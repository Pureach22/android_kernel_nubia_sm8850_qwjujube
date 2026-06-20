__int64 __fastcall _compression_ratio(_DWORD *a1, int a2)
{
  __int64 v2; // x9

  if ( a1[4] == a2 )
  {
    v2 = 0;
    return *(_QWORD *)&a1[4 * v2 + 6];
  }
  if ( a1[8] == a2 )
  {
    v2 = 1;
    return *(_QWORD *)&a1[4 * v2 + 6];
  }
  if ( a1[12] == a2 )
  {
    v2 = 2;
    return *(_QWORD *)&a1[4 * v2 + 6];
  }
  if ( a1[16] == a2 )
  {
    v2 = 3;
    return *(_QWORD *)&a1[4 * v2 + 6];
  }
  if ( a1[20] == a2 )
  {
    v2 = 4;
    return *(_QWORD *)&a1[4 * v2 + 6];
  }
  _warn_printk("Shouldn't be here, LUT possibly corrupted?\n");
  __break(0x800u);
  return 0;
}
