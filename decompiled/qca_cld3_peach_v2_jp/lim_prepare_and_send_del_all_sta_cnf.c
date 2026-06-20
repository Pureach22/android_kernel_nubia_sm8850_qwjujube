__int64 __fastcall lim_prepare_and_send_del_all_sta_cnf(__int64 result, int a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 v6; // x19
  unsigned int v7; // w22
  __int64 hash_entry; // x0
  __int64 v9; // x23
  char v10; // w9
  int v11; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-18h]
  __int64 v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a3 + 88) == 1 )
  {
    v3 = *(unsigned __int16 *)(a3 + 376);
    v6 = result;
    v12 = 0;
    v13 = 0;
    if ( v3 >= 2 )
    {
      v7 = 1;
      do
      {
        hash_entry = dph_get_hash_entry(v6, v7, a3 + 360);
        if ( hash_entry )
        {
          v9 = hash_entry;
          lim_delete_dph_hash_entry(
            v6,
            (unsigned __int8 *)(hash_entry + 338),
            *(unsigned __int16 *)(hash_entry + 336),
            a3);
          lim_release_peer_idx(v6, *(unsigned __int16 *)(v9 + 336), a3);
        }
        ++v7;
      }
      while ( v7 < *(unsigned __int16 *)(a3 + 376) );
    }
    v10 = *(_BYTE *)(a3 + 8);
    LOWORD(v12) = -1;
    v11 = -1;
    HIDWORD(v12) = a2;
    LOWORD(v13) = 4;
    BYTE4(v13) = v10;
    result = lim_process_mlm_rsp_messages(v6, 1018, &v11);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
