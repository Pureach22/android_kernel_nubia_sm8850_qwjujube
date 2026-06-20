__int64 __fastcall msm_venc_s_selection(_DWORD *a1, unsigned int *a2)
{
  __int64 v2; // x4
  __int64 v3; // x4
  unsigned int v4; // w5
  __int64 v5; // x4
  unsigned int v6; // w5
  unsigned int v7; // w8
  unsigned int *v8; // x19
  unsigned int v9; // w9
  unsigned int v10; // w10
  unsigned int v11; // w11
  void *v12; // x8
  __int64 v13; // x4
  unsigned int v14; // w5
  __int64 v15; // x4
  unsigned int v16; // w5
  __int64 v17; // x4
  unsigned int v18; // w5
  __int64 v19; // x4
  unsigned int v20; // w5
  unsigned int v21; // w9
  __int64 v22; // x4
  unsigned int v23; // w10
  unsigned int v24; // w11
  unsigned int v25; // w12
  _BOOL4 v26; // w8
  __int64 result; // x0
  _DWORD *v28; // x20
  _DWORD *v29; // x19
  unsigned int *v30; // x20
  _DWORD *v31; // x20
  _DWORD *v32; // x19
  unsigned int *v33; // x20
  _DWORD *v34; // x19
  unsigned int *v35; // x20
  _DWORD *v36; // x19
  unsigned int *v37; // x20
  _DWORD *v38; // x19
  unsigned int *v39; // x20
  _DWORD *v40; // x19
  unsigned int *v41; // x20
  _DWORD *v42; // x19
  unsigned int *v43; // x20

  v2 = *a2;
  if ( ((unsigned int)v2 | 8) != 0xA )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v12 = &unk_9531A;
    goto LABEL_61;
  }
  v2 = a2[1];
  if ( (_DWORD)v2 == 256 )
  {
    v13 = a2[3];
    v14 = a1[470];
    if ( (unsigned int)v13 < v14 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v36 = a1;
        v37 = a2;
        printk(&unk_8FCB0, "err ", a1 + 85, "msm_venc_s_selection", v13);
        v14 = v36[470];
        a2 = v37;
        a1 = v36;
      }
      a2[3] = v14;
    }
    v15 = a2[4];
    v16 = a1[471];
    if ( (unsigned int)v15 < v16 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v38 = a1;
        v39 = a2;
        printk(&unk_938EF, "err ", a1 + 85, "msm_venc_s_selection", v15);
        v16 = v38[471];
        a2 = v39;
        a1 = v38;
      }
      a2[4] = v16;
    }
    v17 = a2[5];
    v18 = a1[472];
    if ( (unsigned int)v17 > v18 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v40 = a1;
        v41 = a2;
        printk(&unk_8EE55, "err ", a1 + 85, "msm_venc_s_selection", v17);
        v18 = v40[472];
        a2 = v41;
        a1 = v40;
      }
      a2[5] = v18;
    }
    v19 = a2[6];
    v20 = a1[473];
    if ( (unsigned int)v19 > v20 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v42 = a1;
        v43 = a2;
        printk(&unk_8729E, "err ", a1 + 85, "msm_venc_s_selection", v19);
        v20 = v42[473];
        a2 = v43;
        a1 = v42;
      }
      a2[6] = v20;
    }
    v21 = a2[3];
    v22 = (unsigned int)a1[470];
    a1[474] = v21;
    v23 = a2[4];
    a1[475] = v23;
    v24 = a2[5];
    a1[476] = v24;
    v25 = a2[6];
    a1[477] = v25;
    if ( __PAIR64__(a1[471], v22) == __PAIR64__(v23, v21) && a1[472] == v24 )
    {
      v8 = a2;
      v26 = a1[473] != v25;
    }
    else
    {
      v8 = a2;
      v26 = 1;
    }
    if ( a1 && v26 && (msm_vidc_debug & 2) != 0 )
    {
      v31 = a1;
      printk(&unk_96C32, "high", a1 + 85, "msm_venc_s_selection", v22);
      a1 = v31;
    }
    goto LABEL_54;
  }
  if ( (_DWORD)v2 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v12 = &unk_8B32F;
LABEL_61:
    printk(v12, "err ", a1 + 85, "msm_venc_s_selection", v2);
    return 4294967274LL;
  }
  if ( *(_QWORD *)(a2 + 3) )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v29 = a1;
      v30 = a2;
      printk(&unk_921A0, "high", a1 + 85, "msm_venc_s_selection", a2[3]);
      a2 = v30;
      a1 = v29;
    }
    *(_QWORD *)(a2 + 3) = 0;
  }
  v3 = a2[5];
  v4 = a1[98];
  if ( (unsigned int)v3 > v4 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v32 = a1;
      v33 = a2;
      printk(&unk_95379, "high", a1 + 85, "msm_venc_s_selection", v3);
      v4 = v32[98];
      a2 = v33;
      a1 = v32;
    }
    a2[5] = v4;
  }
  v5 = a2[6];
  v6 = a1[99];
  if ( (unsigned int)v5 > v6 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v34 = a1;
      v35 = a2;
      printk(&unk_7F7CA, "high", a1 + 85, "msm_venc_s_selection", v5);
      v6 = v34[99];
      a2 = v35;
      a1 = v34;
    }
    a2[6] = v6;
  }
  v7 = a2[3];
  v8 = a2;
  a1[470] = v7;
  v9 = a2[4];
  a1[471] = v9;
  v10 = a2[5];
  a1[472] = v10;
  v11 = a2[6];
  a1[474] = v7;
  a1[475] = v9;
  a1[476] = v10;
  a1[473] = v11;
  a1[477] = v11;
LABEL_54:
  v28 = a1;
  result = msm_venc_s_fmt_output((__int64)a1, (__int64)(a1 + 148));
  if ( !(_DWORD)result )
  {
    if ( v28 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_83439, "high", v28 + 85, "msm_venc_s_selection", v8[1]);
    }
    return 0;
  }
  return result;
}
