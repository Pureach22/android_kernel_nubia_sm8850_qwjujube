__int64 __fastcall tp_show(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v3; // x19
  int v4; // w8
  void *v6; // x0

  if ( !a1 )
  {
    v6 = &unk_241618;
LABEL_9:
    printk(v6, "tp_show");
    return -19;
  }
  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
  {
    v6 = &unk_2339E9;
    goto LABEL_9;
  }
  v4 = *(_DWORD *)(v3 + 824);
  if ( v4 != 3 && v4 )
    return -22;
  *a3 = v4;
  a3[1] = 1;
  memcpy(a3 + 2, (const void *)(v3 + 168), 0x290u);
  *(_DWORD *)(v3 + 824) = 3;
  return 658;
}
