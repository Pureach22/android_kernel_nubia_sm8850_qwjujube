__int64 __fastcall lmac_get_tsf64(
        __int64 a1,
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
  __int64 v10; // x8
  void (*v11)(void); // x8
  __int64 result; // x0
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 2128)) == 0 )
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: tx_ops is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "lmac_get_tsf64",
      0,
      v13);
    goto LABEL_8;
  }
  v11 = *(void (**)(void))(v10 + 1152);
  if ( !v11 )
  {
LABEL_8:
    result = 0;
    goto LABEL_9;
  }
  if ( *((_DWORD *)v11 - 1) != 876928243 )
    __break(0x8228u);
  v11();
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
