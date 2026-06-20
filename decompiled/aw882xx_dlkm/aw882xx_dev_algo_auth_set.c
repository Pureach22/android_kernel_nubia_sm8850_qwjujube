__int64 __fastcall aw882xx_dev_algo_auth_set(__int64 a1, _DWORD *a2)
{
  __int64 *v4; // x8
  __int64 v5; // x1
  int v6; // w8
  int v7; // w8
  __int64 result; // x0
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x0
  __int64 (__fastcall *v11)(__int64, __int64, int *); // x8
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 *v14; // x8
  unsigned int v15; // w20
  __int64 v16; // x1
  __int64 *v17; // x8
  __int64 v18; // x1
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(a1 + 112);
  v19 = 0;
  v5 = v4[14];
  if ( !v5 )
    v5 = *v4;
  printk(&unk_2708B, v5, "aw882xx_dev_algo_auth_set");
  *(_DWORD *)(a1 + 1116) = *a2;
  v6 = a2[2];
  *(_DWORD *)(a1 + 1128) = 16727;
  *(_DWORD *)(a1 + 1124) = v6;
  *(_DWORD *)(a1 + 1132) = a2[4];
  if ( *a2 == 2 )
  {
    if ( *(_BYTE *)(a1 + 1112) && *(_BYTE *)(a1 + 1113) )
    {
      v9 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1152);
      v10 = *(_QWORD *)(a1 + 120);
      if ( *((_DWORD *)v9 - 1) != -1860236611 )
        __break(0x8228u);
      LODWORD(result) = v9(v10);
      if ( (result & 0x80000000) == 0 )
      {
        v11 = *(__int64 (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
        v12 = *(_QWORD *)(a1 + 120);
        v13 = *(unsigned __int8 *)(a1 + 1113);
        if ( *((_DWORD *)v11 - 1) != 1983062130 )
          __break(0x8228u);
        result = v11(v12, v13, &v19);
        if ( (result & 0x80000000) == 0 )
          goto LABEL_19;
      }
    }
    else
    {
      LODWORD(result) = -22;
    }
    v14 = *(__int64 **)(a1 + 112);
    v15 = result;
    v16 = v14[14];
    if ( !v16 )
      v16 = *v14;
    printk(&unk_26D9C, v16, "aw882xx_dev_algo_auth_set");
    result = v15;
LABEL_19:
    v7 = v19;
    goto LABEL_20;
  }
  if ( *a2 == 1 )
  {
    v7 = a2[1];
    result = 0;
LABEL_20:
    *(_DWORD *)(a1 + 1120) = v7;
    goto LABEL_21;
  }
  v17 = *(__int64 **)(a1 + 112);
  v18 = v17[14];
  if ( !v18 )
    v18 = *v17;
  printk(&unk_2329C, v18, "aw882xx_dev_algo_auth_set");
  result = 4294967274LL;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
