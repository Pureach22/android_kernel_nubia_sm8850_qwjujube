__int64 __fastcall wcd9378_aux_pa_gain_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x3

  v2 = *(_QWORD *)(a1 + 128);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a2 + 72);
  if ( v3 >= 9 )
  {
    dev_err(*(_QWORD *)(v2 + 24), "%s: Unsupported gain val %ld\n", "wcd9378_aux_pa_gain_put", v3);
    return 4294967274LL;
  }
  else
  {
    snd_soc_component_update_bits(v2, 1075315140, 15, v3);
    return 0;
  }
}
