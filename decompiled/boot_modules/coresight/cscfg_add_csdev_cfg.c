__int64 __fastcall cscfg_add_csdev_cfg(_QWORD *a1, __int64 a2)
{
  int v2; // w26
  __int64 v5; // x24
  unsigned __int64 v6; // x20
  _QWORD *v7; // x21
  _QWORD *v8; // x25
  _QWORD *v9; // x27
  const char *v10; // x23
  _QWORD *v11; // x0
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  _QWORD *v14; // x2
  _QWORD *v15; // x1
  _QWORD *v16; // x0

  v2 = *(_DWORD *)(a2 + 32);
  if ( v2 < 1 )
    return 0;
  v5 = 0;
  v6 = 0;
  v7 = nullptr;
  v8 = a1 + 126;
  while ( 2 )
  {
    v9 = v8;
    v10 = *(const char **)(*(_QWORD *)(a2 + 40) + 8 * v5);
    do
    {
      v9 = (_QWORD *)*v9;
      if ( v9 == v8 )
        goto LABEL_4;
    }
    while ( strcmp(*(const char **)*(v9 - 2), v10) );
    if ( v9 == &qword_10 )
      goto LABEL_4;
    if ( v7 )
      goto LABEL_14;
    v6 = 8LL * v2 + 48;
    v11 = (_QWORD *)devm_kmalloc(a1[19], v6, 3520);
    if ( v11 )
    {
      if ( v2 == -5 || 8LL * v2 == -48 )
        goto LABEL_19;
      v7 = v11;
      *v11 = a2;
      v11[1] = a1;
LABEL_14:
      if ( v6 < 0x28
        || (v6 & 0xFFFFFFFFFFFFFFFCLL) == 0x28
        || (v12 = *((int *)v7 + 10), *((_DWORD *)v7 + 10) = v12 + 1, (int)v12 < -6)
        || (v13 = 8 * v12 + 48, v6 < v13)
        || v6 - v13 < 8 )
      {
        while ( 1 )
        {
LABEL_19:
          __break(1u);
LABEL_20:
          if ( !v7 )
            return 0;
          raw_spin_lock_irqsave(a1 + 130);
          v14 = (_QWORD *)a1[128];
          v15 = a1 + 128;
          v16 = v7 + 3;
          if ( (_QWORD *)v14[1] != a1 + 128 || v16 == v15 || v14 == v16 )
            break;
          v14[1] = v16;
          if ( v6 >= 0x18 && (v6 & 0xFFFFFFFFFFFFFFF8LL) != 0x18 )
          {
            *v16 = v14;
            if ( v6 >= 0x20 && (v6 & 0xFFFFFFFFFFFFFFF8LL) != 0x20 )
            {
              v7[4] = v15;
              *v15 = v16;
LABEL_29:
              raw_spin_unlock_irqrestore(a1 + 130);
              return 0;
            }
          }
        }
        _list_add_valid_or_report(v16, v15);
        goto LABEL_29;
      }
      v7[v12 + 6] = v9 - 2;
      v2 = *(_DWORD *)(a2 + 32);
LABEL_4:
      if ( ++v5 >= v2 )
        goto LABEL_20;
      continue;
    }
    return 4294967284LL;
  }
}
