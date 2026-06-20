__int64 __fastcall zte_power_supply_store_property(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w1
  int *v8; // x20
  int matched; // w0
  int v10; // w8
  __int64 result; // x0
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  __int64 v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD *)(a2 + 40);
  v8 = *(int **)(a1 + 152);
  v13 = 0;
  if ( v7 < 1 || (matched = _sysfs_match_string(*(_QWORD *)(a2 + 32)), matched < 0) )
  {
    v12 = 0;
    LODWORD(result) = kstrtoll(a3, 10, &v12);
    if ( (result & 0x80000000) != 0 )
    {
      result = (int)result;
      goto LABEL_10;
    }
    v10 = v12;
  }
  else
  {
    v10 = matched;
  }
  LODWORD(v13) = v10;
  LODWORD(result) = zte_power_supply_set_property(
                      v8,
                      -1171354717 * (unsigned int)((unsigned __int64)(a2 - (_QWORD)&zte_power_supply_attrs - 40) >> 3));
  if ( (int)result >= 0 )
    result = a4;
  else
    result = (int)result;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
