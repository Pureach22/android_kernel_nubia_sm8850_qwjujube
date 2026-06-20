__int64 __fastcall dummy_clk_probe(__int64 a1)
{
  __int64 v2; // x20
  const char *v3; // x22
  __int64 v4; // x0
  unsigned __int64 v5; // x21
  __int64 v6; // x23
  void *v8; // x0
  __int64 v9; // x0
  __int64 v10; // x23
  const char *v11; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v12[5]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v13; // [xsp+38h] [xbp-18h]
  __int64 v14; // [xsp+40h] [xbp-10h]
  __int64 v15; // [xsp+48h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v11 = "dummy_clk";
  of_property_read_string(v2, "clock-output-names", &v11);
  v3 = v11;
  v13 = 0;
  memset(&v12[2], 0, 24);
  v4 = devm_kmalloc(a1 + 16, 128, 3520);
  if ( !v4 )
    goto LABEL_2;
  v6 = v4;
  v12[0] = v3;
  v12[1] = &clk_dummy_ops;
  *(_QWORD *)(v4 + 16) = v12;
  v14 = 0;
  LOBYTE(v13) = 0;
  v5 = devm_clk_register(a1 + 16, v4);
  if ( v5 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_4;
  *(_QWORD *)(v6 + 24) = &dummy_reset_ops;
  *(_QWORD *)(v6 + 80) = v2;
  *(_DWORD *)(v6 + 112) = 100;
  v8 = (unsigned int)devm_reset_controller_register(a1 + 16, v6 + 24) ? &unk_6727 : &unk_66A3;
  printk(v8, v3);
  v9 = devm_kmalloc(a1 + 16, 1536, 3520);
  if ( !v9 )
  {
LABEL_2:
    LODWORD(v5) = -12;
LABEL_4:
    printk(&unk_6667, v11);
    goto LABEL_5;
  }
  v10 = v9;
  *(_QWORD *)(v9 + 1288) = v3;
  if ( (unsigned int)pm_genpd_init() )
    printk(&unk_663A, v3);
  if ( (unsigned int)of_genpd_add_provider_simple(v2, v10) )
    printk(&unk_6755, v3);
  else
    printk(&unk_66F9, v3);
  LODWORD(v5) = of_clk_add_provider(v2, &of_clk_src_simple_get, v5);
  if ( !(_DWORD)v5 )
    dev_info(a1 + 16, "Successfully registered dummy clock controller for %s\n", v11);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
