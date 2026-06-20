__int64 __fastcall tgt_register_spectral_wmi_ops(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 (*v11)(void); // x8
  const char *v13; // x2

  if ( !a1 )
  {
    v13 = "%s: psoc is null";
LABEL_10:
    qdf_trace_msg(0x56u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_register_spectral_wmi_ops");
    return 4;
  }
  if ( !a2 )
  {
    v13 = "%s: WMI operations table is null";
    goto LABEL_10;
  }
  v10 = *(_QWORD *)(a1 + 2128);
  if ( !v10 )
  {
    v13 = "%s: tx_ops is NULL";
    goto LABEL_10;
  }
  v11 = *(__int64 (**)(void))(v10 + 600);
  if ( *((_DWORD *)v11 - 1) != 1034656386 )
    __break(0x8228u);
  return v11();
}
