__int64 __fastcall msm_vidc_read_efuse(_QWORD *a1)
{
  __int64 v1; // x21
  __int64 v2; // x8
  __int64 v3; // x23
  _DWORD *v5; // x22
  unsigned int v6; // w0
  unsigned int v7; // w20

  v1 = a1[489];
  v2 = *(_QWORD *)(v1 + 312);
  if ( !v2 )
    return 0;
  v3 = *(unsigned int *)(v1 + 320);
  if ( (_DWORD)v3 )
  {
    v5 = (_DWORD *)(v2 + 8);
    do
    {
      if ( !v5[2] )
      {
        if ( !devm_ioremap(*a1 + 16LL, (unsigned int)*(v5 - 2), (unsigned int)*(v5 - 1)) )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_8DFAD, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)*(v5 - 2));
          return 4294967274LL;
        }
        v6 = readl_relaxed();
        v7 = (*v5 & v6) >> v5[1];
        if ( v7 )
        {
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_95078, "high", 0xFFFFFFFFLL, "codec", v6);
          goto LABEL_11;
        }
      }
      --v3;
      v5 += 5;
    }
    while ( v3 );
  }
  v7 = 0;
LABEL_11:
  *(_DWORD *)(v1 + 324) = v7;
  return 0;
}
