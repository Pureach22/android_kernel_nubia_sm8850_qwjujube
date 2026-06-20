__int64 __fastcall msm_vidc_query_ctrl(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  __int64 v5; // x4

  v4 = v4l2_ctrl_find(a1 + 1424, *a2);
  if ( v4 )
  {
    v5 = *(unsigned int *)(v4 + 96);
    a2[10] = v5;
    a2[11] = *(_DWORD *)(v4 + 104);
    *(_QWORD *)(a2 + 13) = *(unsigned int *)(v4 + 112);
    a2[12] = *(_DWORD *)(v4 + 152);
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_840E8, "high", a1 + 340, *(_QWORD *)(v4 + 80), v5);
    }
    return 0;
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8034D, "err ", a1 + 340, "msm_vidc_query_ctrl", *a2);
    return 4294967274LL;
  }
}
