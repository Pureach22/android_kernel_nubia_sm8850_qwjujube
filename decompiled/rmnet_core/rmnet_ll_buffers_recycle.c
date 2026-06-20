__int64 __fastcall rmnet_ll_buffers_recycle(__int64 result)
{
  __int64 (*v1)(void); // x8
  __int64 v2; // x19
  _QWORD *v3; // x8
  int v4; // w20
  _QWORD *v5; // x10
  int v6; // w21
  unsigned int v7; // w11
  _QWORD **v8; // x12
  _QWORD *v9; // x9
  char v10; // w8
  _QWORD *v11; // x8
  _QWORD *v12; // x1
  __int64 v13; // x8
  _QWORD *v14; // x9
  _QWORD *v15; // x10
  _QWORD *v16; // x11
  bool v17; // vf
  int v18; // w20
  unsigned __int64 v19; // x9
  unsigned __int64 *v20; // x1
  _QWORD *v21; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = (__int64 (*)(void))off_66A0;
  v21 = &v21;
  v22 = &v21;
  if ( off_66A0 )
  {
    v2 = result;
    if ( *((_DWORD *)off_66A0 - 1) != 1200057395 )
      __break(0x8228u);
    result = v1();
    if ( (_DWORD)result )
    {
      v3 = *(_QWORD **)(v2 + 24);
      v4 = result;
      v5 = (_QWORD *)*v3;
      if ( (_QWORD *)*v3 == v3 )
      {
        v6 = 0;
      }
      else
      {
        v6 = 0;
        v7 = 0;
        v8 = &v21;
        while ( 1 )
        {
          v9 = v5;
          if ( v7 > 0xF )
            break;
          if ( v6 != v4 )
          {
            v10 = *((_BYTE *)v5 + 25);
            v5 = (_QWORD *)*v5;
            if ( (v10 & 1) == 0 )
            {
              v11 = (_QWORD *)v9[1];
              if ( (_QWORD *)*v11 == v9 && (_QWORD *)v5[1] == v9 )
              {
                v5[1] = v11;
                *v11 = v5;
              }
              else
              {
                result = _list_del_entry_valid_or_report(v9);
              }
              v12 = v22;
              ++v6;
              if ( v9 == v8 || v22 == v9 || (_QWORD **)*v22 != v8 )
              {
                result = _list_add_valid_or_report(v9, v22, &v21);
              }
              else
              {
                v22 = v9;
                *v9 = v8;
                v9[1] = v12;
                *v12 = v9;
              }
            }
            ++v7;
            if ( v5 != *(_QWORD **)(v2 + 24) )
              continue;
          }
          *(_QWORD *)(v2 + 24) = v5;
          if ( !v6 )
            goto LABEL_26;
          goto LABEL_24;
        }
        *(_QWORD *)(v2 + 24) = v5;
        if ( !v6 )
          goto LABEL_26;
LABEL_24:
        result = rmnet_ll_buffers_submit(v2, &v21);
        v13 = *(_QWORD *)(v2 + 24);
        v14 = v21;
        if ( v21 != &v21 )
        {
          v15 = *(_QWORD **)(v13 + 8);
          v16 = v22;
          v21[1] = v15;
          *v15 = v14;
          *v16 = v13;
          *(_QWORD *)(v13 + 8) = v16;
          v21 = &v21;
          v22 = &v21;
        }
      }
LABEL_26:
      v17 = __OFSUB__(v4, v6);
      v18 = v4 - v6;
      if ( !((v18 < 0) ^ v17 | (v18 == 0)) )
      {
        _ReadStatusReg(SP_EL0);
        do
        {
          result = _alloc_pages_noprof(395296, *(unsigned int *)(v2 + 60), 0, 0);
          if ( !result )
            break;
          v19 = (((result << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
              + *(unsigned int *)(v2 + 64);
          *(_QWORD *)(v19 + 16) = result;
          *(_BYTE *)(v19 + 25) = 0;
          *(_QWORD *)v19 = v19;
          *(_QWORD *)(v19 + 8) = v19;
          if ( !v19 )
            break;
          v20 = v22;
          if ( (_QWORD **)v19 == &v21 || v22 == (_QWORD *)v19 || (_QWORD **)*v22 != &v21 )
          {
            result = _list_add_valid_or_report(v19, v22, &v21);
          }
          else
          {
            v22 = (_QWORD *)v19;
            *(_QWORD *)v19 = &v21;
            *(_QWORD *)(v19 + 8) = v20;
            *v20 = v19;
          }
          *(_BYTE *)(v19 + 24) = 1;
          --v18;
          ++qword_2FDE0;
        }
        while ( v18 );
      }
      if ( v21 != &v21 )
        result = rmnet_ll_buffers_submit(v2, &v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
