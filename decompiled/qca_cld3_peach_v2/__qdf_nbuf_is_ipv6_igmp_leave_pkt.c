__int64 __fastcall _qdf_nbuf_is_ipv6_igmp_leave_pkt(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w9
  __int64 v3; // x19
  __int64 v4; // x20
  unsigned int v5; // w8
  __int64 v7; // x0
  __int64 v9; // x1
  __int64 v10; // x19
  unsigned int v11; // w20
  void (__fastcall *v12)(__int64); // x8
  unsigned __int8 *v13; // x9
  int v14; // w8
  __int64 v15; // x13
  unsigned int v16; // w8
  unsigned __int8 *v17; // x9
  unsigned __int8 *v18; // x14
  unsigned int v19; // w15
  bool v20; // cc
  int v21; // w15
  __int16 v23[2]; // [xsp+0h] [xbp-10h] BYREF
  char v24[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 224);
  v2 = *(unsigned __int16 *)(v1 + 12);
  if ( v2 == 129 )
  {
    v2 = *(unsigned __int16 *)(v1 + 16);
    v3 = 18;
  }
  else
  {
    v3 = 14;
  }
  if ( v2 != 56710 )
    goto LABEL_8;
  v23[0] = 0;
  v4 = v1 + v3;
  v5 = 0;
  if ( !*(_BYTE *)(v4 + 6) )
  {
    v5 = *(unsigned __int16 *)(v4 + 4);
    if ( *(_WORD *)(v4 + 4) )
    {
      v7 = skb_copy(a1, 2080);
      if ( !v7 )
      {
LABEL_8:
        v5 = 0;
        goto LABEL_9;
      }
      v9 = (unsigned int)(v3 + 40);
      v10 = v7;
      v24[0] = *(_BYTE *)(v4 + 6);
      v11 = ipv6_skip_exthdr(v7, v9, v24, v23);
      v12 = (void (__fastcall *)(__int64))nbuf_free_cb;
      if ( nbuf_free_cb )
      {
        if ( *((_DWORD *)nbuf_free_cb - 1) != 303786302 )
          __break(0x8228u);
        v12(v10);
      }
      else
      {
        dev_kfree_skb_any_reason(v10, 1);
      }
      v5 = 0;
      if ( (v11 & 0x80000000) == 0 && v24[0] == 58 )
      {
        v13 = (unsigned __int8 *)(*(_QWORD *)(a1 + 224) + v11);
        v14 = *v13;
        if ( v14 != 132 )
        {
          if ( v14 != 143 || !*((_WORD *)v13 + 3) )
            goto LABEL_8;
          v15 = 0;
          v16 = __rev16(*((unsigned __int16 *)v13 + 3));
          v17 = v13 + 8;
          while ( 1 )
          {
            v18 = &v17[(int)v15];
            v19 = *v18;
            v20 = v19 > 6;
            v21 = (1 << v19) & 0x4A;
            if ( !v20 && v21 != 0 )
              break;
            --v16;
            v15 = (((v15 << 32) + 0x1400000000LL) >> 32) + 16LL * (bswap32(*((unsigned __int16 *)v18 + 1)) >> 16);
            if ( !v16 )
              goto LABEL_8;
          }
        }
        v5 = 1;
      }
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v5;
}
