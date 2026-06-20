__int64 __fastcall msm_vidc_synx_fence_enable_resources(__int64 a1, char a2)
{
  bool v4; // w0
  __int64 result; // x0
  __int64 v6; // x0
  unsigned int v7; // w1
  unsigned int v8; // w2
  unsigned int v9; // w19

  if ( !*(_QWORD *)(a1 + 4656) )
    return 0;
  v4 = is_core_sub_state(a1, 128);
  if ( (a2 & 1) != 0 )
  {
    if ( !v4 )
    {
      result = synx_enable_resources(1152, 1, 1);
      if ( !(_DWORD)result )
      {
        v6 = a1;
        v7 = 0;
        v8 = 128;
LABEL_15:
        msm_vidc_change_core_sub_state(v6, v7, v8, (__int64)"msm_vidc_synx_fence_enable_resources");
        return 0;
      }
LABEL_9:
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v9 = result;
        printk(&unk_808AC, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_synx_fence_enable_resources");
        return v9;
      }
      return result;
    }
  }
  else if ( v4 )
  {
    result = synx_enable_resources(1152, 1, 0);
    if ( !(_DWORD)result )
    {
      v6 = a1;
      v7 = 128;
      v8 = 0;
      goto LABEL_15;
    }
    goto LABEL_9;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    is_core_sub_state(a1, 128);
    printk(&unk_839FB, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_synx_fence_enable_resources");
  }
  return 4294967274LL;
}
