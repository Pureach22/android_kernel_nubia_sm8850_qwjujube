__int64 __fastcall msm_venc_start_cmd(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_871F7, "high", a1 + 340, a4, a5);
  *(_WORD *)(*(_QWORD *)(a1 + 1864) + 320LL) &= ~0x200u;
  *(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) &= ~0x200u;
  msm_vidc_allow_dcvs(a1);
  msm_vidc_power_data_reset(a1);
  msm_vidc_print_buffer_info(a1);
  msm_vidc_print_memory_stats(a1);
  return msm_vidc_process_resume(a1);
}
