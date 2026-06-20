__int64 __fastcall stm_char_ioctl(__int64 a1, int a2, __int64 a3)
{
  __int64 *v3; // x19
  __int64 v4; // x24
  __int64 v5; // x20
  int v6; // w8
  __int64 result; // x0
  __int64 *v8; // x0
  __int64 v9; // x1
  __int64 (__fastcall *v10)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  unsigned __int64 v16; // x22
  __int64 v17; // x21
  size_t v18; // x23
  int policy; // w22
  unsigned int v20; // w9
  unsigned int v21; // w9
  __int64 v22; // x3
  __int64 v23; // x0
  __int64 (*v24)(void); // x8
  int v25; // w0
  unsigned int v26; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v28; // x25
  __int64 v29; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v30; // [xsp+14h] [xbp-1Ch] BYREF
  _QWORD v31[3]; // [xsp+18h] [xbp-18h] BYREF

  v31[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(__int64 **)(a1 + 32);
  v4 = *v3;
  v29 = 0;
  v5 = *(_QWORD *)(v4 + 984);
  if ( a2 == -2146425599 )
  {
    v8 = v3;
    v9 = a3;
    goto LABEL_9;
  }
  if ( a2 == 1074275586 )
  {
    if ( inline_copy_from_user((int)&v29, a3, 8u) )
    {
      result = -14;
      goto LABEL_16;
    }
    v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v5 + 72);
    if ( v10 )
    {
      v11 = *((unsigned int *)v3 + 3);
      v12 = *((unsigned int *)v3 + 4);
      v13 = *((unsigned int *)v3 + 5);
      v14 = v29;
      if ( *((_DWORD *)v10 - 1) != -635111639 )
        __break(0x8228u);
      LODWORD(result) = v10(v5, v11, v12, v13, v14);
      goto LABEL_10;
    }
LABEL_15:
    result = -25;
    goto LABEL_16;
  }
  if ( a2 != -1072683776 )
    goto LABEL_15;
  v6 = *((_DWORD *)v3 + 5);
  v31[0] = 0;
  v31[1] = 0;
  if ( v6 )
  {
    result = -16;
    goto LABEL_16;
  }
  v30 = 0;
  if ( inline_copy_from_user((int)&v30, a3, 4u) )
  {
    result = -14;
    goto LABEL_16;
  }
  if ( v30 - 4112 < 0xFFFFF000 )
  {
    result = -22;
    goto LABEL_16;
  }
  v16 = v30 + 1;
  v17 = _kmalloc_noprof(v16, 3520);
  if ( !v17 )
  {
LABEL_48:
    result = -12;
    goto LABEL_16;
  }
  while ( 1 )
  {
    v18 = v30;
    if ( (v30 & 0x80000000) != 0 )
    {
      __break(0x800u);
      policy = -14;
      goto LABEL_32;
    }
    _check_object_size(v17, v30, 0);
    if ( inline_copy_from_user(v17, a3, v18) )
    {
      policy = -14;
LABEL_32:
      kfree(v17);
      result = policy;
      goto LABEL_16;
    }
    if ( v16 >= 0xA && (v16 & 0xFFFFFFFE) != 0xA )
    {
      if ( *(_WORD *)(v17 + 10) )
        goto LABEL_31;
      if ( v16 >= 0xC && (v16 & 0xFFFFFFFC) != 0xC )
      {
        if ( *(_DWORD *)(v17 + 12) )
        {
LABEL_31:
          policy = -22;
          goto LABEL_32;
        }
        v20 = *(_DWORD *)(*(_QWORD *)(v4 + 984) + 28LL);
        v21 = v20 ? 0x1000 / v20 : 1;
        if ( (v16 & 0xFFFFFFFE) != 8 )
          break;
      }
    }
    __break(1u);
    v26 = v30;
    StatusReg = _ReadStatusReg(SP_EL0);
    v28 = *(_QWORD *)(StatusReg + 80);
    v16 = v26 + 1;
    *(_QWORD *)(StatusReg + 80) = &stm_char_policy_set_ioctl__alloc_tag;
    v17 = _kmalloc_noprof(v16, 3520);
    *(_QWORD *)(StatusReg + 80) = v28;
    if ( !v17 )
      goto LABEL_48;
  }
  v22 = *(unsigned __int16 *)(v17 + 8);
  policy = -22;
  if ( !*(_WORD *)(v17 + 8) )
    goto LABEL_32;
  if ( v21 < (unsigned int)v22 )
    goto LABEL_32;
  v23 = *v3;
  v31[0] = v17 + 16;
  policy = stm_assign_first_policy(v23, v3 + 1, v31, v22);
  if ( policy )
    goto LABEL_32;
  v24 = *(__int64 (**)(void))(*(_QWORD *)(v4 + 984) + 56LL);
  if ( v24 )
  {
    if ( *((_DWORD *)v24 - 1) != 220482162 )
      __break(0x8228u);
    v25 = v24();
    if ( v25 )
    {
      policy = v25;
      stm_output_free(*v3, v3 + 1);
      goto LABEL_32;
    }
  }
  kfree(v17);
  v8 = v3;
  v9 = a3;
LABEL_9:
  LODWORD(result) = stm_char_policy_get_ioctl(v8, v9);
LABEL_10:
  result = (int)result;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
