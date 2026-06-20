__int64 __fastcall wlan_is_vdev_level_dcs_supported(
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
  __int64 (*v10)(void); // x8
  char v11; // w0

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2128)) == 0 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_dcs_get_tx_ops");
    goto LABEL_8;
  }
  v10 = *(__int64 (**)(void))(v9 + 376);
  if ( !v10 )
  {
LABEL_8:
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: dcs_vdev_support tx_ops is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_is_vdev_level_dcs_supported");
    v11 = 0;
    return v11 & 1;
  }
  if ( *((_DWORD *)v10 - 1) != -1548408 )
    __break(0x8228u);
  v11 = v10();
  return v11 & 1;
}
