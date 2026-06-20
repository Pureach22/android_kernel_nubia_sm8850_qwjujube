__int64 __fastcall qcedev_smmu_ablk_offload_cipher(__int64 a1, __int64 a2)
{
  char v4; // w26
  unsigned __int64 v5; // x8
  __int64 v6; // x21
  unsigned __int64 *v7; // x10
  unsigned __int64 v8; // x22
  unsigned __int64 v9; // x28
  __int64 v10; // x27
  __int64 v11; // x23
  unsigned int v12; // w0
  __int64 v13; // x3
  unsigned __int64 v14; // x26
  __int64 v15; // x27
  unsigned __int64 v16; // x28
  __int64 v17; // x22
  __int64 result; // x0
  unsigned int v19; // w20
  __int64 v20; // [xsp+18h] [xbp-48h] BYREF
  __int64 v21; // [xsp+20h] [xbp-40h]
  __int64 v22; // [xsp+28h] [xbp-38h]
  __int64 v23; // [xsp+30h] [xbp-30h]
  __int64 v24; // [xsp+38h] [xbp-28h] BYREF
  __int64 v25; // [xsp+40h] [xbp-20h]
  unsigned __int64 v26; // [xsp+48h] [xbp-18h]
  __int64 v27; // [xsp+50h] [xbp-10h]
  __int64 v28; // [xsp+58h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 804) == 2 )
    v4 = *(_BYTE *)(a1 + 576);
  else
    v4 = 0;
  *(_QWORD *)(a1 + 832) = &v24;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  *(_QWORD *)(a1 + 840) = &v20;
  sg_init_table(&v24, 1);
  sg_init_table(&v20, 1);
  v5 = *(unsigned int *)(a1 + 568);
  if ( !(_DWORD)v5 )
  {
LABEL_24:
    result = 0;
    goto LABEL_28;
  }
  v6 = 0;
  while ( 1 )
  {
    if ( v6 == 16 )
      __break(0x5512u);
    v7 = (unsigned __int64 *)(a1 + 56 + 16 * v6);
    v8 = *v7;
    v9 = v7[1];
    v10 = *(_QWORD *)(a1 + 312 + 16 * v6 + 8);
    *(_QWORD *)(a1 + 824) = a1 + 600;
    if ( !v8 )
      goto LABEL_7;
    if ( v8 >= 0x400000 )
      v11 = 0x400000;
    else
      v11 = v8;
    v26 = v9;
    v22 = v10;
    *(_DWORD *)(a1 + 816) = v11;
    HIDWORD(v25) = v11;
    HIDWORD(v21) = v11;
    *(_BYTE *)(a1 + 576) = v4;
    v12 = submit_req(a1, a2);
    if ( v12 )
      goto LABEL_25;
    if ( *(_DWORD *)(a1 + 812) )
      break;
    v14 = v8 - v11;
    if ( v8 != v11 )
    {
      v15 = v10 + v11;
      v16 = v9 + v11;
      while ( 1 )
      {
        v17 = v14 >= 0x400000 ? 0x400000LL : v14;
        v26 = v16;
        v22 = v15;
        *(_DWORD *)(a1 + 816) = v17;
        HIDWORD(v25) = v17;
        HIDWORD(v21) = v17;
        *(_BYTE *)(a1 + 576) = 0;
        v12 = submit_req(a1, a2);
        if ( v12 )
          break;
        if ( *(_DWORD *)(a1 + 812) )
          goto LABEL_26;
        v14 -= v17;
        v16 += v17;
        v15 += v17;
        if ( !v14 )
          goto LABEL_6;
      }
LABEL_25:
      v19 = v12;
      goto LABEL_27;
    }
LABEL_6:
    v5 = *(unsigned int *)(a1 + 568);
    v4 = 0;
LABEL_7:
    if ( ++v6 >= v5 )
      goto LABEL_24;
  }
LABEL_26:
  v19 = 0;
LABEL_27:
  printk(&unk_12C42, "qcedev_smmu_ablk_offload_cipher", v19, v13);
  result = v19;
LABEL_28:
  *(_QWORD *)(a1 + 832) = 0;
  *(_QWORD *)(a1 + 840) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
