__int64 __fastcall aw882xx_dsp_set_copp_module_en(char a1)
{
  const char *v1; // x2

  if ( (a1 & 1) != 0 )
    v1 = "enable";
  else
    v1 = "disable";
  printk(&unk_279CE, "aw882xx_dsp_set_copp_module_en", v1);
  return 0;
}
