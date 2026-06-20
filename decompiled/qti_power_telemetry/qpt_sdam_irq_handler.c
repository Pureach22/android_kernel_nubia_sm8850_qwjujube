__int64 __fastcall qpt_sdam_irq_handler(__int64 a1, _BYTE *a2)
{
  __int64 v3; // x4
  __int64 v4; // x5
  __int64 v5; // x0

  mutex_lock(a2 + 200);
  qti_qpt_read_all_data(a2, &print_fmt_qpt_update_channel_data[5], (unsigned __int8)a2[79] + 5, 0, v3, v4);
  if ( a2[78] )
    qti_qpt_read_all_data(
      a2,
      (const char *)((unsigned int)(unsigned __int8)a2[80] + 69),
      (unsigned __int8)a2[81] + 5LL,
      1);
  v5 = mutex_unlock(a2 + 200);
  qptm_power_data_update(v5);
  return 1;
}
