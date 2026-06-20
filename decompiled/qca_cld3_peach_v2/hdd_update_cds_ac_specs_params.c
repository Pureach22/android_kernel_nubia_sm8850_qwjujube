__int64 __fastcall hdd_update_cds_ac_specs_params(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x20
  __int64 v10; // x19
  __int64 values; // x0
  int v12; // w9
  __int16 v13; // w10
  int v14; // w8
  int v15; // w9
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  int v23; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int8 v24; // [xsp+14h] [xbp-Ch]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v23 = 0;
  v22 = 0;
  if ( result )
  {
    v9 = (__int64 *)result;
    if ( *(_QWORD *)(result + 104) )
    {
      result = (__int64)_cds_get_context(56, (__int64)"hdd_update_cds_ac_specs_params", a2, a3, a4, a5, a6, a7, a8, a9);
      if ( result )
      {
        v10 = result;
        values = cfg_psoc_get_values(*v9);
        qdf_uint8_array_parse((_BYTE *)(values + 4362), (__int64)&v23, 5, &v22);
        if ( v22 == 5 )
        {
          v12 = BYTE1(v23);
          v13 = BYTE2(v23);
          *(_DWORD *)(v10 + 160) = (unsigned __int8)v23;
          *(_DWORD *)(v10 + 164) = v12;
          v14 = HIBYTE(v23);
          v15 = v24;
          *(_WORD *)(v10 + 168) = v13;
          *(_DWORD *)(v10 + 172) = v14;
          *(_DWORD *)(v10 + 176) = v15;
        }
        v16 = *v9;
        v22 = 0;
        v17 = cfg_psoc_get_values(v16);
        qdf_uint8_array_parse((_BYTE *)(v17 + 4413), (__int64)&v23, 5, &v22);
        if ( v22 == 5 )
        {
          *(_DWORD *)(v10 + 180) = (unsigned __int8)v23;
          *(_DWORD *)(v10 + 184) = BYTE1(v23);
          *(_WORD *)(v10 + 188) = BYTE2(v23);
          *(_DWORD *)(v10 + 192) = HIBYTE(v23);
          *(_DWORD *)(v10 + 196) = v24;
        }
        v18 = *v9;
        v22 = 0;
        v19 = cfg_psoc_get_values(v18);
        qdf_uint8_array_parse((_BYTE *)(v19 + 4311), (__int64)&v23, 5, &v22);
        if ( v22 == 5 )
        {
          *(_DWORD *)(v10 + 200) = (unsigned __int8)v23;
          *(_DWORD *)(v10 + 204) = BYTE1(v23);
          *(_WORD *)(v10 + 208) = BYTE2(v23);
          *(_DWORD *)(v10 + 212) = HIBYTE(v23);
          *(_DWORD *)(v10 + 216) = v24;
        }
        v20 = *v9;
        v22 = 0;
        v21 = cfg_psoc_get_values(v20);
        result = qdf_uint8_array_parse((_BYTE *)(v21 + 4260), (__int64)&v23, 5, &v22);
        if ( v22 == 5 )
        {
          *(_DWORD *)(v10 + 220) = (unsigned __int8)v23;
          *(_DWORD *)(v10 + 224) = BYTE1(v23);
          *(_WORD *)(v10 + 228) = BYTE2(v23);
          *(_DWORD *)(v10 + 232) = HIBYTE(v23);
          *(_DWORD *)(v10 + 236) = v24;
        }
        v22 = 0;
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Warning: hdd_ctx->cfg_ini is NULL",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "hdd_update_cds_ac_specs_params");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
