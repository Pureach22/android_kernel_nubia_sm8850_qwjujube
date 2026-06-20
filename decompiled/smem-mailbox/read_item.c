__int64 __fastcall read_item(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  unsigned __int64 v6; // x0
  int v7; // w10
  unsigned __int64 v8; // x20
  unsigned int *v9; // x11
  __int64 v10; // x8
  unsigned int v11; // w23
  _DWORD *v12; // x24
  unsigned int v13; // w9
  __int64 v14; // x25
  unsigned int *v15; // x1
  unsigned __int64 v16; // x8
  __int64 v17; // x9
  __int64 result; // x0
  __int64 v19; // x8
  unsigned int v20; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-18h] BYREF
  int v22; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v6 = qcom_smem_get(1, 655, &v21);
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_73B6);
    result = 0;
    goto LABEL_8;
  }
  v7 = *(_DWORD *)(a1 + 24);
  v8 = v6;
  v9 = (unsigned int *)(v6 + *(unsigned int *)(a1 + 20));
  v11 = *v9;
  v10 = v9[1];
  v12 = v9 + 2;
  v13 = v10 + a3;
  v20 = v9[1];
  v14 = v13 - v7;
  v22 = v13 - v7;
  if ( (int)v14 < 1 )
  {
    if ( v13 <= v11 )
    {
      _memcpy_fromio(a2, (char *)v12 + v10, a3);
      v17 = *(unsigned int *)(a1 + 20);
      v15 = &v20;
      v20 += a3;
      v16 = v8 + v17;
      goto LABEL_7;
    }
LABEL_10:
    printk(&unk_761A);
    v19 = *(unsigned int *)(a1 + 20);
    v20 = v11;
    _memcpy_toio(v8 + v19 + 4, &v20, 4);
    result = 0;
    goto LABEL_8;
  }
  if ( (unsigned int)v14 > v11 )
    goto LABEL_10;
  _memcpy_fromio(a2, (char *)v12 + v10, a3 - (int)v14);
  _memcpy_fromio(a2 + a3 - (int)v14, v12, v14);
  v15 = (unsigned int *)&v22;
  v16 = v8 + *(unsigned int *)(a1 + 20);
LABEL_7:
  _memcpy_toio(v16 + 4, v15, 4);
  result = 1;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
