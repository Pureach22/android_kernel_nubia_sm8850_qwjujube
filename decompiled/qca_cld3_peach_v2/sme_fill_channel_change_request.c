__int64 __fastcall sme_fill_channel_change_request(__int64 a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 v4; // w8
  int v5; // w8
  __int64 result; // x0
  int v7; // w9
  size_t v8; // x2
  __int64 v9; // [xsp+0h] [xbp-40h] BYREF
  __int64 v10; // [xsp+8h] [xbp-38h]
  __int64 v11; // [xsp+10h] [xbp-30h]
  size_t n; // [xsp+18h] [xbp-28h] BYREF
  size_t v13[2]; // [xsp+20h] [xbp-20h] BYREF
  int v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  v10 = 0;
  v14 = 0;
  v9 = v4;
  v5 = *((_DWORD *)a2 + 1);
  v13[0] = 0;
  v13[1] = 0;
  v11 = 0;
  n = 0;
  HIDWORD(v9) = a3;
  LODWORD(v10) = v5;
  result = sme_get_network_params(a1, (__int64)&v9);
  v7 = v11;
  v8 = (unsigned __int8)n;
  *((_DWORD *)a2 + 5) = BYTE4(v10);
  *((_DWORD *)a2 + 6) = v7;
  if ( (_DWORD)v8 )
  {
    result = (__int64)qdf_mem_copy(a2 + 37, (char *)&n + 1, v8);
    a2[36] = n;
  }
  if ( BYTE5(v13[0]) )
  {
    result = (__int64)qdf_mem_copy(a2 + 50, (char *)v13 + 6, BYTE5(v13[0]));
    a2[49] = BYTE5(v13[0]);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
