__int64 __fastcall glink_probe_ssr_cb(__int64 a1, __int64 a2)
{
  __int64 *v4; // x8
  __int64 v5; // x1
  void (__fastcall *v6)(__int64, __int64); // x8
  __int64 v7; // x0
  __int64 *v8; // x8

  ipc_log_string(glink_ilc, "received %ld for %s\n", a2, *(const char **)(a1 - 40));
  if ( a2 == 3 )
  {
    v8 = *(__int64 **)(a1 - 56);
    v5 = v8[14];
    if ( !v5 )
      v5 = *v8;
    v6 = *(void (__fastcall **)(__int64, __int64))(a1 - 8);
    v7 = a1 - 72;
    if ( *((_DWORD *)v6 - 1) != 1468676041 )
      __break(0x8228u);
    goto LABEL_12;
  }
  if ( a2 == 1 )
  {
    v4 = *(__int64 **)(a1 - 56);
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    v6 = *(void (__fastcall **)(__int64, __int64))(a1 - 16);
    v7 = a1 - 72;
    if ( *((_DWORD *)v6 - 1) != -1265715374 )
      __break(0x8228u);
LABEL_12:
    v6(v7, v5);
  }
  return 0;
}
