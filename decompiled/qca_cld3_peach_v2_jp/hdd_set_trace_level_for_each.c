__int64 __fastcall hdd_set_trace_level_for_each(__int64 *a1)
{
  unsigned int pidx; // w20
  unsigned int i; // w21
  __int64 values; // x0
  __int64 result; // x0
  unsigned __int64 v6; // x23
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x9
  int v9; // w26
  unsigned int v10; // w19
  __int64 v11; // x0
  unsigned int v12; // w20
  unsigned int v13; // w21
  unsigned int v14; // w26
  bool v15; // cc
  unsigned __int64 v16; // [xsp+0h] [xbp-160h] BYREF
  _BYTE s[334]; // [xsp+Ah] [xbp-156h] BYREF
  __int64 v18; // [xsp+158h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v16 = 0;
  pidx = qdf_get_pidx();
  for ( i = 0; i != 167; ++i )
    ((void (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD))qdf_print_set_category_verbose)(
      pidx,
      i,
      9,
      *(unsigned __int8 *)(a1[13] + 8));
  values = cfg_psoc_get_values(*a1);
  result = qdf_uint8_array_parse((_BYTE *)(values + 2867), (__int64)s, 334, &v16);
  if ( v16 >= 2 )
  {
    v6 = 0;
    do
    {
      if ( v6 >= 0x14E )
        __break(0x5512u);
      v8 = (unsigned __int8)s[v6 + 1];
      if ( v8 > 6 )
        LOBYTE(v9) = 10;
      else
        v9 = dword_A078D0[v8];
      v10 = (unsigned __int8)s[v6];
      if ( v10 <= 0xA6 )
      {
        v11 = qdf_get_pidx();
        v12 = v11;
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))qdf_print_set_category_verbose)(
                   v11,
                   v10,
                   0,
                   0);
        if ( !(_DWORD)result )
        {
          v13 = 0;
          v14 = ~(-1 << v9);
          do
          {
            if ( (v14 & 1) != 0 )
            {
              result = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64))qdf_print_set_category_verbose)(
                         v12,
                         v10,
                         v13,
                         1);
              if ( (_DWORD)result )
                break;
            }
            v15 = v14 > 1;
            ++v13;
            v14 >>= 1;
          }
          while ( v15 );
        }
      }
      v7 = v6 + 3;
      v6 += 2LL;
    }
    while ( v16 > v7 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
