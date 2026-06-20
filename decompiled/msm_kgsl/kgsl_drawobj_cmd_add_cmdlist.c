__int64 __fastcall kgsl_drawobj_cmd_add_cmdlist(_QWORD *a1, __int64 a2, __int64 a3, unsigned int a4, int a5)
{
  int v5; // w20
  __int64 v7; // x22
  __int64 result; // x0
  __int64 v11; // x8
  size_t v12; // x23
  size_t v13; // x24
  __int64 v14; // [xsp+8h] [xbp-28h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h]
  __int64 v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 16) & 2) == 0 && ((v5 = a5, (v7 = a3) != 0) || a5 | a4) )
  {
    result = 4294967274LL;
    if ( a3 && a4 && a5 )
    {
      v11 = a4;
      v16 = 0;
      v17 = 0;
      if ( a4 >= 0x20uLL )
        v12 = 32;
      else
        v12 = a4;
      if ( a4 <= 0x20uLL )
        v11 = 32;
      v14 = 0;
      v15 = 0;
      v13 = v11 - v12;
      while ( 1 )
      {
        if ( a4 > 0x1F )
        {
          if ( a4 >= 0x21 && (int)check_zeroed_user(v7 + v12, v13) < 1 )
          {
LABEL_24:
            result = 4294967282LL;
            goto LABEL_5;
          }
        }
        else
        {
          memset((char *)&v14 + v12, 0, v13);
        }
        _check_object_size(&v14, v12, 0);
        if ( inline_copy_from_user_1((int)&v14, v7, v12) )
          goto LABEL_24;
        if ( (v17 & 7) == 0 )
          break;
        result = kgsl_drawobj_add_memobject(a2 + 88, &v14);
        if ( (_DWORD)result )
          goto LABEL_5;
        --v5;
        v7 += 32;
        if ( !v5 )
          goto LABEL_4;
      }
      dev_err(
        *a1,
        "invalid cmdobj ctxt %u flags %d id %d offset %llu addr %llx size %llu\n",
        *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL),
        v17,
        HIDWORD(v17),
        v14,
        v15,
        v16);
      result = 4294967274LL;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
