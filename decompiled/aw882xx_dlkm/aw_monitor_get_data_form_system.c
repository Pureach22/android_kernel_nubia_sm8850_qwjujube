__int64 __fastcall aw_monitor_get_data_form_system(__int64 a1, _DWORD *a2, unsigned int a3)
{
  __int64 v6; // x0
  __int64 result; // x0
  __int64 *v8; // x8
  __int64 v9; // x1
  __int64 *v10; // x8
  __int64 v11; // x1
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13[0] = 0x79726574746162LL;
  v6 = power_supply_get_by_name(v13);
  if ( !v6 )
  {
    v8 = *(__int64 **)(a1 + 112);
    v9 = v8[14];
    if ( !v9 )
      v9 = *v8;
    printk(&unk_23934, v9, "aw_monitor_get_data_form_system");
    goto LABEL_11;
  }
  if ( (power_supply_get_property(v6, a3, &v12) & 0x80000000) != 0 )
  {
    v10 = *(__int64 **)(a1 + 112);
    v11 = v10[14];
    if ( !v11 )
      v11 = *v10;
    printk(&unk_28A82, v11, "aw_monitor_get_data_form_system");
LABEL_11:
    result = 4294967274LL;
    goto LABEL_4;
  }
  result = 0;
  *a2 = v12;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
