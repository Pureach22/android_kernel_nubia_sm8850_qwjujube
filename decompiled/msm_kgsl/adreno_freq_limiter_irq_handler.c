__int64 __fastcall adreno_freq_limiter_irq_handler(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x27
  unsigned int v5; // w8
  unsigned int v6; // w9

  if ( !(unsigned int)__ratelimit(&adreno_freq_limiter_irq_handler__rs, "adreno_freq_limiter_irq_handler") )
    goto LABEL_2;
  v5 = *(_DWORD *)(a2 + 10040);
  if ( v5 < 0x20 )
  {
    v6 = *(_DWORD *)(a2 + 10044);
    if ( v6 <= 0x1F )
    {
      dev_err(
        *(_QWORD *)a2,
        "GPU req freq %u from prev freq %u unsupported for speed_bin: %d, soc_code: 0x%x\n",
        *(_DWORD *)(a2 + 9144 + 28LL * v5),
        *(_DWORD *)(a2 + 9144 + 28LL * v6),
        *(_DWORD *)(a2 + 13176),
        *(_DWORD *)(a2 + 13188));
LABEL_2:
      reset_control_reset(*(_QWORD *)(a2 + 14160));
      return 1;
    }
  }
  __break(0x5512u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v2);
  return adreno_pm_notifier();
}
