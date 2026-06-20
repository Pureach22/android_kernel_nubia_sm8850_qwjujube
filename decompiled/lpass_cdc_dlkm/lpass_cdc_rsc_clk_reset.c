__int64 __fastcall lpass_cdc_rsc_clk_reset(__int64 a1, unsigned int a2)
{
  __int64 rsc_clk_device_ptr; // x0
  __int64 v4; // x21
  __int64 v5; // x22
  int v6; // w23
  __int64 v7; // x20
  __int64 v10; // x20
  void *v11; // x0

  if ( !a1 )
  {
    v11 = &unk_DCD3;
LABEL_19:
    printk(v11, "lpass_cdc_rsc_clk_reset");
    return 4294967274LL;
  }
  if ( a2 >= 8 )
  {
    printk(&unk_D86A, "lpass_cdc_rsc_clk_reset");
    return 4294967274LL;
  }
  rsc_clk_device_ptr = lpass_cdc_get_rsc_clk_device_ptr(*(_QWORD *)(a1 + 96));
  if ( !rsc_clk_device_ptr )
  {
    v11 = &unk_D96C;
    goto LABEL_19;
  }
  v4 = *(_QWORD *)(rsc_clk_device_ptr + 152);
  if ( !v4 )
  {
    v11 = &unk_DF67;
    goto LABEL_19;
  }
  mutex_lock(v4 + 8);
  v5 = v4 + 104;
  if ( (_clk_is_enabled(*(_QWORD *)(v4 + 104 + 8LL * a2)) & 1) != 0 )
  {
    v6 = 0;
    do
    {
      v7 = *(_QWORD *)(v5 + 8LL * a2);
      clk_disable(v7);
      clk_unprepare(v7);
      --v6;
    }
    while ( (_clk_is_enabled(*(_QWORD *)(v5 + 8LL * a2)) & 1) != 0 );
    if ( v6 )
    {
      do
      {
        v10 = *(_QWORD *)(v5 + 8LL * a2);
        if ( !(unsigned int)clk_prepare(v10) )
        {
          if ( (unsigned int)clk_enable(v10) )
            clk_unprepare(v10);
        }
      }
      while ( !__CFADD__(v6++, 1) );
    }
  }
  mutex_unlock(v4 + 8);
  return 0;
}
