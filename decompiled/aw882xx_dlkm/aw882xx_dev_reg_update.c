__int64 __fastcall aw882xx_dev_reg_update(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 *v4; // x8
  __int64 v5; // x1
  void (__fastcall *v6)(__int64, __int64, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 *v10; // x8
  __int64 v11; // x1

  if ( (a2 & 1) != 0 )
  {
    v6 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
    v7 = *(_QWORD *)(a1 + 120);
    v8 = *(unsigned int *)(a1 + 928);
    v9 = *(unsigned int *)(a1 + 932);
    if ( *((_DWORD *)v6 - 1) != -1860236611 )
      __break(0x8228u);
    v6(v7, v8, v9);
    v10 = *(__int64 **)(a1 + 112);
    v11 = v10[14];
    if ( !v11 )
      v11 = *v10;
    printk(&unk_274D3, v11, "aw_dev_soft_reset");
LABEL_3:
    result = aw_dev_reg_fw_update(a1);
    if ( (result & 0x80000000) != 0 )
      return result;
    goto LABEL_4;
  }
  if ( *(unsigned __int8 *)(a1 + 48) != *(unsigned __int8 *)(a1 + 49) )
    goto LABEL_3;
LABEL_4:
  v4 = *(__int64 **)(a1 + 112);
  *(_BYTE *)(a1 + 48) = *(_BYTE *)(a1 + 49);
  v5 = v4[14];
  if ( !v5 )
    v5 = *v4;
  printk(&unk_22D82, v5, "aw882xx_dev_reg_update");
  return 0;
}
