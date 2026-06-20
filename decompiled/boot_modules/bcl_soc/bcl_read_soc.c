__int64 __fastcall bcl_read_soc(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  unsigned int v4; // w19
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a2 = 0;
  result = bcl_read_soc_batt_psy;
  v5[0] = 0;
  if ( bcl_read_soc_batt_psy || (result = power_supply_get_by_name("battery"), (bcl_read_soc_batt_psy = result) != 0) )
  {
    result = power_supply_get_property(result, 47, v5);
    if ( (_DWORD)result )
    {
      v4 = result;
      printk(&unk_66E8, "bcl_soc", "bcl_read_soc", (unsigned int)result);
      result = v4;
    }
    else
    {
      *a2 = 100 - LODWORD(v5[0]);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
