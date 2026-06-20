__int64 __fastcall awrw_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 v5; // x21
  unsigned int v6; // w23
  int v7; // w0
  void *v9; // x0
  __int64 v10; // x2

  v3 = *(_QWORD *)(a1 + 152);
  if ( *(_DWORD *)(v3 + 1320) != 1 )
  {
    v9 = &unk_141C8;
    v10 = 3152;
LABEL_12:
    printk(v9, "haptic_hv", v10, "awrw_show");
    return -34;
  }
  if ( !*(_QWORD *)(v3 + 1328) )
  {
    v9 = &unk_15A3D;
    v10 = 3156;
    goto LABEL_12;
  }
  if ( *(_DWORD *)(v3 + 1324) )
  {
    v5 = 0;
    v6 = 0;
    do
    {
      v7 = snprintf((char *)(a3 + v5), 4096 - v5, "0x%02x,", *(unsigned __int8 *)(*(_QWORD *)(v3 + 1328) + (int)v6++));
      v5 += v7;
    }
    while ( v6 < *(_DWORD *)(v3 + 1324) );
  }
  else
  {
    v5 = 0;
  }
  return v5 + snprintf((char *)(a3 + v5 - 1), 4096 - v5, "\n");
}
