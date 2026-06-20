__int64 init_module()
{
  __int64 v0; // x8
  __int64 result; // x0
  bool v2; // zf
  int v3; // [xsp+Ch] [xbp-14h]
  __int64 v4; // [xsp+10h] [xbp-10h]
  __int64 v5; // [xsp+18h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = msm_cdc_pinctrl_drv_init();
  if ( v3 )
    printk(&unk_9E0D, "wcd9xxx_core_init");
  v0 = 0;
  v4 = 0;
  do
  {
    result = *(unsigned int *)((char *)&v3 + v0);
    if ( (_DWORD)result )
      break;
    v2 = v0 == 8;
    v0 += 4;
  }
  while ( !v2 );
  _ReadStatusReg(SP_EL0);
  return result;
}
