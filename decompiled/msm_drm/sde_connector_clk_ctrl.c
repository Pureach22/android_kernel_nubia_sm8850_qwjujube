__int64 __fastcall sde_connector_clk_ctrl(__int64 a1, char a2, char a3)
{
  _QWORD *v5; // x8
  _QWORD *v6; // x21
  _DWORD *v7; // x8
  _DWORD *v8; // x8
  void *v10; // x0

  if ( !a1 )
  {
    v10 = &unk_242658;
LABEL_19:
    printk(v10, "sde_connector_clk_ctrl");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 2736) != 16 )
  {
    v6 = nullptr;
    v7 = *(_DWORD **)(a1 + 3024);
    if ( v7 )
      goto LABEL_7;
    goto LABEL_10;
  }
  v5 = (_QWORD *)(a1 + 2760);
  if ( *(_BYTE *)(a1 + 5128) == 1 )
    v5 = (_QWORD *)*v5;
  v6 = (_QWORD *)*v5;
  if ( !*v5 )
  {
    v10 = &unk_25EF7D;
    goto LABEL_19;
  }
  v7 = *(_DWORD **)(a1 + 3024);
  if ( v7 )
  {
LABEL_7:
    if ( *(v7 - 1) != -538254584 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD))v7)(v6, a3 & 1);
  }
LABEL_10:
  v8 = *(_DWORD **)(a1 + 3008);
  if ( !v8 )
    return 0;
  if ( *(v8 - 1) != -1378032659 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(_QWORD *, __int64, _QWORD))v8)(v6, 3, a2 & 1);
}
