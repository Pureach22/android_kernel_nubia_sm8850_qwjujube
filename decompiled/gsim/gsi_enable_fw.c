__int64 __fastcall gsi_enable_fw(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v5; // [xsp+8h] [xbp-28h] BYREF
  __int64 v6; // [xsp+10h] [xbp-20h]
  __int64 v7; // [xsp+18h] [xbp-18h]
  int v8; // [xsp+20h] [xbp-10h]
  __int64 v9; // [xsp+28h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v7 = 0;
  v5 = 0;
  if ( a3 - 14 <= 0xFFFFFFF2 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Incorrect version %d\n", "gsi_enable_fw", 4889, a3);
    result = 0xFFFFFFFFLL;
  }
  else
  {
    LODWORD(v6) = 0;
    v8 = 1;
    LODWORD(v7) = 1;
    if ( a3 <= 1 )
    {
      HIDWORD(v7) = 1;
    }
    else
    {
      gsihal_write_reg_nk(116, 0, 0);
      HIDWORD(v7) = 0;
      if ( a3 >= 6 )
        LODWORD(v5) = 2;
    }
    gsihal_write_reg_fields(117, &v5);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
