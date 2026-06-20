__int64 __fastcall tp_store(__int64 a1, __int64 a2, _BYTE *a3, __int64 a4)
{
  __int64 v4; // x8
  int v5; // w9
  void *v6; // x0

  if ( !a1 )
  {
    v6 = &unk_241618;
LABEL_9:
    printk(v6, "tp_store");
    return -19;
  }
  v4 = *(_QWORD *)(a1 + 152);
  if ( !v4 )
  {
    v6 = &unk_2339E9;
    goto LABEL_9;
  }
  v5 = (unsigned __int8)*a3;
  if ( v5 != 3 && *a3 )
    return -22;
  *(_DWORD *)(v4 + 824) = v5;
  return a4;
}
