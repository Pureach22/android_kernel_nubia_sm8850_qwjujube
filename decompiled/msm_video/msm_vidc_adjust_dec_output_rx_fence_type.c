__int64 __fastcall msm_vidc_adjust_dec_output_rx_fence_type(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x8
  __int64 v6; // x2

  v2 = a1[40];
  if ( (((__int64 (*)(void))is_parent_available)() & 1) == 0 )
    return 4294967274LL;
  if ( a2 )
  {
    v5 = *(int *)(a2 + 196);
    if ( v5 == 2 )
      goto LABEL_4;
  }
  else
  {
    v5 = a1[1846];
    if ( v5 == 2 )
    {
LABEL_4:
      v5 = 1;
      if ( *(_QWORD *)(v2 + 4624) )
        v5 = 2;
    }
  }
  if ( a1[1825] )
    v6 = v5;
  else
    v6 = 0;
  ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    62,
    v6,
    "msm_vidc_adjust_dec_output_rx_fence_type");
  return 0;
}
