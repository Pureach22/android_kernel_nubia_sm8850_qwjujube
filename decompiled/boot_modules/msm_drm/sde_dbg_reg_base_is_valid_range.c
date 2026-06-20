__int64 __fastcall sde_dbg_reg_base_is_valid_range(__int64 a1, unsigned int a2, int a3)
{
  __int64 *v3; // x0
  __int64 *v4; // x8
  __int64 *v5; // t1
  unsigned int v6; // w9

  v5 = *(__int64 **)(a1 + 16);
  v3 = (__int64 *)(a1 + 16);
  v4 = v5;
  if ( v5 == v3 )
  {
LABEL_10:
    printk(&unk_2468DC, "sde_dbg_reg_base_is_valid_range");
    return 0;
  }
  else
  {
    v6 = a3 + a2;
    if ( a2 > a3 + a2 )
      v6 = a2;
    while ( *((_DWORD *)v4 + 16) > a2 || *((_DWORD *)v4 + 17) < v6 )
    {
      v4 = (__int64 *)*v4;
      if ( v4 == v3 )
        goto LABEL_10;
    }
    return 1;
  }
}
