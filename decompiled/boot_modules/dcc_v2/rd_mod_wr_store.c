__int64 __fastcall rd_mod_wr_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  __int64 result; // x0
  __int64 v7; // [xsp+0h] [xbp-10h] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( sscanf(s, "%x %x", (char *)&v7 + 4, &v7) == 2 )
  {
    LODWORD(result) = dcc_rd_mod_wr_add(v5, HIDWORD(v7), (unsigned int)v7);
    if ( (_DWORD)result )
      result = (int)result;
    else
      result = a4;
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
