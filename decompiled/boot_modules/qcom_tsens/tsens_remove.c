__int64 __fastcall tsens_remove(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 result; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8

  v1 = *(_QWORD **)(a1 + 168);
  debugfs_remove(v1[321]);
  result = regmap_field_update_bits_base(v1[14], 0xFFFFFFFFLL, 0, 0, 0, 0);
  v3 = *(__int64 (__fastcall **)(_QWORD))(v1[320] + 32LL);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != 797716802 )
      __break(0x8228u);
    return v3(v1);
  }
  return result;
}
