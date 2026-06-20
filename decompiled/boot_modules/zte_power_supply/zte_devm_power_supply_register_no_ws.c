__int64 __fastcall zte_devm_power_supply_register_no_ws(__int64 a1, const char **a2, _QWORD *a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x21
  unsigned __int64 v8; // x20

  v6 = _devres_alloc_node(zte_devm_power_supply_release, 8, 3264, 0xFFFFFFFFLL, "zte_devm_power_supply_release");
  if ( !v6 )
    return -12;
  v7 = (_QWORD *)v6;
  v8 = _zte_power_supply_register(a1, a2, a3, 0);
  if ( v8 < 0xFFFFFFFFFFFFF001LL )
  {
    *v7 = v8;
    devres_add(a1, v7);
  }
  else
  {
    devres_free(v7);
  }
  return v8;
}
