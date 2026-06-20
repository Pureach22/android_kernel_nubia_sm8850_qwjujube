__int64 __fastcall dp_event_eapol_log(__int64 result, int a2)
{
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x1
  __int16 v6; // w9
  char v7; // w8
  _BYTE v8[2]; // [xsp+4h] [xbp-1Ch] BYREF
  __int16 v9; // [xsp+6h] [xbp-1Ah]
  __int16 v10; // [xsp+8h] [xbp-18h]
  __int64 v11; // [xsp+Ah] [xbp-16h] BYREF
  int v12; // [xsp+12h] [xbp-Eh]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v3 = result;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 || (*(_BYTE *)(result + 71) & 0x78) == 8 )
  {
    v4 = *(_QWORD *)(result + 224);
    v12 = 0;
    v11 = 0;
    result = _qdf_nbuf_data_is_ipv4_eapol_pkt(v4);
    if ( (result & 1) != 0 )
    {
      v5 = *(_QWORD *)(v3 + 224);
      v6 = *(_WORD *)(v5 + 19);
      v8[0] = a2 != 0;
      v7 = *(_BYTE *)(v5 + 15);
      v10 = 0;
      v9 = v6;
      v8[1] = v7;
      qdf_mem_copy(&v11, (const void *)v5, 6u);
      qdf_mem_copy((char *)&v11 + 6, (const void *)(*(_QWORD *)(v3 + 224) + 6LL), 6u);
      result = host_diag_event_report_payload(2701, 18, v8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
