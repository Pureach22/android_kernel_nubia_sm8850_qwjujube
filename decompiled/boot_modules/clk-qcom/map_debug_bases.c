__int64 __fastcall map_debug_bases(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v6; // x0

  if ( !of_get_property(*(_QWORD *)(a1 + 760), a2, 0) )
    return 4294967243LL;
  v6 = syscon_regmap_lookup_by_phandle(*(_QWORD *)(a1 + 760), a2);
  *(_QWORD *)(a3 + 32) = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_29451);
    return *(unsigned int *)(a3 + 32);
  }
  else
  {
    regmap_mmio_detach_clk(v6);
    return 0;
  }
}
