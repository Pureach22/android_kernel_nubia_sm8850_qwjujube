__int64 __fastcall target_if_spectral_fw_hang(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 (__fastcall *v11)(_QWORD); // x9
  __int64 v13; // x0
  __int64 v14; // x19
  __int64 v15; // x9
  __int64 (__fastcall *v16)(__int64, __int64 *); // x8
  __int64 *v17; // x9
  __int64 v18; // x0
  __int64 result; // x0
  const char *v20; // x2
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Spectral LMAC object is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_spectral_fw_hang",
      v21,
      v22);
    result = 4;
    goto LABEL_17;
  }
  if ( !*a1 )
  {
    v20 = "%s: pdev is null";
LABEL_16:
    qdf_trace_msg(0x56u, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_spectral_fw_hang", v21);
    result = 16;
    goto LABEL_17;
  }
  v9 = *(_QWORD *)(*a1 + 80);
  if ( !v9 )
  {
    v20 = "%s: psoc is null";
    goto LABEL_16;
  }
  v10 = *(_QWORD *)(v9 + 2136);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: rx_ops is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "get_target_if_spectral_handle_from_psoc",
      v21,
      v22);
LABEL_15:
    v20 = "%s: spectral psoc object is null";
    goto LABEL_16;
  }
  v11 = *(__int64 (__fastcall **)(_QWORD))(v10 + 264);
  if ( *((_DWORD *)v11 - 1) != -373219892 )
    __break(0x8229u);
  v13 = v11(v9);
  if ( !v13 )
    goto LABEL_15;
  v14 = v13;
  qdf_mem_set(&v21, 8u, 0);
  v15 = *a1;
  v16 = *(__int64 (__fastcall **)(__int64, __int64 *))(v14 + 24);
  LODWORD(v21) = 1;
  if ( v15 && (v17 = *(__int64 **)(v15 + 1240)) != nullptr )
    v18 = *v17;
  else
    v18 = 0;
  if ( *((_DWORD *)v16 - 1) != -58816714 )
    __break(0x8228u);
  result = v16(v18, &v21);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
