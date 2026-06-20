__int64 __fastcall reg_dmav1_rc_write(__int64 a1, int a2, int a3, __int64 a4, unsigned int a5)
{
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w11
  __int64 v8; // x8
  int v9; // w8
  __int64 v10; // x10
  unsigned __int64 v11; // x9
  __int64 (__fastcall *v12)(_QWORD); // x10
  __int64 result; // x0
  _DWORD v14[3]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v15; // [xsp+Ch] [xbp-44h]
  int v16; // [xsp+14h] [xbp-3Ch]
  unsigned __int64 v17; // [xsp+18h] [xbp-38h]
  int *v18; // [xsp+20h] [xbp-30h]
  __int64 v19; // [xsp+28h] [xbp-28h]
  __int64 v20; // [xsp+30h] [xbp-20h]
  __int64 v21; // [xsp+38h] [xbp-18h]
  int v22; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+48h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  v6 = *(unsigned int *)(a1 + 64);
  v7 = *(_DWORD *)(a1 + 8);
  v22 = a3;
  v8 = *(_QWORD *)(v5 + 48);
  v20 = 0;
  v21 = 0;
  v14[1] = 0x80000000;
  v14[2] = a5;
  v9 = *(_DWORD *)(v8 + 524);
  if ( (unsigned int)v6 >= 5 || (v10 = *(unsigned int *)(a1 + 1496), (unsigned int)v10 > 1) )
  {
    __break(0x5512u);
LABEL_10:
    __break(1u);
  }
  if ( ((16 * v6 + 80LL * a5) | (unsigned __int64)(8 * v10)) > 0x7CF )
    goto LABEL_10;
  v15 = 0;
  v16 = v7 + a2 + v9;
  v14[0] = 1;
  v11 = dspp_buf[10 * a5 + 2 * v6 + v10];
  v12 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  v17 = v11;
  v18 = &v22;
  v19 = 0x400000000LL;
  if ( *((_DWORD *)v12 - 1) != -1839634494 )
    __break(0x822Au);
  result = v12(v14);
  if ( (_DWORD)result )
    result = printk(&unk_27AAB6, (unsigned int)result);
  _ReadStatusReg(SP_EL0);
  return result;
}
