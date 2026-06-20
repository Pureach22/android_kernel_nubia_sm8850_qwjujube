__int64 __fastcall tmc_platform_probe(__int64 a1)
{
  __int64 resource; // x20
  __int64 v3; // x0
  _QWORD *v4; // x21
  unsigned __int64 v5; // x0
  unsigned __int64 v7; // x22
  int v8; // w23
  int v9; // w0
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  unsigned int v14; // w20
  unsigned int v21; // w9

  resource = platform_get_resource(a1, 512, 0);
  v3 = devm_kmalloc(a1 + 16, 432, 3520);
  if ( !v3 )
    return 4294967284LL;
  v4 = (_QWORD *)v3;
  v5 = clk_get(a1 + 16, "apb_pclk");
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    *v4 = 0;
    goto LABEL_11;
  }
  v7 = v5;
  v8 = clk_prepare(v5);
  if ( !v8 )
  {
    v9 = clk_enable(v7);
    if ( !v9 )
      goto LABEL_9;
    v8 = v9;
    clk_unprepare(v7);
  }
  clk_put(v7);
  v7 = v8;
LABEL_9:
  *v4 = v7;
  if ( v7 > 0xFFFFFFFFFFFFF000LL )
    return 4294967277LL;
LABEL_11:
  *(_QWORD *)(a1 + 168) = v4;
  _X8 = (unsigned int *)(a1 + 496);
  __asm { PRFM            #0x11, [X8] }
  do
    v21 = __ldxr(_X8);
  while ( __stxr(v21 + 1, _X8) );
  _pm_runtime_set_status(a1 + 16, 0);
  pm_runtime_enable(a1 + 16);
  v14 = tmc_add_coresight_dev((__int64 *)(a1 + 16), resource, v10, v11, v12, v13);
  _pm_runtime_idle(a1 + 16, 5);
  if ( !v14 )
    return 0;
  _pm_runtime_disable(a1 + 16, 1);
  return v14;
}
