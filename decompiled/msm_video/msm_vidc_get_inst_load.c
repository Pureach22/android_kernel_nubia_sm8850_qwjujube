__int64 __fastcall msm_vidc_get_inst_load(_DWORD *a1)
{
  int v1; // w8
  unsigned int v2; // w9
  int v3; // w10
  int v5; // w9
  unsigned int v6; // w10
  unsigned int v7; // w8

  if ( a1 )
  {
    v1 = a1[77];
    if ( v1 == 1 )
    {
      v2 = a1[472];
      v3 = a1[473];
    }
    else if ( v1 == 2 )
    {
      v2 = a1[98];
      if ( v2 <= a1[472] )
        v2 = a1[472];
      if ( a1[99] <= a1[473] )
        v3 = a1[473];
      else
        v3 = a1[99];
    }
    else
    {
      v2 = 0;
      v3 = 0;
    }
    v5 = ((v3 + 15) >> 4) * ((int)(v2 + 15) >> 4);
    v6 = *(_DWORD *)((char *)a1 + 19474);
    if ( v1 == 2 )
    {
      v7 = *(_DWORD *)((char *)a1 + 19642);
      if ( v6 > v7 )
        v7 = *(_DWORD *)((char *)a1 + 19474);
      v6 = *(_DWORD *)((char *)a1 + 19978);
      if ( v7 <= *(_DWORD *)((char *)a1 + 19810) )
        v7 = *(_DWORD *)((char *)a1 + 19810);
      if ( v7 > v6 )
        v6 = v7;
    }
    return v5 * v6;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_get_inst_load");
    return 4294967274LL;
  }
}
