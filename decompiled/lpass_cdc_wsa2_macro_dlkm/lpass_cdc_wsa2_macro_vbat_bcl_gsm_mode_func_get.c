__int64 __fastcall lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_get(__int64 a1, __int64 a2)
{
  __int64 v3; // x8

  v3 = ((unsigned int)snd_soc_component_read(*(_QWORD *)(a1 + 128), 16772) >> 2) & 1;
  *(_QWORD *)(a2 + 72) = v3;
  return 0;
}
