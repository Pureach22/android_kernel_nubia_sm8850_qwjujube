__int64 __fastcall android_vh_alter_mutex_list_add(__int64 a1, __int64 a2, _QWORD *a3, _QWORD *a4, _BYTE *a5)
{
  char *StatusReg; // x10
  _DWORD *v6; // x10
  _QWORD *v7; // x11
  char *v8; // x12
  _DWORD *v9; // x12
  _QWORD *v10; // x1
  _QWORD *v11; // x8
  __int64 result; // x0
  _BYTE *v15; // x9

  StatusReg = (char *)_ReadStatusReg(SP_EL0);
  if ( StatusReg == (char *)&init_task )
    v6 = &vendor_data_pad;
  else
    v6 = StatusReg + 5184;
  if ( (walt_disabled & 1) == 0 && a2 && a3 && a4 && v6[82] != -1 )
  {
    v7 = a4;
    while ( 1 )
    {
      v7 = (_QWORD *)*v7;
      if ( v7 == a4 )
        break;
      v8 = (char *)v7[2];
      if ( v8 == (char *)&init_task )
        v9 = &vendor_data_pad;
      else
        v9 = v8 + 5184;
      if ( v9[82] == -1 )
      {
        v10 = (_QWORD *)v7[1];
        v11 = (_QWORD *)*v10;
        if ( *(_QWORD **)(*v10 + 8LL) != v10 || v10 == a3 || v11 == a3 )
        {
          result = _list_add_valid_or_report(a3, v10, *v10);
          a5 = v15;
        }
        else
        {
          v11[1] = a3;
          *a3 = v11;
          a3[1] = v10;
          *v10 = a3;
        }
        *a5 = 1;
        return result;
      }
    }
  }
  return result;
}
