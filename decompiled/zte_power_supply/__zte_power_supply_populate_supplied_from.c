__int64 __fastcall _zte_power_supply_populate_supplied_from(__int64 a1, __int64 a2)
{
  int v3; // w21
  const char ***v4; // x22
  __int64 v5; // x0
  _QWORD v7[11]; // [xsp+8h] [xbp-58h] BYREF

  v3 = -1;
  v7[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(const char ****)(a1 + 152);
  while ( 1 )
  {
    v5 = *(_QWORD *)(a2 + 40);
    memset(v7, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(v5, "power-supplies", 0, 0, (unsigned int)(v3 + 1), v7) || !v7[0] )
      break;
    ++v3;
    if ( (const char **)v7[0] == v4[5] )
    {
      dev_info(a2 + 56, "%s: Found supply : %s\n", **(const char ***)a2, **v4);
      *(_QWORD *)(*(_QWORD *)(a2 + 24) + 8LL * v3) = **v4;
      ++*(_QWORD *)(a2 + 32);
      break;
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
