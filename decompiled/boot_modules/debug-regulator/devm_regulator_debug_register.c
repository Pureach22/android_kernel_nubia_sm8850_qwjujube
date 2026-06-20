__int64 __fastcall devm_regulator_debug_register(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x21
  unsigned __int64 v6; // x0
  unsigned int v7; // w20

  v4 = _devres_alloc_node(devm_regulator_debug_release, 8, 3264, 0xFFFFFFFFLL, "devm_regulator_debug_release");
  if ( v4 )
  {
    v5 = (_QWORD *)v4;
    v6 = regulator_debug_add(a1, a2);
    v7 = v6;
    if ( v6 && v6 < 0xFFFFFFFFFFFFF001LL )
    {
      *v5 = v6;
      devres_add(a1, v5);
      return 0;
    }
    else
    {
      devres_free(v5);
    }
  }
  else
  {
    return (unsigned int)-12;
  }
  return v7;
}
