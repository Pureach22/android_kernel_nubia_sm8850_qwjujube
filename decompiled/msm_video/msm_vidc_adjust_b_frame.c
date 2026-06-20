__int64 __fastcall msm_vidc_adjust_b_frame(__int64 a1)
{
  unsigned __int64 v1; // x20
  __int64 v3; // x8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x2

  v1 = *(unsigned int *)(a1 + 15928);
  if ( (((__int64 (*)(void))is_parent_available)() & 1) == 0 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 15272);
  if ( v3 && *(_DWORD *)(a1 + 1832) == 3 )
  {
    v4 = (unsigned int)~(-1 << v3);
    if ( v1 >= v4 )
      v5 = v4;
    else
      v5 = v1;
  }
  else
  {
    v5 = 0;
  }
  ((void (__fastcall *)(__int64, __int64, unsigned __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    69,
    v5,
    "msm_vidc_adjust_b_frame");
  return 0;
}
