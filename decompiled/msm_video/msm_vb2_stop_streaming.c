__int64 __fastcall msm_vb2_stop_streaming(__int64 result)
{
  int *v1; // x19
  __int64 v2; // x20
  __int64 (__fastcall *v3)(__int64, __int64, int *); // x8
  __int64 v4; // x0
  const char *v5; // x0
  __int64 v6; // x4

  v1 = (int *)result;
  if ( result && (v2 = *(_QWORD *)(result + 72)) != 0 )
  {
    v3 = *(__int64 (__fastcall **)(__int64, __int64, int *))(v2 + 168);
    v4 = *(_QWORD *)(result + 72);
    if ( *((_DWORD *)v3 - 1) != -249828064 )
      __break(0x8228u);
    result = v3(v4, 5, v1);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v5 = v4l2_type_name(*v1);
        printk(&unk_8F40A, "err ", v2 + 340, v5, v6);
      }
      return msm_vidc_change_state(v2, 5u, (__int64)"msm_vb2_stop_streaming");
    }
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    return printk(&unk_879E7, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_stop_streaming");
  }
  return result;
}
