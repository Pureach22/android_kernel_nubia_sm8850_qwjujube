__int64 __fastcall csr_roam_send_chan_sw_ie_request(
        __int64 a1,
        __int64 a2,
        int a3,
        char a4,
        const void *a5,
        int a6,
        char a7,
        char a8)
{
  __int64 v15; // x0
  char v16; // w8
  __int64 v17; // x20
  __int64 result; // x0
  int v19; // [xsp+0h] [xbp-10h] BYREF
  __int16 v20; // [xsp+4h] [xbp-Ch]
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = a2;
  v20 = WORD2(a2);
  v15 = _qdf_mem_malloc(0x30u, "csr_roam_send_chan_sw_ie_request", 7411);
  if ( v15 )
  {
    *(_BYTE *)(v15 + 8) = a4;
    *(_BYTE *)(v15 + 40) = a7;
    *(_DWORD *)v15 = 3150935;
    *(_DWORD *)(v15 + 4) = a3;
    if ( *(_BYTE *)(a1 + 14986) )
    {
      *(_BYTE *)(v15 + 40) = *(_BYTE *)(a1 + 14986);
      *(_BYTE *)(a1 + 14986) = 0;
    }
    *(_BYTE *)(v15 + 41) = a8;
    v16 = *(_BYTE *)(a1 + 14883);
    *(_DWORD *)(v15 + 44) = a6;
    v17 = v15;
    *(_BYTE *)(v15 + 42) = v16;
    qdf_mem_copy((void *)(v15 + 9), &v19, 6u);
    qdf_mem_copy((void *)(v17 + 16), a5, 0x18u);
    result = umac_send_mb_message_to_mac(v17);
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
