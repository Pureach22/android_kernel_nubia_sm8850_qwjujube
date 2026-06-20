__int64 __fastcall rmnet_shs_get_update_skb_hdr_info(__int64 a1, __int64 a2)
{
  int v4; // w8
  __int64 result; // x0
  __int16 v6; // w8
  __int64 v7; // x9
  __int64 v8; // x10
  __int16 v9; // w8
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x11
  int v13; // w8
  __int64 v14; // x9
  __int64 v15; // x10
  _BYTE v16[4]; // [xsp+0h] [xbp-70h] BYREF
  __int16 v17; // [xsp+4h] [xbp-6Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-68h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-60h] BYREF
  int v20; // [xsp+20h] [xbp-50h]
  _QWORD v21[2]; // [xsp+28h] [xbp-48h] BYREF
  int v22; // [xsp+38h] [xbp-38h]
  _QWORD v23[6]; // [xsp+40h] [xbp-30h] BYREF

  v23[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int16 *)(a1 + 180);
  v22 = 0;
  v21[0] = 0;
  v21[1] = 0;
  memset(v23, 0, 40);
  v20 = 0;
  v19[0] = 0;
  v19[1] = 0;
  v18 = 0;
  v17 = 0;
  v16[0] = 0;
  if ( v4 == 56710 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))rmnet_shs_header_ptr)(a1, 0, 40, v23);
    if ( !result )
      goto LABEL_13;
    v9 = *(unsigned __int8 *)(result + 6);
    *(_DWORD *)(a2 + 204) = 2;
    *(_WORD *)(a2 + 220) = v9;
    *(_QWORD *)a2 = *(_QWORD *)result;
    v10 = *(_QWORD *)(result + 32);
    v11 = *(_QWORD *)(result + 8);
    v12 = *(_QWORD *)(result + 16);
    *(_QWORD *)(a2 + 24) = *(_QWORD *)(result + 24);
    *(_QWORD *)(a2 + 32) = v10;
    *(_QWORD *)(a2 + 8) = v11;
    *(_QWORD *)(a2 + 16) = v12;
    v16[0] = *(_BYTE *)(result + 6);
    result = ipv6_skip_exthdr(a1, 40, v16, &v17);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_13;
  }
  else
  {
    result = 0;
    if ( v4 == 8 )
    {
      result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))rmnet_shs_header_ptr)(a1, 0, 20, v21);
      if ( !result )
        goto LABEL_13;
      v6 = *(unsigned __int8 *)(result + 9);
      *(_DWORD *)(a2 + 204) = 1;
      *(_WORD *)(a2 + 220) = v6;
      v8 = *(_QWORD *)result;
      v7 = *(_QWORD *)(result + 8);
      *(_DWORD *)(a2 + 16) = *(_DWORD *)(result + 16);
      *(_QWORD *)a2 = v8;
      *(_QWORD *)(a2 + 8) = v7;
      result = 4 * (*(_BYTE *)result & 0xFu);
    }
  }
  v13 = *(unsigned __int16 *)(a2 + 220);
  if ( v13 == 17 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64 *))rmnet_shs_header_ptr)(
               a1,
               (unsigned __int16)result,
               8,
               &v18);
    if ( result )
      *(_QWORD *)(a2 + 40) = *(_QWORD *)result;
  }
  else if ( v13 == 6 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))rmnet_shs_header_ptr)(
               a1,
               (unsigned __int16)result,
               20,
               v19);
    if ( result )
    {
      v15 = *(_QWORD *)result;
      v14 = *(_QWORD *)(result + 8);
      *(_DWORD *)(a2 + 56) = *(_DWORD *)(result + 16);
      *(_QWORD *)(a2 + 40) = v15;
      *(_QWORD *)(a2 + 48) = v14;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
