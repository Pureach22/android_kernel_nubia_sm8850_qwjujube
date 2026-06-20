__int64 __fastcall tgt_sap_is_suspend_supported(
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
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  char v13; // w0
  const char *v14; // x2

  if ( !a1 )
  {
    v14 = "%s: vdev not found";
    goto LABEL_12;
  }
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 || (v11 = *(_QWORD *)(v10 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_10;
  }
  v12 = *(__int64 (**)(void))(v11 + 1656);
  if ( !v12 )
  {
LABEL_10:
    v14 = "%s: VDEV: No Tx Ops";
LABEL_12:
    qdf_trace_msg(0x68u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_sap_is_suspend_supported");
    v13 = 0;
    return v13 & 1;
  }
  if ( *((_DWORD *)v12 - 1) != -1811715192 )
    __break(0x8228u);
  v13 = v12();
  return v13 & 1;
}
