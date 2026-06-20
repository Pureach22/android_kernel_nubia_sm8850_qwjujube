__int64 __fastcall msm_vidc_decide_scaling_iris4(__int64 a1)
{
  unsigned int v2; // w21
  int v3; // w8
  int v4; // w9
  unsigned int v6; // w8
  unsigned int v7; // w20
  __int64 v8; // x4
  unsigned int v9; // w8
  __int64 v10; // x10
  int v11; // w11
  void *v12; // x0
  __int64 v13; // x2
  __int64 v14; // x4
  void *v15; // x0
  void *v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2

  if ( !*(_QWORD *)(a1 + 20312) || !*(_DWORD *)(a1 + 38716) )
    return 0;
  if ( *(__int64 *)(a1 + 20128) < 2 )
  {
    v2 = 0;
    goto LABEL_5;
  }
  v6 = *(_DWORD *)(a1 + 312);
  if ( v6 > 0x10 )
  {
    v2 = 0;
    goto LABEL_5;
  }
  v2 = 0;
  if ( ((1 << v6) & 0x10006) == 0 )
    goto LABEL_5;
  v2 = *(_DWORD *)(a1 + 392);
  v7 = *(_DWORD *)(a1 + 396);
  if ( ((v2 | v7) & 1) != 0 )
  {
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      goto LABEL_5;
    v12 = &unk_86431;
    v13 = a1 + 340;
    v14 = v2;
LABEL_29:
    printk(v12, "high", v13, "msm_vidc_decide_scaling_iris4", v14);
    goto LABEL_5;
  }
  if ( *(_DWORD *)(a1 + 1884) || *(_DWORD *)(a1 + 1880) || *(_DWORD *)(a1 + 1888) != v2 || *(_DWORD *)(a1 + 1892) != v7 )
  {
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      goto LABEL_5;
    v8 = *(unsigned int *)(a1 + 1888);
    v15 = &unk_8BE08;
LABEL_33:
    printk(v15, "high", a1 + 340, "msm_vidc_decide_scaling_iris4", v8);
    goto LABEL_5;
  }
  v8 = *(unsigned int *)(a1 + 1904);
  if ( (unsigned int)v8 >= v2 || (v9 = *(_DWORD *)(a1 + 1908), v9 >= v7) )
  {
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      goto LABEL_5;
    v15 = &unk_8D42E;
    goto LABEL_33;
  }
  v10 = *(_QWORD *)(a1 + 15608);
  if ( v10
    || *(_QWORD *)(a1 + 34088)
    || *(_QWORD *)(a1 + 31400) == 1
    || (v11 = *(_DWORD *)(a1 + 18128), (unsigned int)(v11 - 2) <= 0x3E)
    && ((1LL << ((unsigned __int8)v11 - 2)) & 0x4000000000004005LL) != 0
    || v11 == 256 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_88CFB, "high", a1 + 340, "msm_vidc_decide_scaling_iris4", v10 != 0);
    goto LABEL_5;
  }
  if ( v2 == 7680 && v7 == 4320 )
  {
    if ( (unsigned int)v8 > v9 )
    {
      v17 = 16;
      v18 = 9;
      goto LABEL_56;
    }
    goto LABEL_60;
  }
  if ( v2 == 4320 && v7 == 7680 )
  {
    if ( (unsigned int)v8 < v9 )
    {
      v17 = 9;
      v18 = 16;
      goto LABEL_56;
    }
LABEL_60:
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      goto LABEL_5;
    v12 = &unk_8B1A2;
    v13 = a1 + 340;
    v14 = 0;
    goto LABEL_29;
  }
  if ( v2 == 0x2000 && v7 == 4320 )
  {
    if ( (unsigned int)v8 <= v9 )
      goto LABEL_60;
    v17 = 19;
    v18 = 10;
  }
  else
  {
    if ( v2 != 4320 || v7 != 0x2000 || (unsigned int)v8 >= v9 )
      goto LABEL_60;
    v17 = 10;
    v18 = 19;
  }
LABEL_56:
  if ( (unsigned int)msm_vidc_update_scaling_iris4(a1, v17, v18) )
  {
LABEL_5:
    v3 = *(_DWORD *)(a1 + 1888);
    v4 = *(_DWORD *)(a1 + 1892);
    *(_QWORD *)(a1 + 1896) = 0;
    *(_DWORD *)(a1 + 1904) = v3;
    *(_DWORD *)(a1 + 1908) = v4;
    ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      95,
      0,
      "msm_vidc_decide_scaling_iris4");
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      return 0;
    v16 = &unk_86459;
LABEL_36:
    printk(v16, "high", a1 + 340, "msm_vidc_decide_scaling_iris4", v2);
    return 0;
  }
  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    v16 = &unk_84B2D;
    goto LABEL_36;
  }
  return 0;
}
