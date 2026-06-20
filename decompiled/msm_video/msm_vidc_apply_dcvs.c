__int64 __fastcall msm_vidc_apply_dcvs(__int64 a1)
{
  int v1; // w20
  unsigned int v3; // w1
  __int64 v4; // x3
  int v6; // w20

  if ( *(_BYTE *)(a1 + 1932) != 1 )
    return 0;
  v1 = 1;
  if ( *(_DWORD *)(a1 + 308) == 2 )
    v3 = 2;
  else
    v3 = 1;
  v4 = (unsigned int)msm_vidc_num_buffers(a1, v3, 8) + 1;
  if ( (unsigned int)v4 < *(_DWORD *)(a1 + 1928) )
  {
    if ( (unsigned int)v4 >= *(_DWORD *)(a1 + 1920) )
    {
      if ( *(_DWORD *)(a1 + 308) == 1
        || (v6 = *(_DWORD *)(a1 + 1992), (v6 & 2) != 0) && (unsigned int)v4 >= *(_DWORD *)(a1 + 1924)
        || (v6 & 1) != 0 && (unsigned int)v4 <= *(_DWORD *)(a1 + 1924) )
      {
        *(_DWORD *)(a1 + 1992) = 0;
      }
      goto LABEL_9;
    }
    v1 = 2;
  }
  *(_DWORD *)(a1 + 1992) = v1;
LABEL_9:
  if ( a1 && (msm_vidc_debug & 8) != 0 )
    printk(&unk_8F223, "perf", a1 + 340, v4, *(unsigned int *)(a1 + 1920));
  return 0;
}
