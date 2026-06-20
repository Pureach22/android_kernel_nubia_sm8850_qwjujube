__int64 __fastcall cqhci_off(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x8
  __int64 v3; // x20
  void (*v4)(void); // x9
  _DWORD *v5; // x8
  __int64 v6; // x0
  __int64 v7; // x21
  _DWORD *v8; // x8
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  _DWORD *v12; // x8
  __int64 v13; // x9
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x1

  v1 = *(_QWORD **)(result + 1464);
  if ( *((_BYTE *)v1 + 56) == 1 && *(_BYTE *)(result + 1477) == 1 && (*((_BYTE *)v1 + 61) & 1) == 0 )
  {
    v2 = *v1;
    v3 = result;
    v4 = *(void (**)(void))(*v1 + 32LL);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != -289083512 )
        __break(0x8229u);
      v4();
      v2 = *v1;
    }
    v5 = *(_DWORD **)(v2 + 8);
    if ( v5 )
    {
      if ( *(v5 - 1) != -1433747670 )
        __break(0x8228u);
      v6 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v5)(v1, 1, 12);
    }
    else
    {
      v6 = writel_relaxed(1u, (unsigned int *)(v1[1] + 12LL));
    }
    v7 = ktime_get(v6) + 100000;
    while ( 1 )
    {
      v8 = *(_DWORD **)(*v1 + 16LL);
      if ( v8 )
      {
        if ( *(v8 - 1) != 1427797680 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(_QWORD *, __int64))v8)(v1, 12);
        if ( (result & 1) != 0 )
          goto LABEL_21;
      }
      else
      {
        result = readl_relaxed((unsigned int *)(v1[1] + 12LL));
        if ( (result & 1) != 0 )
          goto LABEL_21;
      }
      if ( ktime_get(result) > v7 )
        break;
      __yield();
    }
    v12 = *(_DWORD **)(*v1 + 16LL);
    if ( !v12 )
    {
      result = readl_relaxed((unsigned int *)(v1[1] + 12LL));
LABEL_21:
      if ( (result & 1) != 0 )
        goto LABEL_22;
LABEL_34:
      v15 = *(_QWORD *)(v3 + 120);
      if ( !v15 )
        v15 = *(_QWORD *)(v3 + 8);
      result = printk(&unk_9EA7, v15, v9, v10, v11);
      goto LABEL_22;
    }
    if ( *(v12 - 1) != 1427797680 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(_QWORD *, __int64))v12)(v1, 12);
    if ( (result & 1) == 0 )
      goto LABEL_34;
LABEL_22:
    v13 = v3;
    v14 = *(__int64 (__fastcall **)(_QWORD))(*v1 + 56LL);
    if ( v14 )
    {
      if ( *((_DWORD *)v14 - 1) != -452870896 )
        __break(0x8228u);
      result = v14(v3);
      v13 = v3;
    }
    *(_BYTE *)(v13 + 1477) = 0;
  }
  return result;
}
