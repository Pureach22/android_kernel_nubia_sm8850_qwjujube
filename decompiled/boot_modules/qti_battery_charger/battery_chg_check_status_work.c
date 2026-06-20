__int64 __fastcall battery_chg_check_status_work(__int64 a1)
{
  int *v1; // x21
  __int64 v2; // x20
  int v4; // w9
  __int64 result; // x0
  __int64 v6; // x22
  int v7; // w10
  int v8; // w10
  __int64 v9; // x2
  __int64 v10; // x2
  __int64 v11; // x2
  void *v12; // x0
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  int v14; // [xsp+8h] [xbp-18h]
  __int64 v15; // [xsp+Ch] [xbp-14h]
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v1 = (int *)(a1 - 620);
  v2 = a1 - 1008;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 - 620);
  v15 = 0;
  v16 = 0;
  v13 = 0x10000800ALL;
  v14 = v4;
  result = battery_chg_write(a1 - 1008, (__int64)&v13, 0x18u, 0x3E8u);
  if ( (result & 0x80000000) != 0 )
  {
    v11 = (unsigned int)result;
    v12 = &unk_10DDE;
LABEL_11:
    result = printk(v12, "battery_chg_check_status_work", v11);
    goto LABEL_12;
  }
  v6 = a1 - 632;
  if ( **(_DWORD **)(a1 - 632) == 1 )
    goto LABEL_12;
  v7 = *v1;
  v16 = 0;
  v15 = 0x400000000LL;
  v13 = 0x10000800ALL;
  v14 = v7;
  result = battery_chg_write(v2, (__int64)&v13, 0x18u, 0x3E8u);
  if ( (result & 0x80000000) != 0 )
  {
    v11 = (unsigned int)result;
    v12 = &unk_11618;
    goto LABEL_11;
  }
  if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)v6 + 16LL) + 50) > 0x63 )
    goto LABEL_12;
  v8 = *v1;
  v16 = 0;
  v15 = 0x700000000LL;
  v13 = 0x10000800ALL;
  v14 = v8;
  result = battery_chg_write(v2, (__int64)&v13, 0x18u, 0x3E8u);
  if ( (result & 0x80000000) != 0 )
  {
    v11 = (unsigned int)result;
    v12 = &unk_11303;
    goto LABEL_11;
  }
  if ( *(_DWORD *)(*(_QWORD *)v6 + 28LL) / 0x3E8u <= *(_DWORD *)(a1 - 456) )
  {
    printk(&unk_11D8F, "battery_chg_check_status_work", v9);
    msleep(100);
    result = printk(&unk_11DC3, "battery_chg_check_status_work", v10);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
