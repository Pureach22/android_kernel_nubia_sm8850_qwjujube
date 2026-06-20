__int64 __fastcall msm_vb2_start_streaming(__int64 a1)
{
  __int64 v2; // x19
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w21
  const char *v7; // x0
  __int64 v8; // x4

  if ( !a1 || (v2 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_879E7, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_start_streaming");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(v2 + 320) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_start_streaming");
    return 4294967274LL;
  }
  v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v2 + 168);
  v4 = *(_QWORD *)(a1 + 72);
  if ( *((_DWORD *)v3 - 1) != -249828064 )
    __break(0x8228u);
  result = v3(v4, 4, a1);
  if ( (_DWORD)result )
  {
    v6 = result;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v7 = v4l2_type_name(*(_DWORD *)a1);
      printk(&unk_90171, "err ", v2 + 340, v7, v8);
    }
    msm_vidc_change_state(v2, 5u, (__int64)"msm_vb2_start_streaming");
    return v6;
  }
  return result;
}
