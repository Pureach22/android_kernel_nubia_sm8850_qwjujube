__int64 __fastcall hdcp1_app_load_0(__int64 a1)
{
  unsigned int app; // w0
  __int64 result; // x0
  void *v4; // x8
  void *v5; // x0
  unsigned int v6; // w19

  if ( (*(_BYTE *)(a1 + 72) & 1) != 0 )
    return 0;
  app = load_app((__int64)"hdcp1", (int **)a1, (__int64 (__fastcall **)(__int64, __int64, int **, __int64))(a1 + 16));
  if ( app )
  {
    v4 = &unk_CCC2;
LABEL_12:
    v6 = app;
    printk(v4);
    return v6;
  }
  if ( !*(_QWORD *)a1 )
  {
    v5 = &unk_CDFB;
LABEL_14:
    printk(v5);
    return 4294967274LL;
  }
  app = load_app(
          (__int64)"ops",
          (int **)(a1 + 32),
          (__int64 (__fastcall **)(__int64, __int64, int **, __int64))(a1 + 48));
  if ( app )
  {
    v4 = &unk_CCDE;
    goto LABEL_12;
  }
  if ( !*(_QWORD *)(a1 + 32) )
  {
    v5 = &unk_BEA3;
    goto LABEL_14;
  }
  result = 0;
  *(_DWORD *)(a1 + 72) |= 1u;
  return result;
}
