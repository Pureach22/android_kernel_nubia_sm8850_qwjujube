__int64 __fastcall qsmmuv500_cfg_probe(__int64 a1)
{
  __int64 (**v1)(void); // x8
  __int64 (*v3)(void); // x8
  int v4; // w0
  __int64 v5; // x8
  _DWORD *v6; // x8
  _DWORD **v7; // x8
  _DWORD *v8; // x8

  v1 = *(__int64 (***)(void))(a1 + 48);
  if ( v1 && (v3 = *v1) != nullptr )
  {
    if ( *((_DWORD *)v3 - 1) != 616069899 )
      __break(0x8228u);
    v4 = v3();
    v5 = *(_QWORD *)(a1 + 48);
    if ( !v5 )
    {
LABEL_5:
      writel_relaxed_1(v4 & 0xFBFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 8) + 16LL));
      v7 = *(_DWORD ***)(a1 + 48);
      if ( !v7 )
        goto LABEL_7;
      goto LABEL_6;
    }
  }
  else
  {
    v4 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(a1 + 8) + 16LL));
    v5 = *(_QWORD *)(a1 + 48);
    if ( !v5 )
      goto LABEL_5;
  }
  v6 = *(_DWORD **)(v5 + 8);
  if ( !v6 )
    goto LABEL_5;
  if ( *(v6 - 1) != -1008624849 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD))v6)(a1, 0, 16, v4 & 0xFBFFFFFF);
  v7 = *(_DWORD ***)(a1 + 48);
  if ( !v7 )
  {
LABEL_7:
    if ( (readl_relaxed_1((unsigned int *)(*(_QWORD *)(a1 + 8) + 16LL)) & 0x4000000) == 0 )
      return 0;
LABEL_20:
    __break(0x800u);
    return 0;
  }
LABEL_6:
  v8 = *v7;
  if ( !v8 )
    goto LABEL_7;
  if ( *(v8 - 1) != 616069899 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(__int64, _QWORD, __int64))v8)(a1, 0, 16) & 0x4000000) != 0 )
    goto LABEL_20;
  return 0;
}
