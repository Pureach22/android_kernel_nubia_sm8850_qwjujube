__int64 __fastcall lim_prepare_and_send_del_all_sta_cnf(__int64 result, int a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 v6; // x19
  unsigned int v7; // w22
  __int64 hash_entry; // x0
  __int64 v9; // x23
  char is_mlo_conn; // w0
  __int64 v11; // x1
  char v12; // w9
  int v13; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-18h]
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a3 + 88) == 1 )
  {
    v3 = *(unsigned __int16 *)(a3 + 376);
    v6 = result;
    v14 = 0;
    v15 = 0;
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
            (unsigned __int8 *)(hash_entry + 350),
            *(unsigned __int16 *)(hash_entry + 348),
            a3);
          is_mlo_conn = lim_is_mlo_conn(a3, v9);
          v11 = *(unsigned __int16 *)(v9 + 348);
          if ( (is_mlo_conn & 1) != 0 )
            lim_release_mlo_conn_idx(v6, v11, a3, 0);
          else
            lim_release_peer_idx(v6, v11, a3);
        }
        ++v7;
      }
      while ( v7 < *(unsigned __int16 *)(a3 + 376) );
    }
    v12 = *(_BYTE *)(a3 + 8);
    LOWORD(v14) = -1;
    v13 = -1;
    HIDWORD(v14) = a2;
    LOWORD(v15) = 4;
    BYTE4(v15) = v12;
    result = lim_process_mlm_rsp_messages(v6, 1018, &v13);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
