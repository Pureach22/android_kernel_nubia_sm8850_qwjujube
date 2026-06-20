__int64 __fastcall lpass_cdc_clk_rsc_fs_gen_request(__int64 a1, char a2)
{
  __int64 rsc_clk_device_ptr; // x0
  int *v4; // x21
  __int64 regmap; // x0
  __int64 v6; // x19
  int v7; // w8
  unsigned int v8; // w20
  int v9; // w8
  int v10; // w8
  unsigned __int64 v11; // x20
  int v12; // w22
  bool v13; // cc
  void *v15; // x0

  if ( !a1 )
  {
    v15 = &unk_DCD3;
    return printk(v15, "lpass_cdc_clk_rsc_fs_gen_request");
  }
  rsc_clk_device_ptr = lpass_cdc_get_rsc_clk_device_ptr(*(_QWORD *)(a1 + 96));
  if ( !rsc_clk_device_ptr )
  {
    v15 = &unk_D96C;
    return printk(v15, "lpass_cdc_clk_rsc_fs_gen_request");
  }
  v4 = *(int **)(rsc_clk_device_ptr + 152);
  if ( !v4 )
  {
    v15 = &unk_DF67;
    return printk(v15, "lpass_cdc_clk_rsc_fs_gen_request");
  }
  regmap = dev_get_regmap(*(_QWORD *)(*(_QWORD *)v4 + 96LL), 0);
  if ( !regmap )
  {
    v15 = &unk_DB44;
    return printk(v15, "lpass_cdc_clk_rsc_fs_gen_request");
  }
  v6 = regmap;
  mutex_lock(v4 + 14);
  v7 = v4[50];
  if ( (a2 & 1) != 0 )
  {
    v4[50] = v7 + 1;
    if ( !v7 && v4[53] )
    {
      v8 = 0;
      do
      {
        regmap_update_bits_base(
          v6,
          *(unsigned int *)(*((_QWORD *)v4 + 27) + 4LL * (int)v8),
          *(unsigned int *)(*((_QWORD *)v4 + 27) + 4LL * (int)(v8 + 1)),
          *(unsigned int *)(*((_QWORD *)v4 + 27) + 4LL * (int)(v8 + 2)),
          0,
          0,
          0);
        v8 += 3;
      }
      while ( v8 < 3 * v4[53] );
    }
  }
  else if ( v7 <= 0 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_clk_rsc_fs_gen_request__rs, "lpass_cdc_clk_rsc_fs_gen_request") )
      dev_err(*(_QWORD *)v4, "%s: req_seq_cnt: %d is already disabled\n", "lpass_cdc_clk_rsc_fs_gen_request", v4[50]);
    v4[50] = 0;
  }
  else
  {
    v9 = v7 - 1;
    v4[50] = v9;
    if ( !v9 )
    {
      v10 = 3 * v4[53];
      v11 = (unsigned int)(v10 - 3);
      if ( v10 - 3 >= 0 )
      {
        v12 = v10 - 2;
        do
        {
          regmap_update_bits_base(
            v6,
            *(unsigned int *)(*((_QWORD *)v4 + 27) + 4 * v11),
            *(unsigned int *)(*((_QWORD *)v4 + 27) + 4LL * v12),
            0,
            0,
            0,
            0);
          v13 = v11 > 2;
          v11 -= 3LL;
          v12 -= 3;
        }
        while ( v13 );
      }
    }
  }
  return mutex_unlock(v4 + 14);
}
