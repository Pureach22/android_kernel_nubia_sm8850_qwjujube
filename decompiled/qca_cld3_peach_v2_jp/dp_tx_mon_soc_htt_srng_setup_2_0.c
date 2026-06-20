__int64 __fastcall dp_tx_mon_soc_htt_srng_setup_2_0(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21

  v2 = *(_QWORD *)(a1 + 20056);
  hal_set_low_threshold(*(_QWORD *)(v2 + 456), 0);
  return htt_srng_setup(*(_QWORD *)(a1 + 48), a2, *(_QWORD *)(v2 + 456), 24);
}
