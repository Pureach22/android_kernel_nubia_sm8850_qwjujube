__int64 __fastcall sde_encoder_helper_calc_vsync_count(__int64 a1, int a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned int rate; // w0
  void *v11; // x0

  if ( !a1 || !*(_QWORD *)a1 )
  {
    v11 = &unk_26FCAB;
LABEL_13:
    printk(v11, "sde_encoder_get_kms");
LABEL_14:
    printk(&unk_26C6E1, "sde_encoder_helper_calc_vsync_count");
    return 0;
  }
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 8)) == 0 )
  {
    v11 = &unk_234896;
    goto LABEL_13;
  }
  v5 = *(_QWORD *)(v4 + 136);
  if ( !v5 )
    goto LABEL_14;
  v6 = *(_QWORD *)(v5 + 56);
  if ( !v6 )
    goto LABEL_14;
  rate = sde_power_clk_get_rate((int)v6 + 16, "vsync_clk");
  if ( a3 && a2 && rate )
    return rate / (a3 * a2);
  printk(&unk_25AB4F, "sde_encoder_helper_calc_vsync_count");
  return 0;
}
