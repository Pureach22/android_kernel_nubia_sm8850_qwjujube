__int64 __fastcall cam_compat_util_get_irq(_QWORD *a1)
{
  __int64 v3; // x20
  int string_helper; // w0
  unsigned int irq; // w0
  int v6; // w21
  int v7; // w0
  unsigned int v8; // w0
  int v9; // w7
  unsigned int v11; // w19
  int v12; // w6
  __int64 v13; // x0

  if ( !*((_DWORD *)a1 + 26) )
    return 0;
  v3 = *(_QWORD *)(a1[1] + 744LL);
  string_helper = of_property_read_string_helper(v3, "interrupt-names", a1 + 5, 1, 0);
  if ( string_helper < 0 )
  {
    v9 = string_helper;
    v6 = 0;
    goto LABEL_12;
  }
  irq = platform_get_irq(*a1, 0);
  *((_DWORD *)a1 + 20) = irq;
  if ( (irq & 0x80000000) != 0 )
  {
    v11 = irq;
    v12 = 0;
LABEL_14:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_compat_util_get_irq",
      883,
      "Failed to get irq resource at i = %d rc = %d",
      v12,
      v11);
    return v11;
  }
  if ( *((_DWORD *)a1 + 26) < 2u )
    return 0;
  v6 = 1;
  v7 = of_property_read_string_helper(v3, "interrupt-names", a1 + 6, 1, 1);
  if ( v7 < 0 )
  {
LABEL_9:
    v9 = v7;
LABEL_12:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_compat_util_get_irq",
      875,
      "Failed to get irq names at i = %d rc = %d",
      v6,
      v9);
    return 4294967274LL;
  }
  v8 = platform_get_irq(*a1, 1);
  *((_DWORD *)a1 + 21) = v8;
  if ( (v8 & 0x80000000) != 0 )
  {
    v11 = v8;
    v12 = 1;
    goto LABEL_14;
  }
  if ( *((_DWORD *)a1 + 26) < 3u )
    return 0;
  v6 = 2;
  v7 = of_property_read_string_helper(v3, "interrupt-names", a1 + 7, 1, 2);
  if ( v7 < 0 )
    goto LABEL_9;
  v13 = platform_get_irq(*a1, 2);
  __break(0x5512u);
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cam_secure_get_vfe_fd_port_config(v13);
}
