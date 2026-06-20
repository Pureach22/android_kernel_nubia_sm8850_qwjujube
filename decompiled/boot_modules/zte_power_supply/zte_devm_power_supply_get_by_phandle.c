unsigned __int64 __fastcall zte_devm_power_supply_get_by_phandle(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x20
  __int64 v6; // x0
  int v7; // w0
  unsigned __int64 v8; // x21
  __int64 device; // x0
  unsigned int v17; // w9
  _QWORD v18[11]; // [xsp+8h] [xbp-58h] BYREF

  v18[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 744) )
  {
    v8 = -19;
    goto LABEL_13;
  }
  v4 = _devres_alloc_node(zte_devm_power_supply_put, 8, 3264, 0xFFFFFFFFLL, "zte_devm_power_supply_put");
  if ( !v4 )
  {
    v8 = -12;
    goto LABEL_13;
  }
  v5 = (_QWORD *)v4;
  v6 = *(_QWORD *)(a1 + 744);
  memset(v18, 0, 80);
  v7 = _of_parse_phandle_with_args(v6, a2, 0, 0, 0, v18);
  v8 = -19;
  if ( v7 || !v18[0] )
  {
LABEL_12:
    devres_free(v5);
    goto LABEL_13;
  }
  device = class_find_device(zte_power_supply_class, 0, v18[0], zte_power_supply_match_device_node);
  if ( !device )
  {
    v8 = 0;
    goto LABEL_12;
  }
  v8 = *(_QWORD *)(device + 152);
  _X8 = (unsigned int *)(v8 + 1112);
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stxr(v17 + 1, _X8) );
  if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_12;
  *v5 = v8;
  devres_add(a1, v5);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v8;
}
