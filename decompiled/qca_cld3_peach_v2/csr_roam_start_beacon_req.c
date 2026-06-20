__int64 __fastcall csr_roam_start_beacon_req(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 result; // x0
  int v7; // [xsp+0h] [xbp-10h] BYREF
  __int16 v8; // [xsp+4h] [xbp-Ch]
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a2;
  v8 = WORD2(a2);
  v4 = _qdf_mem_malloc(0xCu, "csr_roam_start_beacon_req", 7157);
  if ( v4 )
  {
    *(_BYTE *)(v4 + 4) = a3;
    v5 = v4;
    *(_DWORD *)v4 = 791638;
    qdf_mem_copy((void *)(v4 + 5), &v7, 6u);
    result = umac_send_mb_message_to_mac(v5);
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
