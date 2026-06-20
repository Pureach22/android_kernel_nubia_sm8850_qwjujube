__int64 __fastcall msm_vidc_query_menu(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  __int64 v5; // x9
  __int64 v6; // x6
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x2
  unsigned int v10; // w19

  v4 = v4l2_ctrl_find(a1 + 1424, *a2);
  if ( !v4 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8034D, "err ", a1 + 340, "msm_vidc_query_menu", *a2);
    return 4294967274LL;
  }
  if ( *(_DWORD *)(v4 + 88) != 3 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_93969, "err ", a1 + 340, "msm_vidc_query_menu", *(_QWORD *)(v4 + 80));
    return 4294967274LL;
  }
  v5 = a2[1];
  if ( *(_QWORD *)(v4 + 96) > v5 )
    return 4294967274LL;
  v6 = *(_QWORD *)(v4 + 104);
  v7 = v4;
  result = 4294967274LL;
  if ( v6 >= v5 )
  {
    if ( (*(_QWORD *)(v7 + 152) & (1 << v5)) != 0 )
      result = 4294967274LL;
    else
      result = 0;
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v9 = a1 + 340;
        v10 = result;
        printk(&unk_91428, "high", v9, "msm_vidc_query_menu", *(_QWORD *)(v7 + 80));
        return v10;
      }
    }
  }
  return result;
}
