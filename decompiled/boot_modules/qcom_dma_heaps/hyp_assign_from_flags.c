__int64 __fastcall hyp_assign_from_flags(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned __int64 v6; // x23
  __int64 v7; // x22
  __int64 v8; // x8
  __int64 v9; // x9
  signed int v10; // w11
  __int64 v11; // x4
  unsigned __int64 v12; // x12
  _DWORD *v13; // x10
  int v14; // w12
  unsigned int v15; // w20
  __int64 v16; // x8
  unsigned __int64 StatusReg; // x24
  __int64 v18; // x25
  __int64 v19; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v20; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-18h] BYREF
  __int64 v22[2]; // [xsp+20h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v21 = 0;
  v20 = 0;
  v19 = 8;
  result = get_vmperm_from_ion_flags(a3, v22, &v21, &v20);
  if ( !(_DWORD)result )
  {
    v6 = 8LL * v20;
    v7 = _kmalloc_noprof(v6, 3520);
    if ( v7 )
    {
      while ( v20 )
      {
        v8 = v22[0];
        v9 = v21;
        v10 = 0;
        v11 = v20;
        while ( 1 )
        {
          v12 = 8LL * v10;
          if ( v6 <= v12 )
            break;
          v13 = (_DWORD *)(v7 + 8LL * v10);
          *v13 = *(_DWORD *)(v8 + 4LL * v10);
          if ( v6 < (v12 | 4) )
            break;
          v14 = *(_DWORD *)(v9 + 4LL * v10++);
          v13[1] = v14;
          if ( v10 >= (unsigned int)v11 )
            goto LABEL_10;
        }
        __break(1u);
        v16 = v20;
        StatusReg = _ReadStatusReg(SP_EL0);
        v18 = *(_QWORD *)(StatusReg + 80);
        v6 = 8 * v16;
        *(_QWORD *)(StatusReg + 80) = &hyp_assign_from_flags__alloc_tag;
        v7 = _kmalloc_noprof(8 * v16, 3520);
        *(_QWORD *)(StatusReg + 80) = v18;
        if ( !v7 )
          goto LABEL_14;
      }
      v11 = 0;
LABEL_10:
      v15 = qcom_scm_assign_mem(a1, a2, &v19, v7, v11);
      if ( v15 )
        printk(&unk_E142, "hyp_assign_from_flags");
      kfree(v7);
    }
    else
    {
LABEL_14:
      v15 = -12;
    }
    kfree(v21);
    kfree(v22[0]);
    result = v15;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
