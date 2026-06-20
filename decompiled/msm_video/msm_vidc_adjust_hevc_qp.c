__int64 __fastcall msm_vidc_adjust_hevc_qp(__int64 a1, unsigned int a2)
{
  int v2; // w8
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8

  v2 = *(_DWORD *)(a1 + 312);
  if ( v2 != 2 && v2 != 8 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      cap_name(a2);
      printk(&unk_87D50, "err ", a1 + 340, "msm_vidc_adjust_hevc_qp", a2);
    }
    return 4294967274LL;
  }
  if ( (((__int64 (__fastcall *)(__int64, _QWORD, __int64, const char *))is_parent_available)(
          a1,
          a2,
          82,
          "msm_vidc_adjust_hevc_qp")
      & 1) == 0 )
    return 4294967274LL;
  v5 = *(_QWORD *)(a1 + 18128);
  result = 0;
  if ( v5 != 8 && v5 != 16 )
  {
    v7 = a1 + 168LL * a2;
    if ( *(__int64 *)(v7 + 4352) <= 0 )
      *(_QWORD *)(v7 + 4352) = 1;
    if ( a2 != 33 )
    {
      if ( a2 == 32 )
      {
        if ( *(__int64 *)(a1 + 26696) <= 0 )
          *(_QWORD *)(a1 + 26696) = 1;
        if ( *(__int64 *)(a1 + 26864) <= 0 )
          *(_QWORD *)(a1 + 26864) = 1;
        if ( *(__int64 *)(a1 + 27032) <= 0 )
        {
          *(_QWORD *)(a1 + 27032) = 1;
          return 0;
        }
      }
      return 0;
    }
    if ( *(__int64 *)(a1 + 27200) <= 0 )
      *(_QWORD *)(a1 + 27200) = 1;
    if ( *(__int64 *)(a1 + 27368) <= 0 )
      *(_QWORD *)(a1 + 27368) = 1;
    if ( *(__int64 *)(a1 + 27536) > 0 )
      return 0;
    *(_QWORD *)(a1 + 27536) = 1;
    return 0;
  }
  return result;
}
