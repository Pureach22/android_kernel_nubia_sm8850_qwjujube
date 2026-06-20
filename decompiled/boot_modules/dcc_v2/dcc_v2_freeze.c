__int64 __fastcall dcc_v2_freeze(__int64 a1)
{
  __int64 v1; // x23
  unsigned int v2; // w8
  _BYTE *v3; // x9
  __int64 v4; // x21
  unsigned __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x19
  __int64 v8; // x24
  unsigned int variable_u32_array; // w0
  __int64 v10; // x0
  unsigned __int64 v11; // x22
  __int64 v12; // x0
  unsigned __int64 v13; // x9
  __int64 v14; // x10
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x11
  bool v17; // cf
  __int64 v18; // x8
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x11
  __int64 v21; // x13
  int v22; // w12
  __int64 v23; // x13
  int v25; // w10
  int v26; // w11
  unsigned int v27; // w20
  unsigned __int64 StatusReg; // x24
  __int64 v29; // x25

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_DWORD *)(v1 + 328);
  if ( !v2 )
    return 0;
  v3 = *(_BYTE **)(v1 + 120);
  if ( (*v3 & 1) == 0 )
  {
    v25 = 1;
    while ( v2 != v25 )
    {
      v26 = (unsigned __int8)v3[v25++];
      if ( v26 == 1 )
      {
        if ( v25 - 1 < v2 )
          goto LABEL_4;
        return 0;
      }
    }
    return 0;
  }
LABEL_4:
  v4 = *(int *)(v1 + 356);
  if ( !(_DWORD)v4 )
    return 0;
  if ( (v4 & 0x80000000) == 0 )
  {
    v5 = 4 * v4;
    v6 = a1;
    v7 = _kmalloc_noprof(4 * v4, 3520);
    while ( 1 )
    {
      a1 = v6;
      if ( !v7 )
        goto LABEL_38;
      v8 = v6;
      variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(v6 + 744), "ll-reg-offsets", v7, v4, v4);
      if ( (variable_u32_array & 0x80000000) != 0 )
        break;
      v10 = _kmalloc_noprof(8 * v4, 3520);
      *(_QWORD *)(v1 + 360) = v10;
      if ( !v10 )
      {
        v27 = -12;
        goto LABEL_46;
      }
      v11 = *(unsigned int *)(v1 + 80);
      v12 = _kmalloc_noprof(v11, 3520);
      *(_QWORD *)(v1 + 368) = v12;
      if ( !v12 )
      {
        v27 = -12;
LABEL_45:
        kfree(*(_QWORD *)(v1 + 360));
        *(_QWORD *)(v1 + 360) = 0;
LABEL_46:
        kfree(v7);
        return v27;
      }
      v13 = *(unsigned int *)(v1 + 348);
      if ( !(_DWORD)v13 || (v14 = *(_QWORD *)(v1 + 72), (((unsigned __int8)v14 | (unsigned __int8)v13) & 3) != 0) )
      {
        dev_err(v8, "Failed to copy DCC SRAM contents\n");
        kfree(*(_QWORD *)(v1 + 368));
        v27 = -22;
        *(_QWORD *)(v1 + 368) = 0;
        goto LABEL_45;
      }
      if ( (unsigned int)v13 < 4 )
      {
LABEL_21:
        v12 = mutex_lock(v1 + 24);
        if ( (int)v4 < 1 )
        {
LABEL_30:
          mutex_unlock(v1 + 24);
          kfree(v7);
          return 0;
        }
        v18 = 0;
        v19 = 0;
        v20 = v5;
        while ( v5 >= v19 )
        {
          if ( v20 < 4 )
            break;
          if ( (v19 & 0x8000000000000000LL) != 0 )
            break;
          if ( v5 < v19 )
            break;
          v17 = v20 >= 4;
          v20 -= 4LL;
          if ( !v17 )
            break;
          v21 = *(unsigned int *)(v7 + v19);
          v19 += 4LL;
          *(_DWORD *)(*(_QWORD *)(v1 + 360) + v18) = v21;
          v22 = *(_DWORD *)(*(_QWORD *)v1 + v21);
          v23 = *(_QWORD *)(v1 + 360) + v18;
          v18 += 8;
          *(_DWORD *)(v23 + 4) = v22;
          if ( 4 * v4 == v19 )
            goto LABEL_30;
        }
      }
      else
      {
        v15 = 0;
        v16 = v11;
        while ( v11 >= v15 )
        {
          if ( v16 < 4 )
            break;
          if ( v11 < v15 )
            break;
          v17 = v16 >= 4;
          v16 -= 4LL;
          if ( !v17 )
            break;
          v13 -= 4LL;
          *(_DWORD *)(v12 + v15) = *(_DWORD *)(v14 + v15);
          v15 += 4LL;
          if ( v13 <= 3 )
            goto LABEL_21;
        }
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v29 = *(_QWORD *)(StatusReg + 80);
      v6 = v12;
      *(_QWORD *)(StatusReg + 80) = &dcc_state_store__alloc_tag;
      if ( (v4 & 0x80000000) != 0 )
      {
        v5 = 0;
        v7 = 0;
      }
      else
      {
        v5 = 4 * v4;
        v7 = _kmalloc_noprof(4 * v4, 3520);
      }
      *(_QWORD *)(StatusReg + 80) = v29;
    }
    v27 = variable_u32_array;
    goto LABEL_46;
  }
LABEL_38:
  dev_err(a1, "Failed to alloc memory for reg_offsets\n");
  return 4294967284LL;
}
