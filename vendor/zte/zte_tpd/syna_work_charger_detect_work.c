__int64 __fastcall syna_work_charger_detect_work(__int64 result, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x19
  __int64 v4; // x9
  __int64 v5; // x23
  unsigned int v6; // w20
  __int64 v7; // x0
  void (*v8)(void); // x8
  int v9; // w8
  char v10; // w8

  v3 = (_QWORD *)(result - 1568);
  _ReadStatusReg(SP_EL0);
  if ( result == 1568 )
    goto LABEL_2;
  v4 = *(_QWORD *)(result - 944);
  if ( *(_DWORD *)(v4 + 184) && (*(_BYTE *)(v4 + 188) & 1) != 0 )
  {
    v5 = result;
    v6 = 0;
  }
  else
  {
    v6 = *(_DWORD *)(*v3 + 524LL);
    v5 = result;
  }
  printk(unk_35219, "syna_work_charger_detect_work", a3);
  v7 = syna_get_charger_status_batt_psy;
  if ( syna_get_charger_status_batt_psy
    || (v7 = power_supply_get_by_name("battery"), (syna_get_charger_status_batt_psy = v7) != 0) )
  {
    v8 = *(void (**)(void))(*(_QWORD *)v7 + 40LL);
    if ( *((_DWORD *)v8 - 1) != -392622893 )
      __break(0x8228u);
    v8();
    result = printk(unk_3A676, "syna_get_charger_status", 0);
    syna_usb_detect_flag = 0;
  }
  else
  {
    result = printk(unk_3A676, "syna_get_charger_status", 0);
    syna_usb_detect_flag = 0;
  }
  v9 = *(_DWORD *)(v5 - 164);
  if ( v9 == 1 && (syna_work_charger_detect_work_status & 1) != 0 )
  {
    result = syna_dev_set_charger_mode(v3, 0, v6);
LABEL_16:
    syna_work_charger_detect_work_status = 0;
    goto LABEL_2;
  }
  if ( v9 == 1 )
    v10 = 0;
  else
    v10 = syna_work_charger_detect_work_status;
  if ( (v10 & 1) != 0 )
    goto LABEL_16;
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
