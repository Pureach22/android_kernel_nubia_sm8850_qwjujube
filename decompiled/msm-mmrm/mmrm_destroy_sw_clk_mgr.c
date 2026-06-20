__int64 __fastcall mmrm_destroy_sw_clk_mgr(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x20
  _QWORD *v4; // x8
  _QWORD *v5; // x22
  _QWORD *v6; // x9

  v3 = (_QWORD *)(a1 + 136);
  v2 = *(_QWORD **)(a1 + 136);
  if ( v2 != v3 )
  {
    do
    {
      v5 = (_QWORD *)*v2;
      v4 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v4 == v2 && (_QWORD *)v5[1] == v2 )
      {
        v5[1] = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report();
        v2 = v6;
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      kfree(v2);
      v2 = v5;
    }
    while ( v5 != v3 );
  }
  if ( a1 )
  {
    kfree(*(_QWORD *)(a1 + 64));
    kfree(a1);
    return 0;
  }
  else
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_DB6F, "err ", "mmrm_destroy_sw_clk_mgr");
    return 4294967274LL;
  }
}
