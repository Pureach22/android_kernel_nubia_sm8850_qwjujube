__int64 __fastcall hfi_setup_ucsc_unmultv1(__int64 a1, int a2, __int64 a3)
{
  _BYTE *v4; // x3
  unsigned int v5; // w1
  __int64 result; // x0
  int src; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  src = 0;
  if ( a2 != 3 && a1 && a3 )
  {
    v4 = *(_BYTE **)a3;
    if ( *(_QWORD *)a3 && *(_DWORD *)(a3 + 8) == 1 )
    {
      v5 = *(_DWORD *)(a3 + 160) & 0xFF0F0FFF | 0x101000;
      *(_DWORD *)(a3 + 160) = v5;
      if ( *v4 == 1 )
        src = 1;
      result = hfi_util_u32_prop_helper_add_prop_by_obj(*(int **)(a3 + 152), v5, *(_DWORD *)(a3 + 164), 0, &src, 4u);
      if ( (_DWORD)result )
        result = printk(&unk_245DDA, *(unsigned int *)(a3 + 160));
    }
    else
    {
      result = printk(&unk_25333A, *(unsigned int *)(a1 + 48));
    }
  }
  else
  {
    result = printk(&unk_223E61, a1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
