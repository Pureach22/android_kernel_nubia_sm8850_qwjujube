__int64 __fastcall charger_policy_cap_max_set(const char *a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v6; // x2
  __int64 v7; // x3
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  if ( a2 )
  {
    sscanf(a1, "%d", &v8);
    v6 = v8;
    a2[106] = 0;
    a2[104] = v6;
    a2[102] = v6;
    printk(&unk_9040, "charger_policy_cap_max_set", v6, v7);
    result = 0;
  }
  else
  {
    printk(&unk_9AE6, "charger_policy_cap_max_set", a3, a4);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
