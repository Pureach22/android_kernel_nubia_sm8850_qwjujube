__int64 __fastcall cm_fill_bss_info_in_roam_rsp_by_cm_id(__int64 *a1, int a2, __int64 a3)
{
  _QWORD *v6; // x1
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  unsigned int v16; // w20
  __int64 cmpt_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  size_t v26; // x2
  __int64 v27; // x9
  int v28; // w8
  _QWORD *v30; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v31[3]; // [xsp+8h] [xbp-18h] BYREF

  v31[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = nullptr;
  v31[0] = 0;
  if ( (~a2 & 0xF000000) != 0 )
  {
    v16 = 4;
  }
  else
  {
    cm_req_lock_acquire((__int64)a1);
    qdf_list_peek_front(a1 + 12, v31);
    v6 = (_QWORD *)v31[0];
    if ( v31[0] )
    {
      while ( 1 )
      {
        qdf_list_peek_next(a1 + 12, v6, &v30);
        v15 = v31[0];
        if ( *(_DWORD *)(v31[0] + 16LL) == a2 )
          break;
        v6 = v30;
        v30 = nullptr;
        v31[0] = v6;
        if ( !v6 )
          goto LABEL_5;
      }
      *(_DWORD *)(a3 + 48) = *(_DWORD *)(v31[0] + 52LL);
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*a1, v7, v8, v9, v10, v11, v12, v13, v14);
      if ( cmpt_obj )
      {
        v26 = *(unsigned __int8 *)(cmpt_obj + 178);
        if ( *(_BYTE *)(cmpt_obj + 178) )
        {
          *(_BYTE *)(a3 + 14) = v26;
          qdf_mem_copy((void *)(a3 + 15), (const void *)(cmpt_obj + 145), v26);
        }
        else
        {
          *(_BYTE *)(a3 + 14) = 0;
        }
      }
      if ( *(_DWORD *)(v15 + 40) | *(unsigned __int16 *)(v15 + 44) )
      {
        v27 = *(_QWORD *)(v15 + 144);
        v28 = *(_DWORD *)(v15 + 40);
        *(_WORD *)(a3 + 12) = *(_WORD *)(v15 + 44);
        *(_DWORD *)(a3 + 8) = v28;
        if ( v27 )
          cm_connect_resp_fill_mld_addr_from_candidate(
            *a1,
            *(_QWORD *)(v27 + 24),
            a3,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25);
      }
      v16 = 0;
    }
    else
    {
LABEL_5:
      v16 = 16;
    }
    cm_req_lock_release((__int64)a1);
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
