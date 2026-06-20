__int64 __fastcall dp_tx_comp_free_buf(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  int v12; // w8
  _QWORD *v15; // x9
  char v16; // w25
  __int64 v17; // x22
  __int64 v18; // x26
  __int64 v19; // x22
  __int64 v20; // x23
  __int64 v21; // x24
  __int64 v22; // x0
  unsigned __int8 v23; // w1
  __int64 ref_by_id_1; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w4
  unsigned int v43; // w23
  int v44; // w8
  __int64 v45; // x21
  __int64 v46; // x22
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // w8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x0
  _DWORD *v65; // x8
  double v66; // d0
  unsigned int *v67; // x8
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x23
  unsigned int *v76; // x8
  __int64 v78; // x22
  unsigned __int64 v79; // x8
  unsigned __int64 v80; // x1
  unsigned __int64 v81; // x8
  unsigned __int64 v82; // x1
  unsigned __int64 v83; // x8
  unsigned __int64 v84; // x1
  unsigned __int64 v85; // x8
  unsigned __int64 v86; // x1
  unsigned __int64 v87; // x8
  unsigned __int64 v88; // x1
  const char *v89; // x2
  __int64 v90; // x4
  __int64 v91; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 *v100; // x9
  int v101; // w9
  __int64 v102; // [xsp+0h] [xbp-20h] BYREF
  __int64 v103; // [xsp+8h] [xbp-18h]
  __int64 v104; // [xsp+10h] [xbp-10h]
  __int64 v105; // [xsp+18h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 8);
  if ( v11 )
  {
    v12 = *(_DWORD *)(a2 + 32);
    if ( (v12 & 0x100) != 0 )
    {
      v23 = *(_BYTE *)(a2 + 48);
      LODWORD(v104) = 0;
      v102 = 0;
      v103 = 0;
      ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, v23, 0x14u);
      if ( ref_by_id_1 )
      {
        v33 = ref_by_id_1;
        qdf_mem_copy(&v102, (const void *)(a2 + 112), 0x14u);
        v42 = *(unsigned __int16 *)(a1 + 20064);
        if ( v42 >= 2 )
        {
          if ( v42 == 2 )
          {
            v43 = BYTE4(v103) & 0xF;
          }
          else
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: Incorrect CDP_ARCH %d",
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "dp_htt_tx_comp_get_status",
              v102,
              v103,
              v104,
              v105);
            v43 = 7;
          }
        }
        else
        {
          v43 = 0;
        }
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: vdev_id: %d tx_status: %d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "dp_non_std_htt_tx_comp_free_buff",
          *(unsigned __int8 *)(a2 + 48),
          v43,
          v102,
          v103);
        if ( *(_QWORD *)(v33 + 304) )
        {
          *(_QWORD *)v11 = 0;
          v65 = *(_DWORD **)(v33 + 304);
          v64 = *(_QWORD *)(v33 + 312);
          if ( *(v65 - 1) != 498559462 )
            __break(0x8228u);
          v66 = ((double (__fastcall *)(__int64, __int64, _QWORD))v65)(v64, v11, v43);
          dp_vdev_unref_delete(a1, v33, 0x14u, v67, v66, v68, v69, v70, v71, v72, v73, v74);
          goto LABEL_40;
        }
        v75 = jiffies;
        v76 = (unsigned int *)(dp_non_std_htt_tx_comp_free_buff___last_ticks_96 - jiffies);
        if ( dp_non_std_htt_tx_comp_free_buff___last_ticks_96 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: callback func is null",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "dp_non_std_htt_tx_comp_free_buff");
          dp_non_std_htt_tx_comp_free_buff___last_ticks_96 = v75;
        }
        dp_vdev_unref_delete(a1, v33, 0x14u, v76, v56, v57, v58, v59, v60, v61, v62, v63);
      }
      else
      {
        v78 = jiffies;
        if ( dp_non_std_htt_tx_comp_free_buff___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: vdev is null!",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "dp_non_std_htt_tx_comp_free_buff",
            v102,
            v103,
            v104,
            v105);
          dp_non_std_htt_tx_comp_free_buff___last_ticks = v78;
        }
      }
      _qdf_nbuf_unmap_single(*(_QWORD *)(a1 + 24), v11, 1);
      goto LABEL_39;
    }
    v15 = *(_QWORD **)(a2 + 72);
    v16 = a3;
    if ( !v15 )
      goto LABEL_8;
    v17 = v15[1];
    if ( (*(_BYTE *)v17 & 1) != 0 )
    {
      v45 = v15[5];
      v46 = v15[6];
      qdf_trace_msg(0x45u, 0, "%s: Unmap the tso segment", a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_tso_unmap_segment");
      if ( v45 )
      {
        if ( v46 )
        {
          v55 = *(_DWORD *)(v46 + 8);
          a3 = v16;
          if ( v55 )
          {
            _qdf_nbuf_unmap_tso_segment(*(_QWORD *)(a1 + 24), v45, v55 == 1);
            a3 = v16;
            --*(_DWORD *)(v46 + 8);
          }
          goto LABEL_29;
        }
        v89 = "%s %d TSO num desc is NULL!";
        v90 = 472;
      }
      else
      {
        v89 = "%s %d TSO desc is NULL!";
        v90 = 468;
      }
      qdf_trace_msg(0x45u, 2u, v89, v47, v48, v49, v50, v51, v52, v53, v54, "dp_tx_tso_unmap_segment", v90);
      if ( (v16 & 1) != 0 )
        goto LABEL_41;
      goto LABEL_39;
    }
    if ( *(_BYTE *)(a2 + 65) == 2 )
    {
      qdf_nbuf_unmap_nbytes_single(
        *(_QWORD *)(a1 + 24),
        *(_QWORD *)(a2 + 8),
        (unsigned int)(*(_DWORD *)(v11 + 112) - *(_DWORD *)(v11 + 116)));
      v79 = *(unsigned int *)(v17 + 36);
      a3 = v16;
      if ( (unsigned int)v79 >= 0x10000 )
      {
        v80 = *(unsigned int *)(v17 + 32) | ((unsigned __int64)(unsigned __int8)*(_DWORD *)(v17 + 36) << 32);
        if ( v80 )
        {
          _qdf_mem_unmap_page(*(_QWORD *)(a1 + 24), v80, v79 >> 16, 1);
          v81 = *(unsigned int *)(v17 + 44);
          a3 = v16;
          if ( (unsigned int)v81 >= 0x10000 )
          {
            v82 = *(unsigned int *)(v17 + 40) | ((unsigned __int64)(unsigned __int8)*(_DWORD *)(v17 + 44) << 32);
            if ( v82 )
            {
              _qdf_mem_unmap_page(*(_QWORD *)(a1 + 24), v82, v81 >> 16, 1);
              v83 = *(unsigned int *)(v17 + 52);
              a3 = v16;
              if ( (unsigned int)v83 >= 0x10000 )
              {
                v84 = *(unsigned int *)(v17 + 48) | ((unsigned __int64)(unsigned __int8)*(_DWORD *)(v17 + 52) << 32);
                if ( v84 )
                {
                  _qdf_mem_unmap_page(*(_QWORD *)(a1 + 24), v84, v83 >> 16, 1);
                  v85 = *(unsigned int *)(v17 + 60);
                  a3 = v16;
                  if ( (unsigned int)v85 >= 0x10000 )
                  {
                    v86 = *(unsigned int *)(v17 + 56) | ((unsigned __int64)(unsigned __int8)*(_DWORD *)(v17 + 60) << 32);
                    if ( v86 )
                    {
                      _qdf_mem_unmap_page(*(_QWORD *)(a1 + 24), v86, v85 >> 16, 1);
                      v87 = *(unsigned int *)(v17 + 68);
                      a3 = v16;
                      if ( (unsigned int)v87 >= 0x10000 )
                      {
                        v88 = *(unsigned int *)(v17 + 64)
                            | ((unsigned __int64)(unsigned __int8)*(_DWORD *)(v17 + 68) << 32);
                        if ( v88 )
                        {
                          _qdf_mem_unmap_page(*(_QWORD *)(a1 + 24), v88, v87 >> 16, 1);
                          if ( (v16 & 1) != 0 )
                            goto LABEL_41;
                          goto LABEL_39;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    {
LABEL_8:
      if ( (v12 & 0x80) == 0
        || (*(_BYTE *)(v11 + 126) & 1) == 0
        || (unsigned __int16)*(_DWORD *)(*(_QWORD *)(v11 + 216) + *(unsigned int *)(v11 + 212) + 32LL) == 1 )
      {
        v18 = *(_QWORD *)(a1 + 24);
        v19 = *(_QWORD *)(a2 + 40);
        v20 = *(unsigned __int16 *)(a2 + 16);
        v21 = *(int *)(v11 + 212);
        qdf_mem_dp_tx_skb_cnt_dec();
        qdf_mem_dp_tx_skb_dec(v21);
        qdf_mem_skb_total_dec(v21);
        if ( *(_BYTE *)(v18 + 624) == 1 && (_qdf_is_pp_nbuf(v11) & 1) != 0 && *(_QWORD *)(v11 + 40) )
        {
          v22 = *(_QWORD *)(v18 + 40);
          if ( (*(_BYTE *)(v22 + 844) & 0x40) == 0 )
            _dma_sync_single_for_cpu(v22, v19);
        }
        else
        {
          dma_unmap_page_attrs(*(_QWORD *)(v18 + 40), v19, v20, 1, 0);
        }
        v44 = *(_DWORD *)(a2 + 32);
        if ( (v44 & 0x400) != 0 )
          goto LABEL_40;
        if ( (v44 & 0x4000) != 0 )
        {
          v91 = dp_vdev_get_ref_by_id_1(a1, *(_BYTE *)(a2 + 48), 1u);
          if ( v91 )
          {
            *(_QWORD *)v11 = 0;
            if ( *(_QWORD *)(v91 + 46144) )
              v100 = *(__int64 **)(v91 + 46152);
            else
              v100 = (__int64 *)(v91 + 46144);
            *v100 = v11;
            v101 = *(_DWORD *)(v91 + 46160);
            *(_QWORD *)(v91 + 46152) = v11;
            *(_DWORD *)(v91 + 46160) = v101 + 1;
            dp_vdev_unref_delete(a1, v91, 1u, (unsigned int *)(v91 + 45056), v92, v93, v94, v95, v96, v97, v98, v99);
            goto LABEL_40;
          }
        }
        if ( (v16 & 1) != 0 )
          goto LABEL_41;
LABEL_39:
        _qdf_nbuf_free(v11);
LABEL_40:
        v11 = 0;
        goto LABEL_41;
      }
    }
LABEL_29:
    if ( (a3 & 1) != 0 )
      goto LABEL_41;
    goto LABEL_39;
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v11;
}
