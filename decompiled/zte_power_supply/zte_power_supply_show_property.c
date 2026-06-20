__int64 __fastcall zte_power_supply_show_property(__int64 a1, __int64 a2, char *s)
{
  __int64 v5; // x1
  unsigned int v6; // w2
  __int64 result; // x0
  int v9; // w8
  __int64 v11; // x20

  _ReadStatusReg(SP_EL0);
  v5 = -1171354717 * (unsigned int)((unsigned __int64)(a2 - (_QWORD)&zte_power_supply_attrs - 40) >> 3);
  if ( (_DWORD)v5 == 64 )
  {
    v6 = *(_DWORD *)(**(_QWORD **)(a1 + 152) + 8LL);
    goto LABEL_5;
  }
  LODWORD(result) = zte_power_supply_get_property(*(_QWORD *)(a1 + 152), v5);
  if ( (result & 0x80000000) == 0 )
  {
    v6 = 0;
LABEL_5:
    v9 = *(_DWORD *)(a2 + 40);
    if ( v9 < 1 || v6 >= v9 )
      LODWORD(result) = sprintf(s, "%d\n", v6);
    else
      LODWORD(result) = sprintf(s, "%s\n", *(const char **)(*(_QWORD *)(a2 + 32) + 8LL * v6));
    result = (int)result;
    goto LABEL_10;
  }
  result = (int)result;
  if ( (unsigned int)(result + 61) > 0x32 || ((1LL << ((unsigned __int8)result + 61)) & 0x4040000000001LL) == 0 )
  {
    v11 = (int)result;
    if ( (unsigned int)__ratelimit(&zte_power_supply_show_property__rs, "zte_power_supply_show_property") )
      dev_err(a1, "driver failed to report `%s' property: %zd\n", *(const char **)a2, v11);
    result = v11;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
