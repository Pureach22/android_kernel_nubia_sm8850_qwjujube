__int64 __fastcall msm_vidc_vb2_buffer_done(__int64 a1, __int64 a2)
{
  __int64 v2; // x4
  __int64 v3; // x9
  __int64 *i; // x8
  __int64 *v5; // x9
  __int64 *v6; // t1
  int v7; // w9
  int v8; // w10
  int v9; // w11
  __int64 v10; // x1

  v2 = (unsigned int)(*(_DWORD *)(a2 + 24) - 1);
  if ( (unsigned int)v2 >= 4 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_811DF, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_vb2_buffer_done");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 8LL * (unsigned int)v2 + 1840);
  if ( (*(_WORD *)(v3 + 320) & 1) == 0 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_88532, "err ", a1 + 340, "msm_vidc_vb2_buffer_done", v2);
    }
    return 4294967274LL;
  }
  v6 = *(__int64 **)(v3 + 248);
  v5 = (__int64 *)(v3 + 248);
  for ( i = v6; ; i = (__int64 *)*i )
  {
    if ( i == v5 )
    {
      print_vidc_buffer(1, (__int64)"err ", (__int64)"vb2 not found for", a1, a2);
      return 4294967274LL;
    }
    if ( *((_DWORD *)i - 114) == 4 && *((_DWORD *)i - 134) == *(_DWORD *)(a2 + 32) )
      break;
  }
  v7 = *(_DWORD *)(a2 + 64);
  *((_DWORD *)i + 8) = v7;
  *(i - 65) = *(_QWORD *)(a2 + 72);
  v8 = *(_DWORD *)(a2 + 44);
  *((_DWORD *)i - 100) = v8;
  v9 = *(_DWORD *)(a2 + 48);
  if ( (v7 & 0x40) != 0 )
    v10 = 6;
  else
    v10 = 5;
  *((_DWORD *)i - 106) = v9 + v8;
  vb2_buffer_done(i - 68, v10);
  return 0;
}
