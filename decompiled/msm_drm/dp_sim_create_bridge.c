__int64 __fastcall dp_sim_create_bridge(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x22
  __int64 result; // x0
  unsigned int v9; // w19
  _QWORD v10[6]; // [xsp+0h] [xbp-30h] BYREF

  v10[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = devm_kmalloc(a1, 2288, 3520);
  if ( v4 )
  {
    v5 = *(_QWORD *)(a1 + 744);
    v6 = v4;
    *(_QWORD *)v4 = a1;
    *(_QWORD *)(v4 + 8) = v5;
    v7 = v4 + 8;
    *(_QWORD *)(v4 + 16) = v4;
    *(_QWORD *)(v4 + 56) = dp_sim_register_hpd;
    *(_QWORD *)(v4 + 64) = &dp_sim_transfer;
    *(_DWORD *)(v4 + 24) = -2147483646;
    *(_QWORD *)(v4 + 2208) = v4 + 2208;
    *(_QWORD *)(v4 + 2216) = v4 + 2208;
    _mutex_init(v4 + 88, "&dp_sim_dev->lock", &dp_sim_create_bridge___key);
    v10[0] = v6;
    v10[1] = 0;
    v10[2] = 0;
    v10[3] = dp_sim_host_hpd_irq;
    v10[4] = 0;
    result = dp_mst_sim_create(v10, v6 + 32);
    if ( (_DWORD)result )
    {
      v9 = result;
      devm_kfree(a1);
      result = v9;
    }
    else
    {
      *a2 = v7;
      *(_BYTE *)(v6 + 162) = -60;
      *(_WORD *)(v6 + 160) = 5138;
      *(_DWORD *)(v6 + 674) = 50427767;
      *(_BYTE *)(v6 + 672) = 1;
      *(_BYTE *)(v6 + 2282) = 1;
      *(_BYTE *)(v6 + 864) = 3;
      *(_DWORD *)(v6 + 2232) = -1;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
