__int64 __fastcall aw882xx_dev_set_intmask(__int64 a1, char a2)
{
  __int64 *v3; // x8
  __int64 v4; // x1
  __int64 v5; // x8
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x9
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  unsigned int v10; // w0
  __int64 *v11; // x8
  unsigned int v12; // w19
  __int64 v13; // x1

  if ( *(_DWORD *)a1 || (a2 & 1) == 0 )
  {
    if ( (a2 & 1) != 0 )
    {
      v5 = 308;
      goto LABEL_9;
    }
  }
  else
  {
    v3 = *(__int64 **)(a1 + 112);
    v4 = v3[14];
    if ( !v4 )
      v4 = *v3;
    printk(&unk_269D9, v4, "aw882xx_dev_set_intmask");
  }
  v5 = 304;
LABEL_9:
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
  v7 = *(_QWORD *)(a1 + 120);
  v8 = *(unsigned int *)(a1 + 296);
  v9 = *(unsigned int *)(a1 + v5);
  if ( *((_DWORD *)v6 - 1) != -1860236611 )
    __break(0x8229u);
  v10 = v6(v7, v8, v9);
  v11 = *(__int64 **)(a1 + 112);
  v12 = v10;
  v13 = v11[14];
  if ( !v13 )
    v13 = *v11;
  printk(&unk_22D82, v13, "aw882xx_dev_set_intmask");
  return v12;
}
