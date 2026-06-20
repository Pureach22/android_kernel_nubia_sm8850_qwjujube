__int64 __fastcall msm_vidc_adjust_dec_output_tx_fence_type(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x2

  if ( a2 )
    v3 = *(int *)(a2 + 196);
  else
    v3 = *(_QWORD *)(a1 + 14936);
  v4 = *(_QWORD *)(a1 + 320);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          63,
          7,
          "msm_vidc_adjust_dec_output_tx_fence_type")
      & 1) == 0 )
    return 4294967274LL;
  if ( v3 == 2 )
  {
    if ( *(_QWORD *)(v4 + 4624) )
      v3 = 2;
    else
      v3 = 1;
  }
  if ( (*(_BYTE *)(a1 + 5544) & 0x80) != 0 )
  {
    if ( (~*(_DWORD *)(a1 + 5528) & 9LL) != 0 )
      v5 = 0;
    else
      v5 = v3;
  }
  else
  {
    v5 = 0;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    63,
    v5,
    "msm_vidc_adjust_dec_output_tx_fence_type");
  return 0;
}
