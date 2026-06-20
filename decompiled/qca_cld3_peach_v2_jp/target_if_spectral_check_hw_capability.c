__int64 __fastcall target_if_spectral_check_hw_capability(__int64 a1)
{
  unsigned int (*v1)(void); // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int (__fastcall *v11)(__int64, __int64); // x8
  unsigned int (__fastcall *v12)(__int64, __int64); // x8
  unsigned int (__fastcall *v13)(__int64, __int64); // x9
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v23; // x2

  v1 = *(unsigned int (**)(void))(a1 + 16);
  if ( *((_DWORD *)v1 - 1) != 182839231 )
    __break(0x8228u);
  if ( !v1() )
  {
    v23 = "%s: SPECTRAL : No PHYDIAG support";
LABEL_17:
    qdf_trace_msg(0x56u, 4u, v23, v3, v4, v5, v6, v7, v8, v9, v10, "target_if_spectral_check_hw_capability");
    return 0;
  }
  v11 = *(unsigned int (__fastcall **)(__int64, __int64))(a1 + 16);
  *(_BYTE *)(a1 + 184) = 1;
  if ( *((_DWORD *)v11 - 1) != 182839231 )
    __break(0x8228u);
  if ( !v11(a1, 1) )
  {
    v23 = "%s: SPECTRAL : No RADAR support";
    goto LABEL_17;
  }
  v12 = *(unsigned int (__fastcall **)(__int64, __int64))(a1 + 16);
  *(_BYTE *)(a1 + 185) = 1;
  if ( *((_DWORD *)v12 - 1) != 182839231 )
    __break(0x8228u);
  if ( !v12(a1, 2) )
  {
    v23 = "%s: SPECTRAL : No SPECTRAL SUPPORT";
    goto LABEL_17;
  }
  v13 = *(unsigned int (__fastcall **)(__int64, __int64))(a1 + 16);
  *(_BYTE *)(a1 + 186) = 1;
  if ( *((_DWORD *)v13 - 1) != 182839231 )
    __break(0x8229u);
  if ( v13(a1, 3) )
  {
    *(_BYTE *)(a1 + 187) = 1;
    return 1;
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      4u,
      "%s: SPECTRAL : No ADVANCED SPECTRAL SUPPORT",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_spectral_check_hw_capability");
    return 1;
  }
}
