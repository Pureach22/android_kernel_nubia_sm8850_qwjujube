bool __fastcall msm_vidc_check_input_fence_allowed(__int64 a1)
{
  unsigned int v1; // w19

  v1 = *(_DWORD *)(a1 + 14264);
  if ( a1 && v1 != 2 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_91572, "err ", a1 + 340, "msm_vidc_check_input_fence_allowed", v1);
  return v1 == 2;
}
