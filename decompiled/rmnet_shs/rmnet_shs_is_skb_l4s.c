bool __fastcall rmnet_shs_is_skb_l4s(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  __int64 v6; // x0
  char v7; // w8
  unsigned __int16 *v8; // x0
  __int64 v10; // [xsp+0h] [xbp-30h] BYREF
  __int64 v11; // [xsp+8h] [xbp-28h]
  __int64 v12; // [xsp+10h] [xbp-20h]
  __int64 v13; // [xsp+18h] [xbp-18h]
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int16 *)(a1 + 180);
  if ( v5 == 56710 )
  {
    v13 = 0;
    v14 = 0;
    v11 = 0;
    v12 = 0;
    v10 = 0;
    v8 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64 *, __int64))rmnet_shs_header_ptr)(
                               a1,
                               0,
                               40,
                               &v10,
                               a5);
    if ( v8 )
    {
      v7 = bswap32(*v8) >> 20;
      goto LABEL_8;
    }
LABEL_7:
    v7 = 0;
    goto LABEL_8;
  }
  if ( v5 != 8 )
    goto LABEL_7;
  LODWORD(v12) = 0;
  v10 = 0;
  v11 = 0;
  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))rmnet_shs_header_ptr)(a1, 0, 20);
  if ( !v6 )
    goto LABEL_7;
  v7 = *(_BYTE *)(v6 + 1);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return (v7 & 3) == 1;
}
