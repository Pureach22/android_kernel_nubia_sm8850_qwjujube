__int64 __fastcall hfi_setup_ucsc_cscv1(__int64 a1, int a2, __int64 *a3)
{
  __int64 v4; // x9
  unsigned int v5; // w1
  int v6; // w10
  int v7; // w10
  __int64 result; // x0
  __int64 v9; // [xsp+0h] [xbp-60h] BYREF
  __int64 v10; // [xsp+8h] [xbp-58h]
  __int64 v11; // [xsp+10h] [xbp-50h]
  __int64 v12; // [xsp+18h] [xbp-48h]
  __int64 v13; // [xsp+20h] [xbp-40h]
  __int64 v14; // [xsp+28h] [xbp-38h]
  __int64 v15; // [xsp+30h] [xbp-30h]
  __int64 v16; // [xsp+38h] [xbp-28h]
  __int64 v17; // [xsp+40h] [xbp-20h]
  __int64 v18; // [xsp+48h] [xbp-18h]
  int v19; // [xsp+50h] [xbp-10h]
  __int64 v20; // [xsp+58h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  if ( a2 != 3 && a1 && a3 )
  {
    v4 = *a3;
    v5 = a3[20] & 0xFF0F0FFF | 0x101000;
    *((_DWORD *)a3 + 40) = v5;
    if ( v4 )
    {
      if ( *((_DWORD *)a3 + 2) != 96 )
      {
        result = printk(&unk_276A53, *(unsigned int *)(a1 + 48));
        goto LABEL_9;
      }
      v6 = *(_DWORD *)(v4 + 12);
      LODWORD(v9) = 1;
      HIDWORD(v9) = v6;
      v7 = *(_DWORD *)(v4 + 64);
      v10 = *(_QWORD *)(v4 + 16);
      v11 = *(_QWORD *)(v4 + 24);
      v12 = *(_QWORD *)(v4 + 32);
      v13 = *(_QWORD *)(v4 + 40);
      v14 = *(_QWORD *)(v4 + 48);
      LODWORD(v15) = *(_DWORD *)(v4 + 56);
      HIDWORD(v15) = v7;
      v16 = *(_QWORD *)(v4 + 68);
      v17 = *(_QWORD *)(v4 + 76);
      v18 = *(_QWORD *)(v4 + 84);
      v19 = *(_DWORD *)(v4 + 92);
    }
    result = hfi_util_u32_prop_helper_add_prop_by_obj((int *)a3[19], v5, *((_DWORD *)a3 + 41), 2, &v9, 0x54u);
    if ( (_DWORD)result )
      result = printk(&unk_245DDA, *((unsigned int *)a3 + 40));
  }
  else
  {
    result = printk(&unk_223E61, a1);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
