__int64 __fastcall ll_lt_sap_get_valid_freq(__int64 a1, unsigned int a2, int a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-48h] BYREF
  __int64 v10; // [xsp+10h] [xbp-40h]
  __int64 v11; // [xsp+18h] [xbp-38h]
  __int64 v12; // [xsp+20h] [xbp-30h]
  __int64 v13; // [xsp+28h] [xbp-28h]
  __int64 v14; // [xsp+30h] [xbp-20h]
  __int64 v15; // [xsp+38h] [xbp-18h]
  int v16; // [xsp+40h] [xbp-10h]
  __int64 v17; // [xsp+48h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v9 = 0;
  qdf_mem_set(&v9, 0x3Cu, 0);
  HIDWORD(v15) = a3;
  ll_lt_sap_get_freq_list(a1, (unsigned int *)&v9, a2, a4);
  result = (unsigned int)v9;
  if ( !(_DWORD)v9 )
  {
    result = (unsigned int)v12;
    if ( !(_DWORD)v12 )
    {
      result = (unsigned int)v10;
      if ( !(_DWORD)v10 )
      {
        result = HIDWORD(v9);
        if ( !HIDWORD(v9) )
        {
          result = (unsigned int)v13;
          if ( !(_DWORD)v13 )
          {
            result = HIDWORD(v12);
            if ( !HIDWORD(v12) )
              result = (unsigned int)v15;
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
