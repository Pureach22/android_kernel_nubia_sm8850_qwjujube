__int64 __fastcall dp_mon_drop_packets_for_mac(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  unsigned __int8 *v4; // x26
  unsigned int v5; // w25
  __int64 v6; // x21
  __int64 v7; // x28
  __int64 v8; // x23
  unsigned int v9; // w8
  unsigned int v10; // w22
  __int64 v11; // x24
  unsigned int *v12; // x27
  void (__fastcall *v13)(unsigned int *, __int64 *); // x8
  __int64 *v14; // x8
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x27
  __int64 v25; // x0
  __int64 v26; // x20
  __int64 v27; // x24
  __int64 v28; // x21
  __int64 v29; // x28
  unsigned int v30; // w23
  unsigned int v31; // w22
  unsigned __int8 *v32; // x25
  __int64 v33; // x26
  __int64 v34; // x0
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  char v44; // w9
  __int64 v45; // x8
  __int64 v46; // x2
  __int64 v47; // x1
  void (__fastcall *v48)(unsigned int *, __int64, __int64, __int64); // x8
  __int64 v49; // x3
  int v50; // w11
  unsigned int v51; // w10
  int v52; // w9
  _QWORD *v53; // x8
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v57; // x20
  char v58; // w9
  char v59; // w8
  __int64 *v60; // x9
  __int64 v61; // x3
  _DWORD *v62; // x8
  char v63; // [xsp+4h] [xbp-5Ch]
  __int64 v64; // [xsp+8h] [xbp-58h]
  unsigned int v65; // [xsp+14h] [xbp-4Ch]
  __int64 v66; // [xsp+18h] [xbp-48h]
  __int64 v67; // [xsp+20h] [xbp-40h]
  unsigned int *v68; // [xsp+28h] [xbp-38h]
  __int64 *v69; // [xsp+30h] [xbp-30h]
  __int64 *v70; // [xsp+38h] [xbp-28h] BYREF
  __int64 *v71; // [xsp+40h] [xbp-20h] BYREF
  __int64 v72; // [xsp+48h] [xbp-18h] BYREF
  __int64 v73; // [xsp+50h] [xbp-10h]
  __int64 v74; // [xsp+58h] [xbp-8h]

  v65 = a3;
  v4 = (unsigned __int8 *)a1;
  v5 = a2;
  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 8);
  if ( !v6 )
    goto LABEL_56;
  v7 = *(_QWORD *)(v6 + 1128);
  if ( !v7 )
    goto LABEL_56;
  if ( (unsigned int)a2 < 2 )
  {
    v8 = *(_QWORD *)(v6 + 80LL * (unsigned int)a2 + 800);
    if ( v8 && *(_BYTE *)(v8 + 1) )
    {
      v63 = a4;
      if ( (unsigned int)hal_srng_access_start_3(*(_QWORD *)(v6 + 1128), v8) )
      {
        v10 = 0;
        goto LABEL_44;
      }
      v9 = (unsigned int)(*(_DWORD *)(v8 + 44) + *(_DWORD *)(v8 + 120)) % *(_DWORD *)(v8 + 36);
      if ( v9 == *(_DWORD *)(v8 + 136) )
      {
        v10 = 0;
      }
      else
      {
        v11 = v6 + 11888 + 120LL * v5;
        v10 = 0;
        v64 = v6 + 11888;
        do
        {
          v12 = (unsigned int *)(*(_QWORD *)(v8 + 16) + 4LL * v9);
          if ( !v12 || v10 > 0x3F )
            break;
          if ( v65 == v10 )
          {
            v10 = v65;
            break;
          }
          v72 = 0;
          v73 = 0;
          if ( *v12 | (unsigned __int64)*((unsigned __int8 *)v12 + 4) )
          {
            v13 = *(void (__fastcall **)(unsigned int *, __int64 *))(*(_QWORD *)(*(_QWORD *)(v6 + 1128) + 74392LL)
                                                                   + 1456LL);
            if ( *((_DWORD *)v13 - 1) != -621572614 )
              __break(0x8228u);
            v13(v12, &v72);
            if ( (v73 & 0xE0000) != 0
              || (v14 = (__int64 *)(*(_QWORD *)(*(_QWORD *)(v64
                                                          + 120 * (((unsigned __int64)(unsigned int)v73 >> 16) & 1)
                                                          + 24)
                                              + 8LL * BYTE1(v73))
                                  + (unsigned __int8)v73
                                  * (unsigned int)*(unsigned __int16 *)(v64
                                                                      + 120
                                                                      * (((unsigned __int64)(unsigned int)v73 >> 16) & 1)
                                                                      + 4))) == nullptr )
            {
              v54 = printk(
                      &unk_9BB309,
                      "rx_desc",
                      "dp_mon_status_srng_drop_for_mac",
                      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/1.0/dp_rx_mon_status_1.0.c");
              dump_stack(v54);
              v14 = nullptr;
            }
            v15 = *v14;
            v69 = v14;
            _qdf_nbuf_sync_for_cpu(*(_QWORD *)(v6 + 24), *v14);
            if ( (**(_DWORD **)(v15 + 224) & 0x3FE) != 0x24C
              && !(unsigned int)dp_rx_mon_handle_status_buf_done(
                                  (__int64)v4,
                                  v8,
                                  v5,
                                  v16,
                                  v17,
                                  v18,
                                  v19,
                                  v20,
                                  v21,
                                  v22,
                                  v23) )
            {
              break;
            }
            v67 = *(_QWORD *)(v6 + 24);
            v68 = v12;
            v24 = *(_QWORD *)(v15 + 40);
            v66 = *(unsigned __int16 *)(v11 + 74);
            if ( (_qdf_is_pp_nbuf(v15) & 1) != 0 && *(_QWORD *)(v15 + 40) )
            {
              v25 = *(_QWORD *)(v67 + 40);
              if ( (*(_BYTE *)(v25 + 844) & 0x40) == 0 )
                _dma_sync_single_for_cpu(v25, v24);
            }
            else if ( v24 )
            {
              v26 = v11;
              v27 = v6;
              v28 = v7;
              v29 = v8;
              v30 = v10;
              v31 = v5;
              v32 = v4;
              v33 = *(int *)(v15 + 212);
              qdf_mem_dp_rx_skb_cnt_dec();
              qdf_mem_dp_rx_skb_dec(v33);
              v34 = v33;
              v4 = v32;
              v5 = v31;
              v10 = v30;
              v8 = v29;
              v7 = v28;
              v6 = v27;
              v11 = v26;
              qdf_mem_skb_total_dec(v34);
              dma_unmap_page_attrs(*(_QWORD *)(v67 + 40), v24, v66, 2, 0);
            }
            if ( v15 )
              _qdf_nbuf_free(v15);
            v12 = v68;
          }
          else
          {
            qdf_spin_lock_bh_14(v11 + 56);
            v53 = *(_QWORD **)(v11 + 48);
            if ( !v53 )
            {
              qdf_spin_unlock_bh_16(v11 + 56);
              break;
            }
            v69 = *(__int64 **)(v11 + 48);
            *(_QWORD *)(v11 + 48) = *v53;
            qdf_spin_unlock_bh_16(v11 + 56);
          }
          v35 = dp_rx_nbuf_prepare(v6, v4);
          if ( !v35 )
          {
            v70 = nullptr;
            v71 = nullptr;
            v57 = jiffies;
            if ( dp_mon_status_srng_drop_for_mac___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: fail to allocate or map nbuf",
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                "dp_mon_status_srng_drop_for_mac");
              dp_mon_status_srng_drop_for_mac___last_ticks = v57;
            }
            *v69 = 0;
            v58 = *((_BYTE *)v69 + 30);
            *v69 = (__int64)v71;
            v59 = v58 & 0xFE;
            v60 = v70;
            *((_BYTE *)v69 + 30) = v59;
            v71 = v69;
            if ( !v60 || !*v69 )
              v70 = v69;
            dp_rx_add_desc_list_to_free_list(v6, &v71, &v70, v5, v11);
            v61 = (unsigned int)*(unsigned __int8 *)(v6 + 20004) + 3;
            v62 = *(_DWORD **)(*(_QWORD *)(v7 + 74392) + 1472LL);
            if ( *(v62 - 1) != -1494657337 )
              __break(0x8228u);
            ((void (__fastcall *)(unsigned int *, _QWORD, _QWORD, __int64))v62)(v12, 0, 0, v61);
            break;
          }
          v44 = *((_BYTE *)v69 + 30);
          v45 = 80;
          if ( (*(_BYTE *)(v35 + 68) & 4) == 0 )
            v45 = 40;
          v46 = *((unsigned int *)v69 + 6);
          v47 = *(_QWORD *)(v35 + v45);
          *v69 = v35;
          *((_BYTE *)v69 + 30) = v44 | 1;
          v48 = *(void (__fastcall **)(unsigned int *, __int64, __int64, __int64))(*(_QWORD *)(v7 + 74392) + 1472LL);
          v49 = (unsigned int)*(unsigned __int8 *)(v6 + 20004) + 3;
          if ( *((_DWORD *)v48 - 1) != -1494657337 )
            __break(0x8228u);
          v48(v12, v47, v46, v49);
          v50 = *(_DWORD *)(v8 + 44);
          v51 = *(_DWORD *)(v8 + 36);
          v9 = (v50 + *(_DWORD *)(v8 + 120)) % v51;
          v52 = *(_DWORD *)(v8 + 136);
          if ( v9 != v52 )
          {
            *(_DWORD *)(v8 + 120) = v9;
            *(_DWORD *)(v8 + 124) = v9;
            v9 = (v9 + v50) % v51;
          }
          ++v10;
        }
        while ( v9 != v52 );
      }
      if ( (*(_DWORD *)(v8 + 76) & 0x80000000) != 0 )
      {
        **(_DWORD **)(v8 + 144) = *(_DWORD *)(v8 + 120);
        v55 = *(_QWORD *)(v8 + 88);
        if ( (v55 & 1) == 0 )
          goto LABEL_43;
      }
      else
      {
        hal_delayed_reg_write(v7, (unsigned __int8 *)v8, *(_QWORD *)(v8 + 144), *(_DWORD *)(v8 + 120));
        v55 = *(_QWORD *)(v8 + 88);
        if ( (v55 & 1) == 0 )
        {
LABEL_43:
          raw_spin_unlock(v8 + 80);
LABEL_44:
          a4 = v63;
LABEL_45:
          dp_mon_dest_srng_drop_for_mac(v4, v5, a4 & 1);
          _ReadStatusReg(SP_EL0);
          return v10;
        }
      }
      *(_QWORD *)(v8 + 88) = v55 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v8 + 80);
      goto LABEL_44;
    }
LABEL_56:
    v10 = 0;
    goto LABEL_45;
  }
  __break(0x5512u);
  return qdf_nbuf_unmap_nbytes_single_0(a1, a2, a3);
}
