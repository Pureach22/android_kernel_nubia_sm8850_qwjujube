__int64 __fastcall aw882xx_dev_clear_int_status(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64, __int64, int *); // x8
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 *v5; // x8
  __int64 v6; // x1
  __int64 (__fastcall *v7)(__int64, __int64, int *); // x8
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 *v10; // x8
  __int64 v11; // x1
  __int64 *v12; // x8
  __int64 v13; // x1
  __int64 result; // x0
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
  v3 = *(_QWORD *)(a1 + 120);
  v4 = *(unsigned int *)(a1 + 300);
  v15 = 0;
  if ( *((_DWORD *)v2 - 1) != 1983062130 )
    __break(0x8228u);
  if ( (v2(v3, v4, &v15) & 0x80000000) != 0 )
  {
    v5 = *(__int64 **)(a1 + 112);
    v6 = v5[14];
    if ( !v6 )
      v6 = *v5;
    printk(&unk_28DB3, v6, "aw882xx_dev_get_int_status");
  }
  v7 = *(__int64 (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
  v8 = *(_QWORD *)(a1 + 120);
  v9 = *(unsigned int *)(a1 + 300);
  v15 = 0;
  if ( *((_DWORD *)v7 - 1) != 1983062130 )
    __break(0x8228u);
  if ( (v7(v8, v9, &v15) & 0x80000000) != 0 )
  {
    v10 = *(__int64 **)(a1 + 112);
    v11 = v10[14];
    if ( !v11 )
      v11 = *v10;
    printk(&unk_28DB3, v11, "aw882xx_dev_get_int_status");
  }
  v12 = *(__int64 **)(a1 + 112);
  v13 = v12[14];
  if ( !v13 )
    v13 = *v12;
  result = printk(&unk_22D82, v13, "aw882xx_dev_clear_int_status");
  _ReadStatusReg(SP_EL0);
  return result;
}
