__int64 __fastcall sap_sort_mac_list(
        __int64 result,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 v11; // x20
  unsigned int v12; // w23
  __int64 v13; // x25
  __int64 v14; // x22
  __int64 v15; // [xsp+0h] [xbp-10h] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v10 = a2;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v15) = 0;
  LODWORD(v15) = 0;
  if ( result && a2 <= 0x20u )
  {
    if ( a2 )
    {
      v11 = result;
      v12 = 0;
      do
      {
        if ( v10 != 1 )
        {
          v13 = v10 - 1;
          v14 = v11;
          do
          {
            result = qdf_mem_cmp((const void *)v14, (const void *)(v14 + 6), 6u);
            if ( (int)result >= 1 )
            {
              qdf_mem_copy(&v15, (const void *)(v14 + 6), 6u);
              qdf_mem_copy((void *)(v14 + 6), (const void *)v14, 6u);
              result = (__int64)qdf_mem_copy((void *)v14, &v15, 6u);
            }
            --v13;
            v14 += 6;
          }
          while ( v13 );
        }
        ++v12;
      }
      while ( v12 < v10 );
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x39u,
               2u,
               "%s: either buffer is NULL or size = %d is more",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "sap_sort_mac_list",
               a2,
               v15,
               v16);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
