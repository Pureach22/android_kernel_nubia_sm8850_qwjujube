__int64 __fastcall qcom_q6v5_unprepare(__int64 a1)
{
  __int64 v2; // x0

  disable_irq(*(unsigned int *)(a1 + 76));
  v2 = *(_QWORD *)(a1 + 32);
  if ( v2
    && (unsigned int)qmp_send(
                       v2,
                       "{class: image, res: load_state, name: %s, val: %s}",
                       *(const char **)(a1 + 288),
                       "off") )
  {
    dev_err(*(_QWORD *)a1, "failed to toggle load state\n");
  }
  icc_set_bw(*(_QWORD *)(a1 + 40), 0, 0);
  return *(unsigned __int8 *)(a1 + 136) ^ 1u;
}
