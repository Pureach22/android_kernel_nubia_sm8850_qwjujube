_QWORD *__fastcall wcd_mbhc_adc_init(_QWORD *result)
{
  if ( !result )
    return (_QWORD *)printk(&unk_E4A0, "wcd_mbhc_adc_init");
  result[115] = &mbhc_fn;
  result[100] = 0xFFFFFFFE00000LL;
  result[101] = result + 101;
  result[102] = result + 101;
  result[103] = wcd_correct_swch_plug;
  return result;
}
