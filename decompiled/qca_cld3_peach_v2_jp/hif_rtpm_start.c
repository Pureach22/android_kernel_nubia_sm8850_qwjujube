__int64 __fastcall hif_rtpm_start(__int64 a1)
{
  unsigned int conparam; // w0
  unsigned int v3; // w20
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x0
  unsigned int v8; // w8
  unsigned int v15; // w10
  __int64 v16; // x8
  int v17; // w9

  conparam = hif_get_conparam(a1);
  if ( (*(_BYTE *)gp_hif_rtpm_ctx & 1) == 0 )
    return qdf_trace_msg(61, 5, "%s: RUNTIME PM is disabled in ini", "hif_rtpm_start");
  v3 = conparam;
  if ( (pld_is_one_msi(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL)) & 1) != 0 )
    return qdf_trace_msg(61, 5, "%s: RUNTIME PM is disabled for single MSI mode", "hif_rtpm_start");
  if ( v3 <= 8 && ((1 << v3) & 0x130) != 0 )
    return qdf_trace_msg(61, 5, "%s: RUNTIME PM is disabled for FTM/EPPING/MONITOR mode", "hif_rtpm_start");
  qdf_trace_msg(61, 5, "%s: Enabling RUNTIME PM, Delay: %d ms", "hif_rtpm_start", *(_DWORD *)(a1 + 4));
  v5 = gp_hif_rtpm_ctx;
  *(_DWORD *)(gp_hif_rtpm_ctx + 188) = 1;
  v6 = *(_QWORD *)(v5 + 8);
  pm_runtime_set_autosuspend_delay(v6, *(unsigned int *)(a1 + 4));
  _pm_runtime_use_autosuspend(v6, 1);
  v7 = pm_runtime_allow(v6);
  *(_QWORD *)(v6 + 520) = ktime_get_mono_fast_ns(v7);
  v8 = *(_DWORD *)(v6 + 480);
  do
  {
    if ( !v8 )
      break;
    _X12 = (unsigned int *)(v6 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v15 = __ldxr(_X12);
      if ( v15 != v8 )
        break;
      if ( !__stlxr(v8 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v15 == v8;
    v8 = v15;
  }
  while ( !_ZF );
  *(_WORD *)(v6 + 488) |= 0x100u;
  v16 = gp_hif_rtpm_ctx;
  v17 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(gp_hif_rtpm_ctx + 312) = v17;
  *(_DWORD *)(v16 + 316) = v17;
  result = qdf_debugfs_create_entry("cnss_runtime_pm", 256, 0, 0, &hif_rtpm_fops);
  *(_QWORD *)(gp_hif_rtpm_ctx + 304) = result;
  return result;
}
