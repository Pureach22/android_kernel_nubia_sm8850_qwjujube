__int64 __fastcall qbt_poll(__int64 a1, void (**a2)(void))
{
  _DWORD *v2; // x19
  int v3; // w8
  void (*v4)(void); // x8
  int v5; // w8
  int v6; // w9
  void (*v7)(void); // x8
  void *v9; // x0

  if ( !a1 || (v2 = *(_DWORD **)(a1 + 32)) == nullptr )
  {
    v9 = &unk_9A11;
LABEL_22:
    printk(v9, "qbt_poll");
    return 4294967274LL;
  }
  v3 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 76LL) & 0xFFFFF;
  if ( v3 == 1 )
  {
    if ( a2 )
    {
      v7 = *a2;
      if ( *a2 )
      {
        if ( *((_DWORD *)v7 - 1) != -442429149 )
          __break(0x8228u);
        v7();
        __dmb(0xBu);
      }
    }
    v5 = v2[2858];
    v6 = v2[2859];
    goto LABEL_17;
  }
  if ( v3 )
  {
    v9 = &unk_9C65;
    goto LABEL_22;
  }
  if ( a2 )
  {
    v4 = *a2;
    if ( *a2 )
    {
      if ( *((_DWORD *)v4 - 1) != -442429149 )
        __break(0x8228u);
      v4();
      __dmb(0xBu);
    }
  }
  v5 = v2[1572];
  v6 = v2[1573];
LABEL_17:
  if ( v5 == v6 )
    return 0;
  else
    return 65;
}
