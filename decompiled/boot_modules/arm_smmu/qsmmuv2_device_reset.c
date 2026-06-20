__int64 __fastcall qsmmuv2_device_reset(__int64 *a1)
{
  __int64 (**v1)(void); // x8
  __int64 v2; // x22
  __int64 (*v4)(void); // x8
  int v5; // w0
  __int64 v6; // x8
  _DWORD *v7; // x8
  __int64 v8; // x20
  unsigned int *v9; // x21
  char v10; // w0
  __int64 v11; // x23
  unsigned __int64 v12; // x20
  unsigned int *v13; // x21
  __int64 v14; // x8
  __int64 v15; // x2
  __int64 v16; // x3
  _DWORD *v17; // x8
  _DWORD **v18; // x8
  _DWORD *v19; // x8
  int v20; // w0
  __int64 v21; // x8
  _DWORD *v22; // x8

  v1 = (__int64 (**)(void))a1[6];
  v2 = *(a1 - 2);
  if ( v1 && (v4 = *v1) != nullptr )
  {
    if ( *((_DWORD *)v4 - 1) != 616069899 )
      __break(0x8228u);
    v5 = v4();
    v6 = a1[6];
    if ( !v6 )
      goto LABEL_5;
  }
  else
  {
    v5 = readl_relaxed_1((unsigned int *)(a1[1] + (6 << *((_DWORD *)a1 + 7))));
    v6 = a1[6];
    if ( !v6 )
    {
LABEL_5:
      writel_relaxed_1(v5 | 4, (unsigned int *)(a1[1] + (6 << *((_DWORD *)a1 + 7))));
      goto LABEL_6;
    }
  }
  v7 = *(_DWORD **)(v6 + 8);
  if ( !v7 )
    goto LABEL_5;
  if ( *(v7 - 1) != -1008624849 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64 *, __int64, _QWORD, _QWORD))v7)(a1, 6, 0, v5 | 4u);
LABEL_6:
  v8 = *a1;
  v9 = (unsigned int *)(a1[1] + (6 << *((_DWORD *)a1 + 7)));
  v10 = readl_0(v9);
  if ( (v10 & 8) != 0 )
  {
LABEL_10:
    if ( (v10 & 8) == 0 )
      goto LABEL_22;
LABEL_11:
    if ( !*((_DWORD *)a1 - 2) )
      goto LABEL_23;
    goto LABEL_12;
  }
  v11 = 30000001;
  while ( --v11 >= 0 )
  {
    __yield();
    v10 = readl_0(v9);
    if ( (v10 & 8) != 0 )
      goto LABEL_10;
  }
  if ( (readl_0(v9) & 8) != 0 )
    goto LABEL_11;
LABEL_22:
  dev_err(v8, "Couldn't halt SMMU!\n");
  if ( !*((_DWORD *)a1 - 2) )
    goto LABEL_23;
LABEL_12:
  v12 = 0;
  v13 = (unsigned int *)(v2 + 4);
  do
  {
    v14 = a1[6];
    v15 = (int)*(v13 - 1);
    v16 = *v13;
    if ( v14 && (v17 = *(_DWORD **)(v14 + 8)) != nullptr )
    {
      if ( *(v17 - 1) != -1008624849 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 *, _QWORD, __int64, __int64))v17)(a1, 0, v15, v16);
    }
    else
    {
      writel_relaxed_1(v16, (unsigned int *)(a1[1] + v15));
    }
    ++v12;
    v13 += 2;
  }
  while ( v12 < *((unsigned int *)a1 - 2) );
LABEL_23:
  v18 = (_DWORD **)a1[6];
  if ( v18 && (v19 = *v18) != nullptr )
  {
    if ( *(v19 - 1) != 616069899 )
      __break(0x8228u);
    v20 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD))v19)(a1, 6, 0);
    v21 = a1[6];
    if ( !v21 )
      goto LABEL_27;
  }
  else
  {
    v20 = readl_relaxed_1((unsigned int *)(a1[1] + (6 << *((_DWORD *)a1 + 7))));
    v21 = a1[6];
    if ( !v21 )
    {
LABEL_27:
      writel_relaxed_1(v20 & 0xFFFFFFFB, (unsigned int *)(a1[1] + (6 << *((_DWORD *)a1 + 7))));
      return 0;
    }
  }
  v22 = *(_DWORD **)(v21 + 8);
  if ( !v22 )
    goto LABEL_27;
  if ( *(v22 - 1) != -1008624849 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64 *, __int64, _QWORD, _QWORD))v22)(a1, 6, 0, v20 & 0xFFFFFFFB);
  return 0;
}
