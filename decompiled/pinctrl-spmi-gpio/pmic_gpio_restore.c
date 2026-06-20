__int64 __fastcall pmic_gpio_restore(__int64 a1)
{
  _QWORD *v1; // x21
  __int64 v2; // x20
  __int64 v3; // x8
  unsigned int v4; // w19
  __int64 v5; // x22
  __int64 result; // x0
  __int64 v7; // x23
  __int64 v8; // x8
  unsigned int v9; // w20

  v1 = *(_QWORD **)(a1 + 152);
  v2 = v1[2];
  v3 = *(unsigned int *)(*(_QWORD *)(v2 + 16) + 16LL);
  if ( !(_DWORD)v3 )
    return 0;
  v4 = 0;
  v5 = 0;
  result = 0;
  v7 = 24 * v3;
  while ( 1 )
  {
    if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 16) + 8LL) + v5 + 16) + 3LL) == 1 )
    {
      result = pmic_gpio_config_set(v2, v4, 0, 0);
      if ( (result & 0x80000000) != 0 )
        break;
    }
    v5 += 24;
    ++v4;
    if ( v7 == v5 )
      return result;
  }
  v8 = *(_QWORD *)(v2 + 16);
  v9 = result;
  dev_err(*v1, "Failed to restore pin %s[%d] ret=%d\n", *(const char **)(*(_QWORD *)(v8 + 8) + v5 + 8), v4, result);
  return v9;
}
