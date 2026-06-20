__int64 __fastcall reg_dmav1_setup_pre_downscale(__int64 a1, __int64 a2, int *a3)
{
  __int64 result; // x0
  __int64 v7; // x21
  __int64 ops; // x0
  __int64 v9; // x1
  int v10; // w9
  int v11; // w10
  int v12; // w12
  int v13; // w13
  int v14; // w14
  int v15; // w11
  int v16; // w9
  __int64 (__fastcall *v17)(_QWORD); // x10
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  result = 4294967274LL;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || !a3 )
    goto LABEL_7;
  v7 = a1;
  ops = sde_reg_dma_get_ops(*(unsigned int *)(a2 + 1392));
  if ( !ops )
  {
    printk(&unk_235B78, v9);
LABEL_10:
    result = 4294967274LL;
    goto LABEL_7;
  }
  v10 = *a3;
  v11 = a3[1];
  v12 = a3[2];
  v13 = a3[3];
  v14 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 48LL) + 72LL);
  *(_DWORD *)v7 = 1;
  v15 = *(_DWORD *)(a2 + 8);
  *(_QWORD *)(v7 + 12) = 0;
  v16 = v10 | (16 * v11) | (v12 << 8);
  *(_DWORD *)(v7 + 20) = v14 + v15 + 4168;
  *(_QWORD *)(v7 + 32) = &v18;
  *(_QWORD *)(v7 + 40) = 0x400000000LL;
  v17 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
  v18 = v16 | (v13 << 12);
  if ( *((_DWORD *)v17 - 1) != -1839634494 )
    __break(0x822Au);
  result = v17(v7);
  if ( (_DWORD)result )
  {
    printk(&unk_2214F0, (unsigned int)result);
    goto LABEL_10;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
