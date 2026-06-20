__int64 __fastcall p2p_del_all_rand_mac_vdev(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 i; // x25
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x28
  _QWORD *v14; // x24
  _QWORD *v15; // x21
  unsigned int v16; // w23
  __int64 v17; // x8
  __int64 v18; // [xsp+0h] [xbp-20h]
  __int64 v19; // [xsp+8h] [xbp-18h]
  int v20; // [xsp+10h] [xbp-10h] BYREF
  __int16 v21; // [xsp+14h] [xbp-Ch]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = result;
    v21 = 0;
    v20 = 0;
    result = wlan_objmgr_vdev_get_comp_private_obj(result, 5u);
    if ( result )
    {
      v2 = result;
      raw_spin_lock(result + 24);
      for ( i = 0; i != 4; ++i )
      {
        v13 = v2 + 40 + 216 * i;
        if ( *(_BYTE *)(v13 + 8) == 1 )
        {
          v14 = *(_QWORD **)(v13 + 192);
          if ( v14 != (_QWORD *)(v13 + 192) )
          {
            do
            {
              v15 = (_QWORD *)*v14;
              qdf_list_remove_node(v13 + 192, v14);
              _qdf_mem_free((__int64)v14);
              v14 = v15;
            }
            while ( v15 != (_QWORD *)(v13 + 192) );
          }
          v16 = *(_DWORD *)(v13 + 16);
          *(_BYTE *)(v13 + 8) = 0;
          qdf_mem_copy(&v20, (const void *)(v13 + 9), 6u);
          raw_spin_unlock(v2 + 24);
          qdf_mc_timer_stop(v13 + 24);
          v17 = *(_QWORD *)(v1 + 152);
          if ( v17 )
            v4 = *(_QWORD *)(v17 + 80);
          else
            v4 = 0;
          p2p_set_mac_filter(v4, *(unsigned __int8 *)(v1 + 104), &v20, v16, 0, 0, 0);
          LODWORD(v18) = BYTE2(v20);
          LODWORD(v19) = HIBYTE(v21);
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: random_mac:delall vdev %d freq %d addr %02x:%02x:%02x:**:**:%02x",
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            "p2p_del_all_rand_mac_vdev",
            *(unsigned __int8 *)(v1 + 104),
            v16,
            (unsigned __int8)v20,
            BYTE1(v20),
            v18,
            v19);
          raw_spin_lock(v2 + 24);
        }
      }
      result = raw_spin_unlock(v2 + 24);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
