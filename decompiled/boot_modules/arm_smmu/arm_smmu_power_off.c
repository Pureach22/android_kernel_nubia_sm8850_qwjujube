__int64 __fastcall arm_smmu_power_off(__int64 a1, const char ***a2)
{
  int v4; // w8
  const char *v5; // x1
  const char **v6; // x8
  _DWORD **v7; // x8
  _DWORD *v8; // x8
  int v9; // w8
  int v10; // w20
  int v11; // w8
  int v12; // w20
  const char **v13; // x0

  mutex_lock(a2 + 6);
  v4 = *((_DWORD *)a2 + 24);
  if ( v4 )
  {
    if ( v4 < 2 )
    {
      v6 = a2[14];
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != -54286643 )
          __break(0x8228u);
        ((void (__fastcall *)(const char ***))v6)(a2);
      }
      if ( a1 )
      {
        v7 = *(_DWORD ***)(a1 + 48);
        if ( v7 && (v8 = *v7) != nullptr )
        {
          if ( *(v8 - 1) != 616069899 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v8)(a1, 0, 32);
        }
        else
        {
          readl_relaxed_2(*(_QWORD *)(a1 + 8) + 32LL);
        }
        __dsb(0xDu);
      }
      v9 = *((_DWORD *)a2 + 4);
      if ( v9 )
      {
        v10 = v9 - 1;
        do
          clk_disable(a2[1][v10--]);
        while ( v10 != -1 );
        v11 = *((_DWORD *)a2 + 4);
        if ( v11 )
        {
          v12 = v11 - 1;
          do
            clk_unprepare(a2[1][v12--]);
          while ( v12 != -1 );
        }
      }
      regulator_bulk_disable(*((unsigned int *)a2 + 8), a2[3]);
      v13 = a2[5];
      if ( v13 && (unsigned int)icc_set_bw(v13, 0, 0) )
        __break(0x800u);
      *((_DWORD *)a2 + 24) = 0;
    }
    else
    {
      *((_DWORD *)a2 + 24) = v4 - 1;
    }
  }
  else
  {
    v5 = (*a2)[14];
    if ( !v5 )
      v5 = **a2;
    _warn_printk("%s: Bad power count\n", v5);
    __break(0x800u);
  }
  return mutex_unlock(a2 + 6);
}
