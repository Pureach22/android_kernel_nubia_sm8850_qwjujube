__int64 __fastcall msm_vidc_input_min_count(__int64 a1)
{
  __int64 v1; // x4
  int v2; // w8
  unsigned int v3; // w8
  int v5; // w9

  v1 = *(unsigned int *)(a1 + 308);
  if ( (_DWORD)v1 == 2 )
    goto LABEL_5;
  if ( (_DWORD)v1 == 1 )
  {
    v2 = *(_DWORD *)(a1 + 312);
    if ( (unsigned int)(v2 - 1) > 1 || *(_QWORD *)(a1 + 27704) )
      goto LABEL_5;
    v5 = *(_DWORD *)(a1 + 15272);
    if ( v2 == 1 )
    {
      v3 = 4;
      if ( !*(_QWORD *)(a1 + 27872) || !v5 )
      {
LABEL_6:
        if ( *(_QWORD *)(a1 + 32576) || *(_DWORD *)(a1 + 312) == 8 )
          return 1;
        return v3;
      }
    }
    else if ( !v5 )
    {
LABEL_5:
      v3 = 4;
      goto LABEL_6;
    }
    v3 = (1 << v5) + 2;
    goto LABEL_6;
  }
  if ( !a1 || (msm_vidc_debug & 1) == 0 )
    return 0;
  printk(&unk_87097, "err ", a1 + 340, "msm_vidc_input_min_count", v1);
  return 0;
}
