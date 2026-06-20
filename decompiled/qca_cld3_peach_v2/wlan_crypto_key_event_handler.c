__int64 __fastcall wlan_crypto_key_event_handler(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
  int v6; // w22
  __int64 v7; // x28
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w21
  unsigned int v17; // w21
  __int64 comp_private_obj; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x25
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x5
  __int64 v37; // x6
  __int64 v38; // x7
  int v39; // w8
  unsigned __int16 *v40; // x0
  unsigned __int16 *v41; // x27
  unsigned int v42; // w8
  unsigned int v43; // w21
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x10
  __int64 v53; // x4
  __int64 v54; // x5
  __int64 v55; // x6
  __int64 v56; // x7
  unsigned int v63; // w9
  __int64 v65; // [xsp+0h] [xbp-10h]

  v6 = a3;
  qdf_mutex_acquire((__int64)&crypto_lock);
  if ( v6 )
  {
    v7 = a3;
    while ( 1 )
    {
      v17 = a2[9];
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 14);
      if ( comp_private_obj )
      {
        v27 = comp_private_obj;
        qdf_mutex_acquire(comp_private_obj);
        if ( *(int *)(v27 + 64) >= 1024 )
        {
          if ( a2 )
          {
            v53 = *a2;
            v54 = a2[1];
            v55 = a2[2];
            v56 = a2[5];
          }
          else
          {
            v55 = 0;
            v53 = 0;
            v54 = 0;
            v56 = 0;
          }
          qdf_trace_msg(
            0x1Cu,
            2u,
            "%s: max crypto hash entry limit reached mac_addr: %02x:%02x:%02x:**:**:%02x",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wlan_crypto_add_key_entry",
            v53,
            v54,
            v55,
            v56);
        }
        else
        {
          if ( a2 )
          {
            v36 = *a2;
            v37 = a2[1];
            v38 = a2[2];
            v39 = a2[5];
          }
          else
          {
            v38 = 0;
            v36 = 0;
            v37 = 0;
            v39 = 0;
          }
          LODWORD(v65) = v39;
          qdf_trace_msg(
            0x1Cu,
            8u,
            "%s: crypto add entry link id %d mac_addr: %02x:%02x:%02x:**:**:%02x",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wlan_crypto_add_key_entry",
            v17,
            v36,
            v37,
            v38,
            v65);
          if ( crypto_hash_find_by_linkid_and_macaddr(v27, v17, a2) )
            wlan_crypto_free_key_by_link_id(a1, a2, v17);
          v40 = (unsigned __int16 *)_qdf_mem_malloc(0xA8u, "wlan_crypto_add_key_entry", 219);
          if ( v40 )
          {
            v41 = v40;
            memcpy(v40, a2, 0xA8u);
            v42 = *v41 ^ v17 ^ v41[1] ^ v41[2];
            v43 = ((v42 >> *(_DWORD *)(v27 + 76)) ^ v42) & *(_DWORD *)(v27 + 72);
            qdf_trace_msg(
              0x1Cu,
              8u,
              "%s: crypto hash add index %d ",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "crypto_hash_add",
              v43);
            qdf_mutex_acquire(v27);
            v52 = 16LL * v43;
            *((_QWORD *)v41 + 19) = 0;
            *((_QWORD *)v41 + 20) = *(_QWORD *)(*(_QWORD *)(v27 + 80) + v52 + 8);
            **(_QWORD **)(*(_QWORD *)(v27 + 80) + v52 + 8) = v41;
            *(_QWORD *)(*(_QWORD *)(v27 + 80) + v52 + 8) = v41 + 76;
            qdf_mutex_release(v27);
            _X8 = (unsigned int *)(v27 + 64);
            __asm { PRFM            #0x11, [X8] }
            do
              v63 = __ldxr(_X8);
            while ( __stxr(v63 + 1, _X8) );
            *((_BYTE *)v41 + 8) = 1;
            qdf_mutex_release(v27);
            v16 = 0;
            goto LABEL_5;
          }
        }
        qdf_mutex_release(v27);
        v16 = 2;
      }
      else
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: crypto_psoc_obj NULL",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "wlan_crypto_add_key_entry");
        v16 = 16;
      }
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: Failed to add key entry for link:%d",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wlan_crypto_key_event_handler",
        a2[9]);
      wlan_crypto_free_key(a2 + 16);
      qdf_mem_set(a2, 0xA8u, 0);
LABEL_5:
      --v7;
      a2 += 168;
      if ( !v7 )
        goto LABEL_23;
    }
  }
  v16 = 0;
LABEL_23:
  qdf_mutex_release((__int64)&crypto_lock);
  return v16;
}
