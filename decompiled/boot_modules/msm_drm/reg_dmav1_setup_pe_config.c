__int64 __fastcall reg_dmav1_setup_pe_config(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 ops; // x0
  __int64 v7; // x1
  int v8; // w9
  int v9; // w12
  int v10; // w10
  int v11; // w28
  int v12; // w23
  __int64 v13; // x20
  int v14; // w8
  int v15; // w15
  int v16; // w27
  int v17; // w11
  int v18; // w14
  int v19; // w24
  int v20; // w13
  int v21; // w25
  int v22; // w22
  int v23; // w16
  unsigned int v24; // w8
  int v25; // w9
  __int64 (__fastcall *v26)(_QWORD); // x10
  __int64 result; // x0
  int v28; // w10
  __int64 (__fastcall *v29)(_QWORD); // x10
  unsigned int v30; // w19
  int v31; // [xsp+4h] [xbp-1Ch]
  int v32; // [xsp+8h] [xbp-18h]
  int v33; // [xsp+Ch] [xbp-14h]
  int v34; // [xsp+10h] [xbp-10h] BYREF
  int v35; // [xsp+14h] [xbp-Ch]
  __int64 v36; // [xsp+18h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
    goto LABEL_11;
  ops = sde_reg_dma_get_ops(*(unsigned int *)(a2 + 1392));
  if ( !ops )
  {
    printk(&unk_235B78, v7);
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v8 = *(unsigned __int8 *)(a3 + 196);
  v9 = *(_DWORD *)(a3 + 212);
  v10 = *(unsigned __int8 *)(a3 + 228);
  v11 = *(_DWORD *)(a3 + 152);
  v12 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 48LL) + 72LL);
  v13 = ops;
  v14 = *(_DWORD *)(a3 + 132);
  v15 = *(_DWORD *)(a3 + 164);
  v16 = *(_DWORD *)(a3 + 168);
  v17 = *(_DWORD *)(a3 + 148) << 24;
  v31 = *(_DWORD *)(a3 + 136);
  v32 = *(_DWORD *)(a3 + 216);
  v18 = *(_DWORD *)(a3 + 244);
  v19 = *(_DWORD *)(a3 + 248);
  v33 = *(unsigned __int8 *)(a3 + 200);
  v20 = *(_DWORD *)(a3 + 180);
  v21 = *(_DWORD *)(a3 + 184);
  v22 = *(unsigned __int8 *)(a3 + 232);
  *(_DWORD *)a1 = 2;
  v23 = *(_DWORD *)(a2 + 8);
  *(_QWORD *)(a1 + 12) = 0;
  *(_QWORD *)(a1 + 32) = &v34;
  *(_QWORD *)(a1 + 40) = 0x800000000LL;
  v24 = v17 & 0xFF0000FF | ((unsigned __int8)v9 << 16) | ((unsigned __int8)v14 << 8) | v8;
  *(_DWORD *)(a1 + 20) = v12 + v23 + 4132;
  v25 = (v20 << 24) | ((unsigned __int8)v18 << 16) | ((unsigned __int8)v15 << 8) | v10;
  v26 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
  v34 = v24;
  v35 = v25;
  if ( *((_DWORD *)v26 - 1) != -1839634494 )
    __break(0x822Au);
  LODWORD(result) = v26(a1);
  if ( (_DWORD)result )
    goto LABEL_9;
  *(_DWORD *)a1 = 2;
  v28 = *(_DWORD *)(a2 + 8);
  *(_QWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 20) = v12 + v28 + 4160;
  *(_QWORD *)(a1 + 32) = &v34;
  *(_QWORD *)(a1 + 40) = 0x800000000LL;
  v29 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
  v34 = (v11 << 24) | ((unsigned __int8)v32 << 16) | ((unsigned __int8)v31 << 8) | v33;
  v35 = (v21 << 24) | ((unsigned __int8)v19 << 16) | ((unsigned __int8)v16 << 8) | v22;
  if ( *((_DWORD *)v29 - 1) != -1839634494 )
    __break(0x822Au);
  result = v29(a1);
  if ( (_DWORD)result )
  {
LABEL_9:
    v30 = result;
    printk(&unk_227E35, (unsigned int)result);
    result = v30;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
