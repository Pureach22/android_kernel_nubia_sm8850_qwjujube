bool __fastcall msm_vidc_allow_image_encode_session(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x3
  unsigned int v6; // w8
  __int64 v7; // x8
  __int64 v8; // x19
  _BOOL4 v9; // w19
  void *v11; // x8
  void *v12; // x8
  __int64 v13; // [xsp+28h] [xbp+18h]

  if ( *(_DWORD *)(a1 + 312) != 8 || *(_DWORD *)(a1 + 308) != 1 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 0;
    v11 = &unk_8CD3D;
    goto LABEL_29;
  }
  v5 = *(unsigned int *)(a1 + 392);
  if ( (unsigned int)v5 < *(_DWORD *)(a1 + 17096)
    || (unsigned int)v5 > *(_DWORD *)(a1 + 17104)
    || (v6 = *(_DWORD *)(a1 + 396), v6 < *(_DWORD *)(a1 + 17600))
    || v6 > *(_DWORD *)(a1 + 17608) )
  {
    if ( !a1 )
      return 0;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_23;
    v8 = a1;
    printk(&unk_957D8, "err ", a1 + 340, v5, *(unsigned int *)(a1 + 396));
    goto LABEL_41;
  }
  a5 = *(unsigned int *)(a1 + 18128);
  if ( ((unsigned int)a5 > 0x10 || ((1 << a5) & 0x10014) == 0) && (_DWORD)a5 != 256 )
  {
    if ( !a1 )
      return 0;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_23;
    v8 = a1;
    printk(&unk_94AAA, "err ", a1 + 340, "msm_vidc_allow_image_encode_session", a5);
    goto LABEL_41;
  }
  a5 = *(unsigned int *)(a1 + 600);
  v7 = *(_QWORD *)(a1 + 26528);
  if ( v7 != a5 || v7 != *(_DWORD *)(a1 + 604) )
  {
    if ( !a1 )
      return 0;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_23;
    v8 = a1;
    printk(&unk_90BDD, "err ", a1 + 340, "msm_vidc_allow_image_encode_session", a5);
    goto LABEL_41;
  }
  a5 = *(_QWORD *)(a1 + 24344);
  if ( a5 != 2 )
  {
    if ( !a1 )
      return 0;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_23;
    v12 = &unk_93D40;
LABEL_36:
    v8 = a1;
    printk(v12, "err ", a1 + 340, "msm_vidc_allow_image_encode_session", a5);
LABEL_41:
    a1 = v8;
LABEL_23:
    v9 = 0;
    goto LABEL_24;
  }
  a5 = *(_QWORD *)(a1 + 15776);
  if ( *(_QWORD *)(a1 + 15944) | a5 )
  {
    if ( !a1 )
      return 0;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_23;
    v8 = a1;
    printk(&unk_885EF, "err ", a1 + 340, "msm_vidc_allow_image_encode_session", a5);
    goto LABEL_41;
  }
  a5 = *(_QWORD *)(a1 + 10568);
  if ( a5 )
  {
    if ( !a1 )
      return 0;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_23;
    v12 = &unk_85C1B;
    goto LABEL_36;
  }
  a5 = *(_QWORD *)(a1 + 24680);
  v9 = a5 == 0;
  if ( a1 && a5 && (msm_vidc_debug & 1) != 0 )
  {
    v13 = a1;
    printk(&unk_8C1A5, "err ", a1 + 340, "msm_vidc_allow_image_encode_session", a5);
    a1 = v13;
  }
LABEL_24:
  if ( a1 && !v9 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v11 = &unk_7FAB5;
LABEL_29:
      printk(v11, "err ", a1 + 340, "msm_vidc_allow_image_encode_session", a5);
    }
    return 0;
  }
  return v9;
}
