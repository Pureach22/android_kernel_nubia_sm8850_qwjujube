__int64 __fastcall msm_msi_snps_handler(__int64 a1)
{
  _QWORD *v1; // x22
  void (__fastcall *v3)(_QWORD); // x8
  void (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  __int64 v6; // x23
  int v7; // w0
  unsigned int v8; // w20
  int v9; // w21
  unsigned int v10; // w20
  __int64 v11; // x0
  unsigned __int64 v12; // x21
  unsigned int *v13; // x23
  bool v14; // cc
  __int64 (__fastcall *v15)(_QWORD); // x8

  v1 = *(_QWORD **)(a1 + 72);
  if ( !v1[9] )
  {
    v3 = (void (__fastcall *)(_QWORD))v1[7];
    if ( v3 )
      goto LABEL_6;
    v4 = (void (__fastcall *)(_QWORD))v1[6];
    v5 = a1 + 48;
    if ( *((_DWORD *)v4 - 1) != 270158662 )
      __break(0x8228u);
    v4(v5);
    v3 = (void (__fastcall *)(_QWORD))v1[5];
    if ( v3 )
    {
LABEL_6:
      if ( *((_DWORD *)v3 - 1) != 270158662 )
        __break(0x8228u);
      v3(a1 + 48);
    }
  }
  v6 = *(_QWORD *)(a1 + 8);
  v7 = readl_relaxed(*(_QWORD *)(v6 + 16));
  v8 = *(_DWORD *)(v6 + 24);
  v9 = v7;
  writel_relaxed(v8, *(unsigned int **)(v6 + 8));
  v10 = v9 & ~v8;
  v11 = writel_relaxed(v10, *(unsigned int **)(v6 + 16));
  if ( v10 )
  {
    v12 = 0;
    v13 = (unsigned int *)(v6 + 56);
    do
    {
      if ( (v10 & 1) != 0 )
      {
        if ( v12 >= 0x20 )
        {
          __break(0x5512u);
          return readl_relaxed(v11);
        }
        v11 = generic_handle_irq(*v13);
      }
      v14 = v10 > 1;
      ++v12;
      v13 += 8;
      v10 >>= 1;
    }
    while ( v14 );
  }
  v15 = (__int64 (__fastcall *)(_QWORD))v1[9];
  if ( !v15 )
    v15 = (__int64 (__fastcall *)(_QWORD))v1[8];
  if ( *((_DWORD *)v15 - 1) != 270158662 )
    __break(0x8228u);
  return v15(a1 + 48);
}
