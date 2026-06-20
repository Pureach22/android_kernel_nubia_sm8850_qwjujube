__int64 __fastcall hdd_set_netdev_flags(
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
  int v10; // w19
  __int64 v11; // x22
  __int64 **context; // x0
  __int64 **v13; // x21
  __int64 v14; // x8
  __int64 (*v15)(void); // x8
  int v16; // w0
  const char *v17; // x2
  _BOOL4 v19; // w23
  __int64 v20; // x8
  __int64 (__fastcall *v21)(__int64 **, __int64); // x8
  int v22; // w0
  __int64 v23; // x8
  unsigned int (__fastcall *v24)(__int64 **, __int64); // x8
  __int64 **v25; // x0
  __int64 v26; // x1
  __int64 v27; // x8
  __int64 (__fastcall *v28)(__int64 **, __int64); // x8
  __int64 v29; // x8
  bool v30; // w24
  __int64 *v31; // x8
  __int64 v32; // x8
  unsigned int (__fastcall *v33)(__int64 **, __int64); // x8
  char v34; // w8
  __int64 v35; // x8
  unsigned int (__fastcall *v36)(__int64 **, __int64); // x8

  if ( !a1 || !*(_QWORD *)(a1 + 32) )
  {
    v17 = "%s: invalid input!";
    return qdf_trace_msg(0x33u, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_set_netdev_flags");
  }
  v10 = *(_DWORD *)(a1 + 40);
  v11 = *(_QWORD *)(a1 + 24);
  context = (__int64 **)_cds_get_context(71, (__int64)"hdd_set_netdev_flags", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context || !v11 )
  {
    v17 = "%s: invalid SOC or HDD context!";
    return qdf_trace_msg(0x33u, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_set_netdev_flags");
  }
  v13 = context;
  if ( !*context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_cfg_get");
LABEL_15:
    v16 = 0;
    goto LABEL_16;
  }
  v14 = **context;
  if ( !v14 )
  {
    v19 = 0;
    goto LABEL_32;
  }
  v15 = *(__int64 (**)(void))(v14 + 264);
  if ( !v15 )
    goto LABEL_15;
  if ( *((_DWORD *)v15 - 1) != -1095293032 )
    __break(0x8228u);
  v16 = v15();
LABEL_16:
  v19 = v16 != 0;
  if ( !*v13 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_cfg_get");
    goto LABEL_32;
  }
  v20 = **v13;
  if ( !v20 || (v21 = *(__int64 (__fastcall **)(__int64 **, __int64))(v20 + 264)) == nullptr )
  {
LABEL_32:
    v22 = 0;
    if ( v10 > 6 )
      goto LABEL_22;
LABEL_33:
    if ( v10 != 1 )
    {
      if ( v10 == 2 )
        goto LABEL_44;
      if ( v10 != 3 )
        goto LABEL_53;
      if ( !*v13 )
      {
        qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_cfg_get");
        goto LABEL_72;
      }
      v27 = **v13;
      if ( !v27 )
        goto LABEL_82;
      v28 = *(__int64 (__fastcall **)(__int64 **, __int64))(v27 + 264);
      if ( !v28 )
        goto LABEL_72;
      if ( *((_DWORD *)v28 - 1) != -1095293032 )
        __break(0x8228u);
      v22 = v28(v13, 1);
    }
    if ( !v22 )
      goto LABEL_72;
    goto LABEL_60;
  }
  if ( *((_DWORD *)v21 - 1) != -1095293032 )
    __break(0x8228u);
  v22 = v21(v13, 3);
  if ( v10 <= 6 )
    goto LABEL_33;
LABEL_22:
  if ( v10 != 16 && v10 != 11 )
  {
    if ( v10 != 7 )
    {
LABEL_53:
      v30 = v22 == 0;
      if ( !v19 )
        goto LABEL_57;
      goto LABEL_56;
    }
LABEL_44:
    if ( *v13 )
    {
      v29 = **v13;
      if ( v29 )
      {
        v24 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v29 + 264);
        if ( v24 )
        {
          v25 = v13;
          v26 = 1;
LABEL_48:
          if ( *((_DWORD *)v24 - 1) != -1095293032 )
            __break(0x8228u);
          v30 = v24(v25, v26) == 0;
          if ( !v19 )
            goto LABEL_57;
          goto LABEL_56;
        }
      }
      goto LABEL_52;
    }
    goto LABEL_55;
  }
  if ( *v13 )
  {
    v23 = **v13;
    if ( v23 )
    {
      v24 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v23 + 264);
      if ( v24 )
      {
        v25 = v13;
        v26 = 2;
        goto LABEL_48;
      }
    }
LABEL_52:
    v22 = 0;
    goto LABEL_53;
  }
LABEL_55:
  qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_cfg_get");
  v30 = 1;
  if ( !v19 )
    goto LABEL_61;
LABEL_56:
  if ( !*(_DWORD *)(v11 + 3280) )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 32) + 184LL) |= 0x8000uLL;
    if ( v30 )
      goto LABEL_72;
    goto LABEL_60;
  }
LABEL_57:
  if ( !v30 )
  {
LABEL_60:
    v30 = 0;
    *(_QWORD *)(*(_QWORD *)(a1 + 32) + 184LL) |= 0x12uLL;
LABEL_61:
    v31 = *v13;
    if ( !*v13 )
    {
LABEL_73:
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_cfg_get");
LABEL_74:
      if ( *v13 )
      {
        v35 = **v13;
        if ( v35 )
        {
          v36 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v35 + 264);
          if ( v36 )
          {
            if ( *((_DWORD *)v36 - 1) != -1095293032 )
              __break(0x8228u);
            if ( v36(v13, 10) )
              *(_QWORD *)(*(_QWORD *)(a1 + 32) + 184LL) |= 1uLL;
          }
        }
      }
      else
      {
        qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_cfg_get");
      }
      goto LABEL_82;
    }
    goto LABEL_62;
  }
LABEL_72:
  v30 = 1;
  v31 = *v13;
  if ( !*v13 )
    goto LABEL_73;
LABEL_62:
  v32 = *v31;
  if ( v32 )
  {
    v33 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v32 + 264);
    if ( v33 )
    {
      if ( *((_DWORD *)v33 - 1) != -1095293032 )
        __break(0x8228u);
      if ( v33(v13, 5) )
        v34 = v30;
      else
        v34 = 1;
      if ( (v34 & 1) == 0 )
      {
        *(_QWORD *)(*(_QWORD *)(a1 + 32) + 184LL) |= 0x110001uLL;
        *(_BYTE *)(a1 + 52466) = 1;
      }
    }
    goto LABEL_74;
  }
LABEL_82:
  *(_QWORD *)(*(_QWORD *)(a1 + 32) + 184LL) |= 0x10000000000uLL;
  return qdf_trace_msg(
           0x33u,
           8u,
           "%s: adapter mode %u dev feature 0x%llx",
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           "hdd_set_netdev_flags",
           (unsigned int)v10,
           *(_QWORD *)(*(_QWORD *)(a1 + 32) + 184LL));
}
