__int64 __fastcall sir_convert_mlo_probe_rsp_frame2_struct(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int16 v7; // w8
  __int16 v8; // w9
  __int16 v9; // w8
  __int16 v10; // w9
  _BYTE v11[4]; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v12[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v13[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v14[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v15; // [xsp+10h] [xbp-10h] BYREF
  __int16 v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  result = 29;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v14[0] = 0;
    v13[0] = 0;
    v12[0] = 0;
    v11[0] = 0;
    v15 = 0;
    v16 = 0;
    qdf_mem_set((void *)a3, 0x92Eu, 0);
    util_get_mlie_common_info_len(a1, a2, a3 + 4);
    lim_store_mlo_ie_raw_info(a1, a1 + *(unsigned __int8 *)(a3 + 4) + 5, a2, a3 + 2);
    util_get_bvmlie_mldmacaddr(a1, a2, (int)&v15);
    qdf_mem_copy((void *)(a3 + 5), &v15, 6u);
    util_get_bvmlie_primary_linkid(a1, a2, v14, v13);
    v7 = 16 * (v14[0] & 1);
    v8 = *(_WORD *)(a3 + 2) & 0xFFEF;
    *(_BYTE *)(a3 + 11) = v13[0];
    *(_WORD *)(a3 + 2) = v8 | v7;
    util_get_bvmlie_bssparamchangecnt(a1, a2, v12, v11);
    result = 0;
    v9 = 32 * (v12[0] & 1);
    v10 = *(_WORD *)(a3 + 2) & 0xFFDF;
    *(_BYTE *)(a3 + 12) = v11[0];
    *(_WORD *)(a3 + 2) = v10 | v9;
    *(_BYTE *)(a3 + 1) = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
