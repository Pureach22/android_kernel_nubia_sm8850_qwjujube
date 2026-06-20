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
  unsigned int v16; // w21
  __int64 cmpt_obj; // x0
  size_t v18; // x2
  int *v19; // x22
  int v20; // t1
  int v21; // w9
  _QWORD *v23; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v24[3]; // [xsp+8h] [xbp-18h] BYREF

  v24[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = nullptr;
  v24[0] = 0;
  if ( (~a2 & 0xF000000) != 0 )
  {
    v16 = 4;
  }
  else
  {
    cm_req_lock_acquire((__int64)a1);
    qdf_list_peek_front(a1 + 12, v24);
    v6 = (_QWORD *)v24[0];
    if ( v24[0] )
    {
      while ( 1 )
      {
        qdf_list_peek_next(a1 + 12, v6, &v23);
        v15 = v24[0];
        if ( *(_DWORD *)(v24[0] + 16LL) == a2 )
          break;
        v6 = v23;
        v23 = nullptr;
        v24[0] = v6;
        if ( !v6 )
          goto LABEL_5;
      }
      *(_DWORD *)(a3 + 48) = *(_DWORD *)(v24[0] + 52LL);
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*a1, v7, v8, v9, v10, v11, v12, v13, v14);
      if ( cmpt_obj )
      {
        v18 = *(unsigned __int8 *)(cmpt_obj + 162);
        if ( *(_BYTE *)(cmpt_obj + 162) )
        {
          *(_BYTE *)(a3 + 14) = v18;
          qdf_mem_copy((void *)(a3 + 15), (const void *)(cmpt_obj + 129), v18);
        }
        else
        {
          *(_BYTE *)(a3 + 14) = 0;
        }
      }
      v20 = *(_DWORD *)(v15 + 40);
      v19 = (int *)(v15 + 40);
      v16 = 0;
      if ( v20 | *((unsigned __int16 *)v19 + 2) )
      {
        v21 = *v19;
        *(_WORD *)(a3 + 12) = *((_WORD *)v19 + 2);
        *(_DWORD *)(a3 + 8) = v21;
      }
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
