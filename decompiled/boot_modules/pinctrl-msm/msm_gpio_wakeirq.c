__int64 __fastcall msm_gpio_wakeirq(__int64 a1, unsigned int a2, __int64 a3, _DWORD *a4, _DWORD *a5)
{
  __int64 data; // x0
  __int64 v9; // x9
  int v10; // w8
  __int64 v11; // x9
  int v12; // w10
  int v13; // w8
  __int64 v14; // x19
  __int64 v15; // x20
  unsigned int v16; // w0
  unsigned __int64 v17; // x8

  data = gpiochip_get_data(a1);
  *a4 = -1;
  *a5 = 1;
  v9 = *(_QWORD *)(data + 968);
  v10 = *(_DWORD *)(v9 + 88);
  if ( !v10 )
  {
LABEL_5:
    if ( *a4 == -1 )
      return 0;
    goto LABEL_8;
  }
  v11 = *(_QWORD *)(v9 + 80);
  v12 = 0;
  while ( *(_DWORD *)(v11 + 8LL * v12) != a2 )
  {
    if ( v10 == ++v12 )
      goto LABEL_5;
  }
  v13 = *(_DWORD *)(v11 + 8LL * v12 + 4);
  *a4 = v13;
  if ( v13 != -1 )
  {
LABEL_8:
    v14 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * a2;
    if ( (*(_WORD *)(v14 + 92) & 0x7C0) != 0 )
    {
      v15 = data + 976;
      v16 = readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v14 + 84) >> 5) & 3LL))
                                 + *(unsigned int *)(v14 + 68)));
      v17 = *(_QWORD *)(v14 + 92);
      if ( ((v16 >> ((v17 >> 6) & 0x1F)) & 1) != 0 )
        writel(
          v16 | (1 << (v17 >> 11)),
          (unsigned int *)(*(_QWORD *)(v15 + 8 * ((*(_QWORD *)(v14 + 84) >> 5) & 3LL)) + *(unsigned int *)(v14 + 68)));
    }
  }
  return 0;
}
