__int64 __fastcall qmap_data_report_handler(__int64 result)
{
  __int64 v1; // x20
  _UNKNOWN **v2; // x19
  char v3; // w9
  char v4; // w10
  int v5; // w8
  _BYTE v6[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-28h]
  __int64 v8; // [xsp+10h] [xbp-20h]
  __int64 v9; // [xsp+18h] [xbp-18h]
  __int64 v10; // [xsp+20h] [xbp-10h]
  __int64 v11; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 112) >= 0x30u
    && (v1 = *(_QWORD *)(result + 224)) != 0
    && (v10 = 0, v9 = 0, v8 = 0, v7 = 0, *(_BYTE *)(v1 + 4) == 34)
    && (*(_BYTE *)(v1 + 5) & 3) == 1
    && *(unsigned __int8 *)(v1 + 15) <= 8u )
  {
    raw_spin_lock_bh(&data_report_lock);
    v2 = &data_report_req_list;
    do
    {
      v2 = (_UNKNOWN **)*v2;
      if ( v2 == &data_report_req_list )
      {
        result = raw_spin_unlock_bh(&data_report_lock);
        goto LABEL_21;
      }
    }
    while ( *((_DWORD *)v2 + 22) != *(_DWORD *)(v1 + 8) );
    list_del(v2);
    --data_report_count;
    result = raw_spin_unlock_bh(&data_report_lock);
    if ( !v2 )
      goto LABEL_21;
    v3 = *(_BYTE *)(v1 + 13);
    v4 = *(_BYTE *)(v1 + 14);
    v6[0] = *(_BYTE *)(v1 + 1);
    v5 = *(unsigned __int8 *)(v1 + 15);
    v6[1] = v3;
    v6[2] = v4;
    v6[3] = v5;
    if ( !v5 )
      goto LABEL_19;
    LODWORD(v7) = bswap32(*(_DWORD *)(v1 + 16));
    if ( v5 == 1
      || (HIDWORD(v7) = bswap32(*(_DWORD *)(v1 + 20)), v5 == 2)
      || (LODWORD(v8) = bswap32(*(_DWORD *)(v1 + 24)), v5 == 3)
      || (HIDWORD(v8) = bswap32(*(_DWORD *)(v1 + 28)), v5 == 4)
      || (LODWORD(v9) = bswap32(*(_DWORD *)(v1 + 32)), v5 == 5)
      || (HIDWORD(v9) = bswap32(*(_DWORD *)(v1 + 36)), v5 == 6)
      || (LODWORD(v10) = bswap32(*(_DWORD *)(v1 + 40)), v5 == 7)
      || (HIDWORD(v10) = bswap32(*(_DWORD *)(v1 + 44)), v5 == 8) )
    {
LABEL_19:
      rmnet_aps_send_msg((__int64)(v2 + 2), 4u, 7u, 0x24u, (__int64)v6, 0x820u);
      result = kfree(v2);
      goto LABEL_21;
    }
    __break(0x5512u);
    return list_del(result);
  }
  else
  {
LABEL_21:
    _ReadStatusReg(SP_EL0);
  }
  return result;
}
