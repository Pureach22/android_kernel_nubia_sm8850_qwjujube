__int64 __fastcall msm_vidc_init_codec(__int64 a1, _DWORD *a2)
{
  int v2; // w5
  int v3; // w5
  __int64 result; // x0
  __int64 v5; // x8
  int v7; // w8
  void *v8; // x0

  v2 = *(_DWORD *)(a1 + 308);
  if ( (unsigned int)(v2 - 1) >= 2 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v8 = &unk_943CB;
      goto LABEL_25;
    }
    return 4294967274LL;
  }
  *a2 = v2;
  v3 = *(_DWORD *)(a1 + 312);
  if ( v3 <= 3 )
  {
    if ( v3 == 1 )
    {
      a2[3] = 16;
      if ( *(_QWORD *)(a1 + 11240) == 1 )
      {
        a2[2] = 1;
        a2[11] = 1;
        return 0;
      }
      else
      {
        result = 0;
        a2[2] = 0;
        a2[11] = 0;
      }
      return result;
    }
    if ( v3 != 2 )
      goto LABEL_20;
    v5 = 2;
LABEL_13:
    *((_QWORD *)a2 + 1) = v5 & 0xFFFF0000FFFFFFFFLL | 0x2000000000LL;
    return 0;
  }
  if ( v3 == 4 )
  {
    v5 = 3;
    goto LABEL_13;
  }
  if ( v3 != 16 )
  {
    if ( v3 == 64 )
    {
      *((_QWORD *)a2 + 1) = 0x1000000005LL;
      return 0;
    }
LABEL_20:
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v8 = &unk_7F71A;
LABEL_25:
      printk(v8, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_codec");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  result = 0;
  a2[2] = 4;
  if ( *(_QWORD *)(a1 + 34256) )
    v7 = 128;
  else
    v7 = 64;
  a2[3] = v7;
  return result;
}
