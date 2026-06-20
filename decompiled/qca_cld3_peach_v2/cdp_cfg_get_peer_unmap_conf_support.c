__int64 __fastcall cdp_cfg_get_peer_unmap_conf_support(
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

  if ( !*(_QWORD *)a1 )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: invalid instance",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "cdp_cfg_get_peer_unmap_conf_support");
LABEL_8:
    v11 = 0;
    return v11 & 1;
  }
  v9 = *(_QWORD *)(*(_QWORD *)a1 + 104LL);
  if ( !v9 )
    goto LABEL_8;
  v10 = *(__int64 (**)(void))(v9 + 96);
  if ( !v10 )
    goto LABEL_8;
  if ( *((_DWORD *)v10 - 1) != 799902358 )
    __break(0x8228u);
  v11 = v10();
  return v11 & 1;
}
