__int64 __fastcall ml_nlink_handle_standby_link_3_ports(
        __int64 result,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        unsigned int *a5)
{
  __int64 v5; // x22
  __int64 v8; // x21
  int v9; // w23
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x9
  int v16; // w9
  unsigned int v17; // [xsp+10h] [xbp-60h] BYREF
  _BYTE v18[4]; // [xsp+14h] [xbp-5Ch] BYREF
  int v19; // [xsp+18h] [xbp-58h] BYREF
  char v20; // [xsp+1Ch] [xbp-54h]
  int v21; // [xsp+20h] [xbp-50h] BYREF
  unsigned __int8 v22; // [xsp+24h] [xbp-4Ch]
  _QWORD v23[5]; // [xsp+28h] [xbp-48h] BYREF
  __int64 v24; // [xsp+50h] [xbp-20h] BYREF
  __int64 v25; // [xsp+58h] [xbp-18h]
  int v26; // [xsp+60h] [xbp-10h]
  __int64 v27; // [xsp+68h] [xbp-8h]

  v5 = a4;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v17 = 0;
  if ( a4 < 2u )
    goto LABEL_46;
  v8 = result;
  v22 = 0;
  v21 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v19 = 0;
  v20 = 0;
  memset(v23, 0, sizeof(v23));
  result = ml_nlink_get_link_info(
             result,
             a2,
             1u,
             5u,
             v23,
             (unsigned int *)&v24,
             (unsigned __int8 *)&v21,
             &v19,
             v18,
             &v17);
  v9 = v18[0];
  if ( v18[0] < 2u || (result = policy_mgr_2_freq_always_on_same_mac(v8, *a5, a5[1]), (result & 1) != 0) )
  {
LABEL_46:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)(v9 - 6) >= 0xFFFFFFFB )
  {
    if ( (unsigned __int8)v21 == 255 )
    {
      v11 = 0;
      while ( (_DWORD)v24 != a5[v11] )
      {
        if ( v5 == ++v11 )
          goto LABEL_12;
      }
      if ( (_DWORD)v5 != (unsigned __int8)v11 )
        goto LABEL_6;
LABEL_12:
      v10 = 1 << v19;
    }
    else
    {
LABEL_6:
      v10 = 0;
    }
    if ( BYTE1(v21) == 255 )
    {
      v12 = 0;
      while ( HIDWORD(v24) != a5[v12] )
      {
        if ( v5 == ++v12 )
          goto LABEL_19;
      }
      if ( (_DWORD)v5 != (unsigned __int8)v12 )
        goto LABEL_20;
LABEL_19:
      v10 |= 1 << SBYTE1(v19);
    }
LABEL_20:
    if ( v9 != 2 )
    {
      if ( BYTE2(v21) == 255 )
      {
        v13 = 0;
        while ( (_DWORD)v25 != a5[v13] )
        {
          if ( v5 == ++v13 )
            goto LABEL_27;
        }
        if ( (_DWORD)v5 != (unsigned __int8)v13 )
          goto LABEL_28;
LABEL_27:
        v10 |= 1 << SBYTE2(v19);
      }
LABEL_28:
      if ( v9 != 3 )
      {
        if ( HIBYTE(v21) == 255 )
        {
          v14 = 0;
          while ( HIDWORD(v25) != a5[v14] )
          {
            if ( v5 == ++v14 )
              goto LABEL_35;
          }
          if ( (_DWORD)v5 != (unsigned __int8)v14 )
            goto LABEL_36;
LABEL_35:
          v10 |= 1 << SHIBYTE(v19);
        }
LABEL_36:
        if ( v9 != 4 && v22 == 255 )
        {
          v15 = 0;
          while ( v26 != a5[v15] )
          {
            if ( v5 == ++v15 )
              goto LABEL_43;
          }
          if ( (_DWORD)v5 != (unsigned __int8)v15 )
            goto LABEL_44;
LABEL_43:
          v10 |= 1 << v20;
        }
      }
    }
LABEL_44:
    v16 = *(unsigned __int16 *)(a3 + 2);
    if ( (v17 & ~(v10 | v16)) != 0 )
      *(_WORD *)(a3 + 2) = v16 | v10;
    goto LABEL_46;
  }
  __break(0x5512u);
  return device_mode_to_string_1(result);
}
