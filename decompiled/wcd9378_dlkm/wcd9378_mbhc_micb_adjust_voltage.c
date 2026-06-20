__int64 __fastcall wcd9378_mbhc_micb_adjust_voltage(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v4; // x25
  unsigned int v7; // w24
  unsigned int v8; // w23
  unsigned int v9; // w22

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( v4 )
  {
    if ( a3 - 1 >= 3 )
    {
      ((void (*)(void))dev_err)();
      v8 = 0;
      v7 = 0;
    }
    else
    {
      v7 = 255;
      v8 = dword_1E6B8[a3 - 1];
    }
    mutex_lock(v4 + 136);
    v9 = wcd9378_micb_usage_value_convert(a1, a2, a3);
    snd_soc_component_update_bits(a1, v8, v7, v9);
    if ( a3 == 2 )
    {
      dev_err(*(_QWORD *)(a1 + 24), "%s: sj micbias set\n", "wcd9378_mbhc_micb_adjust_voltage");
      snd_soc_component_update_bits(a1, 1086326680, 255, v9);
      *(_DWORD *)(v4 + 368) = a2;
    }
    mutex_unlock(v4 + 136);
    return 0;
  }
  else
  {
    ((void (*)(void))dev_err)();
    return 4294967274LL;
  }
}
