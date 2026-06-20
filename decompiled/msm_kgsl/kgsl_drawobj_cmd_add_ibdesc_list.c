__int64 __fastcall kgsl_drawobj_cmd_add_ibdesc_list(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  int v4; // w20
  __int64 result; // x0
  int v7; // w19
  __int64 v9; // [xsp+8h] [xbp-38h] BYREF
  __int64 v10; // [xsp+10h] [xbp-30h]
  __int64 v11; // [xsp+18h] [xbp-28h]
  __int64 v12; // [xsp+20h] [xbp-20h]
  __int64 v13; // [xsp+28h] [xbp-18h] BYREF
  __int64 v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 16) & 2) != 0 )
  {
LABEL_15:
    result = 0;
    goto LABEL_16;
  }
  v4 = a3;
  result = 4294967274LL;
  if ( a3 )
  {
    v7 = a4;
    if ( a4 )
    {
      if ( (*(_QWORD *)_ReadStatusReg(SP_EL0) & 0x400000) != 0 )
      {
        if ( a4 >= 1 )
        {
          v11 = 0;
          v12 = 0;
          v10 = 0;
          while ( 1 )
          {
            v13 = 0;
            v14 = 0;
            if ( inline_copy_from_user_1((int)&v13, v4, 0x10u) )
              goto LABEL_17;
            v9 = (unsigned int)v13;
            v11 = (unsigned int)v14;
            LODWORD(v12) = HIDWORD(v14);
            result = kgsl_drawobj_cmd_add_ibdesc(a1, a2, &v9);
            if ( (_DWORD)result )
              goto LABEL_16;
            --v7;
            v4 += 16;
            if ( !v7 )
              goto LABEL_15;
          }
        }
      }
      else if ( a4 >= 1 )
      {
        while ( 1 )
        {
          v11 = 0;
          v12 = 0;
          v9 = 0;
          v10 = 0;
          if ( inline_copy_from_user_1((int)&v9, v4, 0x20u) )
            break;
          result = kgsl_drawobj_cmd_add_ibdesc(a1, a2, &v9);
          if ( !(_DWORD)result )
          {
            --v7;
            v4 += 32;
            if ( v7 )
              continue;
          }
          goto LABEL_16;
        }
LABEL_17:
        result = 4294967282LL;
        goto LABEL_16;
      }
      goto LABEL_15;
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
