__int64 __fastcall lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_put(__int64 a1, __int64 a2)
{
  snd_soc_component_update_bits(*(_QWORD *)(a1 + 128), 16772, 4, 4 * (unsigned int)(*(_QWORD *)(a2 + 72) != 0));
  return 0;
}
