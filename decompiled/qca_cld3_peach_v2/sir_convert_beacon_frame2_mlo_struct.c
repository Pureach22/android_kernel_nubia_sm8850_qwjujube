__int64 __fastcall sir_convert_beacon_frame2_mlo_struct(__int64 result, int a2, __int64 a3, __int64 a4)
{
  int v4; // w8
  __int64 v6; // x0
  __int64 v7; // x1
  __int16 v8; // w8
  __int16 v9; // w9
  __int16 v10; // [xsp+4h] [xbp-DCh] BYREF
  _BYTE v11[4]; // [xsp+8h] [xbp-D8h] BYREF
  _BYTE v12[4]; // [xsp+Ch] [xbp-D4h] BYREF
  _BYTE v13[4]; // [xsp+10h] [xbp-D0h] BYREF
  _BYTE v14[4]; // [xsp+14h] [xbp-CCh] BYREF
  int v15[2]; // [xsp+18h] [xbp-C8h] BYREF
  int v16[2]; // [xsp+20h] [xbp-C0h] BYREF
  _QWORD v17[23]; // [xsp+28h] [xbp-B8h] BYREF

  v17[22] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a3 + 2612);
  v14[0] = 0;
  v11[0] = 0;
  v10 = 0;
  if ( v4 )
  {
    *(_QWORD *)v15 = 0;
    *(_QWORD *)v16 = 0;
    memset(v17, 0, 176);
    v13[0] = 0;
    v12[0] = 0;
    result = util_find_mlie(result + 12, (unsigned int)(a2 - 12), v16, v15);
    if ( !(_DWORD)result )
    {
      result = util_get_bvmlie_persta_partner_info(*(_QWORD *)v16, *(_QWORD *)v15, v17, 255);
      if ( !(_DWORD)result )
      {
        v7 = *(_QWORD *)v15;
        v6 = *(_QWORD *)v16;
        *(_WORD *)(a4 + 3460) = LOBYTE(v17[0]);
        result = util_get_mlie_common_info_len(v6, v7, v14);
        if ( !(_DWORD)result )
        {
          lim_store_mlo_ie_raw_info(v16[0], v16[0] + v14[0] + 5, v15[0], a4 + 3438);
          qdf_mem_copy((void *)(a4 + 3441), (const void *)(*(_QWORD *)v16 + 6LL), 6u);
          util_get_bvmlie_ext_mld_cap_op_info(*(_QWORD *)v16, *(_QWORD *)v15, v11, &v10);
          if ( v11[0] == 1 )
            *(_WORD *)(a4 + 3458) = *(_WORD *)(a4 + 3458) & 0xFFE1 | v10 & 0x1E;
          result = util_get_bvmlie_bssparamchangecnt(*(_QWORD *)v16, *(_QWORD *)v15, v12, v13);
          v8 = 32 * (v12[0] & 1);
          v9 = *(_WORD *)(a4 + 3438) & 0xFFDF;
          *(_BYTE *)(a4 + 3448) = v13[0];
          *(_WORD *)(a4 + 3438) = v9 | v8;
          *(_BYTE *)(a4 + 3437) = 1;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
