__int64 __fastcall aw882xx_dev_get_int_status(__int64 a1, _WORD *a2)
{
  __int64 (__fastcall *v4)(__int64, __int64, int *); // x8
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 result; // x0
  __int64 *v8; // x8
  unsigned int v9; // w19
  __int64 v10; // x1
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
  v5 = *(_QWORD *)(a1 + 120);
  v6 = *(unsigned int *)(a1 + 300);
  v11 = 0;
  if ( *((_DWORD *)v4 - 1) != 1983062130 )
    __break(0x8228u);
  result = v4(v5, v6, &v11);
  if ( (result & 0x80000000) != 0 )
  {
    v8 = *(__int64 **)(a1 + 112);
    v9 = result;
    v10 = v8[14];
    if ( !v10 )
      v10 = *v8;
    printk(&unk_28DB3, v10, "aw882xx_dev_get_int_status");
    result = v9;
  }
  else
  {
    *a2 = v11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
