_BYTE *__fastcall rmnet_shs_is_ll_skb_stamping_reqd(__int64 a1)
{
  int v2; // w8
  _BYTE *result; // x0
  int v4; // w8
  unsigned int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8
  __int16 v9; // [xsp+Ch] [xbp-B4h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-B0h] BYREF
  int v11; // [xsp+20h] [xbp-A0h]
  _BYTE v12[40]; // [xsp+90h] [xbp-30h] BYREF
  __int64 v13; // [xsp+B8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v12, 0, sizeof(v12));
  v2 = *(unsigned __int16 *)(a1 + 180);
  v11 = 0;
  v10[0] = 0;
  v10[1] = 0;
  v9 = 0;
  if ( v2 == 56710 )
  {
    result = (_BYTE *)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _BYTE *))rmnet_shs_header_ptr)(a1, 0, 40, v12);
    if ( result )
    {
      v5 = (unsigned __int8)result[6];
      if ( v5 <= 0x2B )
      {
        result = (_BYTE *)&unk_1;
        if ( v5 != 6 && v5 != 17 )
          goto LABEL_26;
      }
      else
      {
        if ( v5 == 44 )
        {
          if ( (*(_DWORD *)(a1 + 112) & 0xFFFFFFFE) == 0x28 )
            goto LABEL_26;
          result = (_BYTE *)skb_header_pointer(a1, &v9);
          if ( !result )
            goto LABEL_30;
          if ( *result != 50 )
            goto LABEL_26;
          goto LABEL_29;
        }
        if ( v5 == 50 )
          goto LABEL_29;
        if ( v5 != 58 )
        {
LABEL_26:
          result = nullptr;
          goto LABEL_30;
        }
        v6 = *(_DWORD *)(a1 + 129);
        *(_DWORD *)(a1 + 152) = 0;
        *(_DWORD *)(a1 + 129) = v6 | 0x400;
        result = nullptr;
      }
    }
  }
  else
  {
    result = nullptr;
    if ( v2 == 8 )
    {
      result = (_BYTE *)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))rmnet_shs_header_ptr)(
                          a1,
                          0,
                          20,
                          v10);
      if ( result )
      {
        v4 = (unsigned __int8)result[9];
        if ( (*((_WORD *)result + 3) & 0xFF3F) != 0 )
        {
          if ( v4 != 50 )
          {
            if ( v4 != 1 )
              goto LABEL_26;
            goto LABEL_21;
          }
LABEL_29:
          result = nullptr;
          v8 = *(_DWORD *)(a1 + 129) | 0x400;
          *(_DWORD *)(a1 + 152) = 11184810;
          *(_DWORD *)(a1 + 129) = v8;
          goto LABEL_30;
        }
        result = (_BYTE *)&unk_1;
        if ( v4 > 16 )
        {
          if ( v4 == 17 )
            goto LABEL_30;
          if ( v4 != 50 )
            goto LABEL_26;
          goto LABEL_29;
        }
        if ( v4 == 1 )
        {
LABEL_21:
          v7 = *(_DWORD *)(a1 + 129);
          *(_DWORD *)(a1 + 152) = 0;
          *(_DWORD *)(a1 + 129) = v7 | 0x400;
          result = nullptr;
          goto LABEL_30;
        }
        if ( v4 != 6 )
          goto LABEL_26;
      }
    }
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
