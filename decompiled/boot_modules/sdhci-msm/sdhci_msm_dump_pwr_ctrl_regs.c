__int64 __fastcall sdhci_msm_dump_pwr_ctrl_regs(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x22
  __int64 v4; // x19
  void (*v5)(void); // x8
  __int64 v6; // x1
  void (__fastcall *v7)(__int64, __int64); // x8
  __int64 v8; // x1
  void (__fastcall *v9)(__int64, __int64); // x8

  v1 = *(_QWORD *)(a1 + 72);
  v2 = *(_QWORD *)(a1 + 1624);
  v4 = *(_QWORD *)(v1 + 120);
  if ( !v4 )
    v4 = *(_QWORD *)(v1 + 8);
  v5 = **(void (***)(void))(a1 + 1616);
  if ( *((_DWORD *)v5 - 1) != -1793813973 )
    __break(0x8228u);
  v5();
  v6 = *(unsigned int *)(v2 + 44);
  v7 = **(void (__fastcall ***)(__int64, __int64))(a1 + 1616);
  if ( *((_DWORD *)v7 - 1) != -1793813973 )
    __break(0x8228u);
  v7(a1, v6);
  v8 = *(unsigned int *)(v2 + 52);
  v9 = **(void (__fastcall ***)(__int64, __int64))(a1 + 1616);
  if ( *((_DWORD *)v9 - 1) != -1793813973 )
    __break(0x8228u);
  v9(a1, v8);
  return printk(&unk_FB5C, v4);
}
