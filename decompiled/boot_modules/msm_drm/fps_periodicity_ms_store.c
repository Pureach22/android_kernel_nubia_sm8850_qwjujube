__int64 __fastcall fps_periodicity_ms_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  int v6; // w0
  int v7; // w8
  unsigned int v8; // w8

  if ( !a1 || !a3 )
  {
    printk(&unk_2120FD, "fps_periodicity_ms_store");
    return -11;
  }
  v4 = *(_QWORD *)(a1 + 152);
  if ( !v4 )
    return -22;
  v6 = kstrtouint(a3, 10, v4 + 4468);
  if ( v6 < 0 )
    return v6;
  v7 = *(_DWORD *)(v4 + 4468);
  if ( !v7 )
  {
    v8 = 1000000;
    goto LABEL_11;
  }
  v8 = 1000 * v7;
  if ( v8 <= 0x4C4B40 )
  {
LABEL_11:
    *(_DWORD *)(v4 + 4468) = v8;
    return a4;
  }
  *(_DWORD *)(v4 + 4468) = 5000000;
  return a4;
}
