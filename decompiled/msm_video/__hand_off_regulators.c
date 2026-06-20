__int64 __fastcall _hand_off_regulators(__int64 a1)
{
  __int64 v2; // x8
  _QWORD *v3; // x28
  int v4; // w27
  unsigned int v5; // w0
  unsigned int v7; // w21
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x20

  if ( is_core_sub_state(a1, 2) )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_966B8, "high", 0xFFFFFFFFLL, "codec", "__hand_off_regulators");
    return 0;
  }
  v2 = *(_QWORD *)(a1 + 3904);
  v3 = *(_QWORD **)(v2 + 32);
  if ( v3 >= &v3[3 * *(unsigned int *)(v2 + 40)] )
  {
LABEL_16:
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8E9FC, "high", 0xFFFFFFFFLL, "codec", "__hand_off_regulators");
    msm_vidc_change_core_sub_state(a1, 0, 2u, (__int64)"__hand_off_regulators");
    return 0;
  }
  v4 = 0;
  while ( *((_BYTE *)v3 + 16) != 1 )
  {
LABEL_8:
    v3 += 3;
    if ( (unsigned __int64)v3 >= *(_QWORD *)(v2 + 32) + 24 * (unsigned __int64)*(unsigned int *)(v2 + 40) )
      goto LABEL_16;
  }
  v5 = regulator_set_mode(*v3, 1);
  if ( !v5 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_84681, "high", 0xFFFFFFFFLL, "codec", "__hand_off_regulator");
    if ( !(unsigned int)regulator_is_enabled(*v3) )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_852A9, "err ", 0xFFFFFFFFLL, "codec", "__hand_off_regulator");
      __break(0x800u);
    }
    v2 = *(_QWORD *)(a1 + 3904);
    ++v4;
    goto LABEL_8;
  }
  v7 = v5;
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_93F4E, "err ", 0xFFFFFFFFLL, "codec", "__hand_off_regulator");
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 32LL);
  v9 = v8 + 24LL * v4;
  if ( v9 >= v8 )
  {
    do
    {
      _acquire_regulator(v9);
      v9 -= 24LL;
    }
    while ( v9 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 32LL) );
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_95BEE, "err ", 0xFFFFFFFFLL, "codec", "__hand_off_regulators");
  return v7;
}
