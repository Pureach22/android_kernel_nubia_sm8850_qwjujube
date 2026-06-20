__int64 __fastcall sde_encoder_helper_report_irq_timeout(__int64 *a1, int a2)
{
  int v3; // w4
  __int64 result; // x0
  __int64 (__fastcall *v5)(__int64, __int64 *, __int64); // x8
  __int64 v6; // x0

  if ( *a1 )
    v3 = *(_DWORD *)(*a1 + 24);
  else
    v3 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_helper_report_irq_timeout",
    562,
    -1,
    v3,
    *((_DWORD *)a1 + 168) - 1,
    *(_DWORD *)(a1[62] + 32) - 1,
    a2,
    239);
  result = printk(&unk_249159, "sde_encoder_helper_report_irq_timeout");
  v5 = (__int64 (__fastcall *)(__int64, __int64 *, __int64))a1[49];
  if ( v5 )
  {
    v6 = *a1;
    if ( *((_DWORD *)v5 - 1) != -570463643 )
      __break(0x8228u);
    return v5(v6, a1, 2);
  }
  return result;
}
