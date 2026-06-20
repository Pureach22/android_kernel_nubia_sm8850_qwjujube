__int64 __fastcall msm_vidc_check_scaling_supported(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  void *v5; // x8
  __int64 v6; // x4
  unsigned int v7; // w6
  unsigned int v8; // w5
  unsigned int v9; // w7
  int v10; // w9
  __int64 v11; // x2
  void *v12; // x0

  if ( *(_DWORD *)(result + 312) == 8 || *(_DWORD *)(result + 308) == 2 )
  {
    if ( result )
    {
      if ( (msm_vidc_debug & 2) == 0 )
        return 0;
      v5 = &unk_8F186;
LABEL_25:
      printk(v5, "high", result + 340, "msm_vidc_check_scaling_supported", a5);
      return 0;
    }
    return result;
  }
  if ( *(_DWORD *)(result + 1880) != *(_DWORD *)(result + 1896)
    || *(_DWORD *)(result + 1884) != *(_DWORD *)(result + 1900)
    || *(_DWORD *)(result + 1888) != *(_DWORD *)(result + 1904)
    || *(_DWORD *)(result + 1892) != *(_DWORD *)(result + 1908) )
  {
    v6 = *(unsigned int *)(result + 1888);
    v7 = *(_DWORD *)(result + 1904);
    v8 = *(_DWORD *)(result + 1892);
    v9 = *(_DWORD *)(result + 1908);
    if ( v7 > (unsigned int)v6 || v9 > v8 )
    {
      if ( !result || (msm_vidc_debug & 1) == 0 )
        return 4294967274LL;
      v11 = result + 340;
      v12 = &unk_89170;
    }
    else
    {
      v10 = *(_DWORD *)(result + 20144);
      if ( (unsigned int)v6 <= v7 * v10 && v8 <= v9 * v10 )
        return 0;
      if ( !result || (msm_vidc_debug & 1) == 0 )
        return 4294967274LL;
      v11 = result + 340;
      v12 = &unk_8E632;
    }
    printk(v12, "err ", v11, "msm_vidc_check_scaling_supported", v6);
    return 4294967274LL;
  }
  if ( result )
  {
    if ( (msm_vidc_debug & 2) == 0 )
      return 0;
    v5 = &unk_7FA49;
    goto LABEL_25;
  }
  return result;
}
