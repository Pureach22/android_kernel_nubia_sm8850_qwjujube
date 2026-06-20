__int64 __fastcall reg_copy_regd(__int64 a1)
{
  unsigned __int64 v2; // x20
  __int64 result; // x0
  __int64 v4; // x9
  __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x1
  __int64 *v9; // x10
  _QWORD *v10; // x12
  unsigned __int64 v11; // x15
  __int64 v12; // x11
  __int64 v13; // x13
  __int64 v14; // x14
  __int64 v15; // x11
  __int64 v16; // x11
  __int64 v17; // x11
  __int64 v18; // x13
  __int64 v19; // x10
  __int64 v20; // x14
  unsigned __int64 StatusReg; // x21
  __int64 v22; // x22

  v2 = 96LL * *(unsigned int *)(a1 + 16) + 32;
  result = _kmalloc_noprof(v2, 3520);
  if ( !result )
    return -12;
  while ( 1 )
  {
    v4 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)result = *(_QWORD *)a1;
    *(_QWORD *)(result + 8) = v4;
    v5 = *(_QWORD *)(a1 + 24);
    LODWORD(v4) = *(_DWORD *)(a1 + 16);
    *(_QWORD *)(result + 16) = *(_QWORD *)(a1 + 16);
    *(_QWORD *)(result + 24) = v5;
    if ( !(_DWORD)v4 )
      break;
    v6 = 0;
    v7 = 28;
    while ( 1 )
    {
      v8 = v2 >= v7 ? v2 - v7 : 0LL;
      if ( v8 <= 0x5F )
        break;
      v9 = (__int64 *)(a1 + v7);
      v10 = (_QWORD *)(result + v7);
      v11 = *(unsigned int *)(a1 + 16);
      v12 = *(_QWORD *)(a1 + v7 + 64);
      v13 = *(_QWORD *)(a1 + v7 + 72);
      ++v6;
      v7 += 96LL;
      v10[8] = v12;
      v10[9] = v13;
      v14 = v9[11];
      v10[10] = v9[10];
      v10[11] = v14;
      v15 = v9[5];
      v10[4] = v9[4];
      v10[5] = v15;
      v16 = v9[7];
      v10[6] = v9[6];
      v10[7] = v16;
      v18 = *v9;
      v17 = v9[1];
      v20 = v9[2];
      v19 = v9[3];
      *v10 = v18;
      v10[1] = v17;
      v10[2] = v20;
      v10[3] = v19;
      if ( v6 >= v11 )
        return result;
    }
    _fortify_panic(17, v8);
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &reg_copy_regd__alloc_tag;
    v2 = 96LL * *(unsigned int *)(a1 + 16) + 32;
    result = _kmalloc_noprof(v2, 3520);
    *(_QWORD *)(StatusReg + 80) = v22;
    if ( !result )
      return -12;
  }
  return result;
}
