__int64 __fastcall hwmon_pec_register(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 (*v4)(void); // x8
  __int64 result; // x0
  unsigned int v6; // w20

  v2 = i2c_verify_client(*(_QWORD *)(a1 + 96));
  if ( !v2 )
    return 4294967274LL;
  v3 = v2;
  v4 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 16LL) + 32LL);
  if ( *((_DWORD *)v4 - 1) != 2093148950 )
    __break(0x8228u);
  if ( (v4() & 8) == 0 )
    return 0;
  result = device_create_file(v3 + 32, &dev_attr_pec);
  if ( !(_DWORD)result )
  {
    result = _devm_add_action(a1, hwmon_remove_pec, v3 + 32, "hwmon_remove_pec");
    if ( (_DWORD)result )
    {
      v6 = result;
      device_remove_file(v3 + 32, &dev_attr_pec);
      return v6;
    }
  }
  return result;
}
