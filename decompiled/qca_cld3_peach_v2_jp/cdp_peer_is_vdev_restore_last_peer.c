__int64 __fastcall cdp_peer_is_vdev_restore_last_peer(
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

  if ( !*(_QWORD *)a1 || (v9 = *(_QWORD *)(*(_QWORD *)a1 + 72LL)) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "cdp_peer_is_vdev_restore_last_peer");
    goto LABEL_8;
  }
  v10 = *(__int64 (**)(void))(v9 + 136);
  if ( !v10 )
  {
LABEL_8:
    v11 = 0;
    return v11 & 1;
  }
  if ( *((_DWORD *)v10 - 1) != 454466150 )
    __break(0x8228u);
  v11 = v10();
  return v11 & 1;
}
