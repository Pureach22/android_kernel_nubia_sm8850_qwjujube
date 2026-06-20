int *__fastcall fastrpc_alloc_rootheap_buf(int *result, __int64 a2, _DWORD *a3)
{
  _DWORD *v3; // x20
  unsigned int v4; // w8
  int v5; // w9
  __int64 v6; // x21
  unsigned int v7; // w8
  int *v8; // x19
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x10
  int *v15; // x25
  _QWORD *v16; // x21
  __int64 v17; // x0
  _QWORD *v18; // x1
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = result + 16036;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = result[16064];
  v5 = result[13050];
  v19[0] = 0;
  if ( v4 )
    v6 = v4;
  else
    v6 = 1310720;
  if ( v5 )
  {
    v7 = result[16065];
    if ( !v7 )
      v7 = 3;
    if ( result[16040] < v7 )
    {
      v8 = result;
      v11 = raw_spin_lock_irqsave(result + 12900);
      v12 = (unsigned int)v8[1];
      v13 = v11;
      if ( (int)v12 < 1 )
      {
LABEL_20:
        result = (int *)raw_spin_unlock_irqrestore(v8 + 12900, v13);
        goto LABEL_21;
      }
      v14 = 0;
      v15 = v8;
      while ( 1 )
      {
        if ( v14 == 51 )
          __break(0x5512u);
        if ( v15[296] == 1 && (v15[47] & 1) != 0 )
          break;
        ++v14;
        v15 += 256;
        if ( v12 == v14 )
          goto LABEL_20;
      }
      raw_spin_unlock_irqrestore(v8 + 12900, v11);
      result = (int *)_fastrpc_buf_alloc(0, (_QWORD *)v15 + 22, *v8, v6, v19, 5);
      if ( !(_DWORD)result )
      {
        v16 = (_QWORD *)v19[0];
        *a3 = 3;
        *(_QWORD *)(a2 + 32) = v16[8];
        *(_QWORD *)(a2 + 40) = v16[9];
        v17 = raw_spin_lock_irqsave(v8 + 12900);
        v18 = *((_QWORD **)v3 + 1);
        v13 = v17;
        if ( v16 == (_QWORD *)v3 || v16 == v18 || (_DWORD *)*v18 != v3 )
        {
          _list_add_valid_or_report(v16, v18, v3);
        }
        else
        {
          *((_QWORD *)v3 + 1) = v16;
          *v16 = v3;
          v16[1] = v18;
          *v18 = v16;
        }
        ++v3[4];
        goto LABEL_20;
      }
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
