__int64 __fastcall aw882xx_dev_check_ef_lock(__int64 a1)
{
  int v1; // w8
  void (__fastcall *v3)(__int64, __int64, int *); // x9
  __int64 v4; // x1
  __int64 v6; // x0
  __int64 *v7; // x9
  __int64 v8; // x1
  __int64 v9; // x0
  void (__fastcall *v10)(__int64, __int64, int *); // x9
  __int64 v11; // x1
  __int64 *v12; // x8
  __int64 v13; // x1
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 216);
  v14 = 0;
  if ( v1 )
  {
    v3 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
    v4 = *(unsigned int *)(a1 + 220);
    v6 = *(_QWORD *)(a1 + 120);
    if ( *((_DWORD *)v3 - 1) != 1983062130 )
      __break(0x8229u);
    v3(v6, v4, &v14);
    v7 = *(__int64 **)(a1 + 112);
    v8 = v7[14];
    if ( !v8 )
      v8 = *v7;
    printk(&unk_28237, v8, "aw882xx_dev_check_ef_lock");
    if ( *(_DWORD *)(a1 + 216) >= 2u )
    {
      v9 = *(_QWORD *)(a1 + 120);
      v10 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
      v11 = *(unsigned int *)(a1 + 232);
      if ( *((_DWORD *)v10 - 1) != 1983062130 )
        __break(0x8229u);
      v10(v9, v11, &v14);
      v12 = *(__int64 **)(a1 + 112);
      v13 = v12[14];
      if ( !v13 )
        v13 = *v12;
      printk(&unk_28237, v13, "aw882xx_dev_check_ef_lock");
      if ( *(_DWORD *)(a1 + 216) > 2u )
        __break(0x5512u);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
