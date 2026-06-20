size_t __fastcall sde_cesta_poll_handshake(size_t result)
{
  int *v1; // x19
  __int64 v2; // x21
  __int64 v3; // x0
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  __int64 v5; // x1
  __int64 v6; // x20
  __int64 v7; // x0
  int v8; // w21
  __int64 v9; // x0
  __int64 v10; // x6
  char v11; // [xsp+0h] [xbp+0h]

  if ( !result )
    return printk(&unk_25C1E1, "sde_cesta_poll_handshake");
  v1 = (int *)result;
  if ( *(_DWORD *)(result + 4) )
    return printk(&unk_25C1E1, "sde_cesta_poll_handshake");
  v2 = cesta_list_0;
  if ( *(_QWORD *)(cesta_list_0 + 864) )
  {
    v3 = ktime_get(result);
    v4 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 864);
    v5 = (unsigned int)v1[2];
    v6 = v3;
    if ( *((_DWORD *)v4 - 1) != 1440333326 )
      __break(0x8228u);
    v7 = v4(v2, v5);
    v8 = v7;
    v9 = ktime_get(v7);
    if ( v8 )
      LODWORD(v10) = 60333;
    else
      v10 = (v9 - v6) / 1000;
    return sde_evtlog_log(sde_dbg_base_evtlog, "sde_cesta_poll_handshake", 631, -1, *v1, v1[2], v10, -1059143953, v11);
  }
  return result;
}
