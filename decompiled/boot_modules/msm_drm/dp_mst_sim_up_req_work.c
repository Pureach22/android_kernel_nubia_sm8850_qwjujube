__int64 __fastcall dp_mst_sim_up_req_work(__int64 a1)
{
  __int64 *v2; // x21
  unsigned int v3; // w22
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 v8; // x10
  char v9; // w0
  int v10; // w8
  __int64 v11; // x0
  void (__fastcall *v12)(_QWORD); // x8
  __int64 result; // x0
  unsigned int v14; // [xsp+4h] [xbp-1Ch] BYREF
  __int16 v15; // [xsp+8h] [xbp-18h] BYREF
  __int64 v16; // [xsp+Ah] [xbp-16h]
  __int16 v17; // [xsp+12h] [xbp-Eh]
  char v18; // [xsp+14h] [xbp-Ch]
  char v19; // [xsp+15h] [xbp-Bh]
  char v20; // [xsp+16h] [xbp-Ah]
  char v21; // [xsp+17h] [xbp-9h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 **)(a1 + 32);
  mutex_lock(v2 + 86);
  if ( *((_DWORD *)v2 + 8) )
  {
    v3 = 0;
    do
    {
      if ( *((_DWORD *)v2 + 194) )
        break;
      if ( ((*(_DWORD *)(a1 + 40) >> v3) & 1) != 0 )
      {
        v4 = v2[3] + 48LL * (int)v3;
        *((_BYTE *)v2 + 410) = 2;
        *((_BYTE *)v2 + 411) = 16 * v3;
        v5 = *(_QWORD *)(v4 + 6);
        v6 = *(_QWORD *)(v4 + 14);
        v17 = 0;
        v16 = 0;
        *(__int64 *)((char *)v2 + 412) = v5;
        *(__int64 *)((char *)v2 + 420) = v6;
        LOBYTE(v5) = *(_BYTE *)(v4 + 2);
        LOBYTE(v6) = *(_BYTE *)(v4 + 4);
        v15 = 1;
        v21 = 0;
        v18 = 20;
        v20 = 1;
        LOBYTE(v5) = (32 * v5) | ((_BYTE)v6 << 6);
        LOBYTE(v6) = *(_BYTE *)(v4 + 1);
        v19 = 1;
        LOBYTE(v5) = v5 & 0xF8 | (16 * v6) | (8 * *(_BYTE *)v4) | *(_BYTE *)(v4 + 3) & 7;
        v7 = *(__int64 *)((char *)v2 + 410);
        v8 = *(__int64 *)((char *)v2 + 418);
        *((_BYTE *)v2 + 428) = v5;
        LODWORD(v5) = *(_DWORD *)((char *)v2 + 425);
        *(__int64 *)((char *)v2 + 815) = v7;
        *(__int64 *)((char *)v2 + 823) = v8;
        *(_DWORD *)((char *)v2 + 830) = v5;
        dp_mst_sim_encode_sideband_msg_hdr((__int64)&v15, (_BYTE *)v2 + 812, &v14);
        v9 = dp_mst_sim_msg_data_crc4((__int64)v2 + 815, 0x13u);
        v10 = *((_DWORD *)v2 + 8);
        *((_BYTE *)v2 + 834) = v9;
        *(_WORD *)((char *)v2 + 781) = 32;
        *((_BYTE *)v2 + 780) = v10;
        mutex_unlock(v2 + 86);
        v11 = *v2;
        v12 = (void (__fastcall *)(_QWORD))v2[1];
        if ( *((_DWORD *)v12 - 1) != 251140989 )
          __break(0x8228u);
        v12(v11);
        while ( 1 )
        {
          mutex_lock(v2 + 86);
          if ( (*((_BYTE *)v2 + 781) & 0x20) == 0 || *((_DWORD *)v2 + 194) )
            break;
          mutex_unlock(v2 + 86);
          wait_for_completion(v2 + 92);
        }
      }
      ++v3;
    }
    while ( v3 < *((_DWORD *)v2 + 8) );
  }
  mutex_unlock(v2 + 86);
  result = kfree(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
