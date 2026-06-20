__int64 __fastcall hfi_setup_ucsc_gcv1(__int64 a1, int a2, __int64 a3)
{
  unsigned int *v4; // x3
  int v5; // w4
  unsigned int v6; // w1
  unsigned int v7; // w8
  __int64 result; // x0
  unsigned int src; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 3 || !a1 || !a3 )
  {
    result = printk(&unk_223E61, a1);
    goto LABEL_20;
  }
  v4 = *(unsigned int **)a3;
  v5 = *(_DWORD *)(a3 + 8);
  v6 = *(_DWORD *)(a3 + 160) & 0xFF0F0FFF | 0x101000;
  *(_DWORD *)(a3 + 160) = v6;
  if ( !v4 || v5 != 4 )
  {
    result = printk(&unk_25333A, *(unsigned int *)(a1 + 48));
    goto LABEL_20;
  }
  v7 = *v4;
  if ( (int)*v4 > 1 )
  {
    switch ( v7 )
    {
      case 2u:
        v7 = 4;
        goto LABEL_17;
      case 3u:
        v7 = 2;
        goto LABEL_17;
      case 4u:
        v7 = 3;
        goto LABEL_17;
    }
LABEL_13:
    result = printk(&unk_2427C4, v7);
    goto LABEL_20;
  }
  if ( !v7 )
  {
    src = 0;
    goto LABEL_18;
  }
  if ( v7 != 1 )
    goto LABEL_13;
LABEL_17:
  src = v7;
LABEL_18:
  result = hfi_util_u32_prop_helper_add_prop_by_obj(*(int **)(a3 + 152), v6, *(_DWORD *)(a3 + 164), 0, &src, 4u);
  if ( (_DWORD)result )
    result = printk(&unk_245DDA, *(unsigned int *)(a3 + 160));
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
