__int64 __fastcall dp_rx_wbm_err_reap_desc_be(__int64 a1, __int64 a2, __int64 a3, int a4, _DWORD *a5)
{
  __int64 v7; // x21
  __int64 v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w24
  unsigned int v19; // w20
  int v20; // w8
  char v21; // w11
  __int64 v22; // x22
  unsigned int v23; // w9
  unsigned int *v30; // x23
  unsigned __int64 v31; // x28
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int64 v40; // x20
  __int64 v41; // x22
  __int64 v42; // x20
  __int64 v43; // x2
  unsigned __int16 *v44; // x20
  unsigned int v45; // t1
  int v46; // w8
  __int64 v47; // x1
  int v48; // w21
  __int64 v49; // x24
  __int64 v50; // x27
  __int64 v51; // x26
  __int64 v52; // x20
  __int64 v53; // x8
  unsigned int v54; // w24
  unsigned int v55; // w20
  int v56; // w24
  int v57; // w27
  int v58; // w8
  char v59; // w9
  char v60; // w9
  __int64 v61; // x9
  unsigned __int64 *v62; // x9
  __int64 v63; // t1
  unsigned __int64 v64; // x11
  unsigned __int64 v65; // x10
  __int64 v66; // x10
  __int64 v67; // x9
  int v68; // w8
  unsigned __int64 v69; // x9
  unsigned __int64 v70; // x8
  __int64 v71; // x8
  __int64 v72; // x8
  char v73; // w9
  unsigned __int64 v74; // x10
  __int64 v75; // x0
  __int64 v76; // x20
  __int64 v77; // x0
  __int64 (__fastcall *v78)(_QWORD); // x8
  __int64 v79; // x0
  __int64 (__fastcall *v80)(_QWORD); // x8
  _DWORD *v82; // [xsp+10h] [xbp-70h]
  __int64 *v84; // [xsp+20h] [xbp-60h]
  __int64 v85; // [xsp+28h] [xbp-58h]
  _QWORD *v86; // [xsp+30h] [xbp-50h]
  unsigned __int64 StatusReg; // [xsp+38h] [xbp-48h]
  __int64 v88; // [xsp+40h] [xbp-40h]
  char v89; // [xsp+4Ch] [xbp-34h]
  __int64 v90; // [xsp+58h] [xbp-28h]
  int v91; // [xsp+60h] [xbp-20h]
  unsigned int v92; // [xsp+64h] [xbp-1Ch] BYREF
  unsigned __int64 v93; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v94[2]; // [xsp+70h] [xbp-10h] BYREF

  v7 = a3;
  v94[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a2 + 1128);
  v93 = 0;
  v94[0] = 0;
  v92 = 0;
  v85 = v9;
  if ( (unsigned int)dp_srng_access_start(a1, a2, a3) )
  {
    qdf_trace_msg(
      0x82u,
      2u,
      "%s: %pK: HAL RING Access Failed -- %pK",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_rx_wbm_err_reap_desc_be",
      a2,
      v7);
    goto LABEL_99;
  }
  if ( !a4 )
  {
LABEL_99:
    dp_srng_access_end(a1, a2, v7);
    v88 = 0;
    goto LABEL_97;
  }
  v82 = a5;
  v18 = 0;
  v89 = 0;
  v86 = nullptr;
  v88 = 0;
  v84 = (__int64 *)(a2 + 18792);
  StatusReg = _ReadStatusReg(SP_EL0);
  v90 = v7;
  while ( 1 )
  {
    v19 = *(_DWORD *)(v7 + 120);
    if ( v19 == *(_DWORD *)(v7 + 136) )
      break;
    v20 = *(_DWORD *)(v7 + 44);
    v21 = *(_BYTE *)(v7 + 78);
    v22 = *(_QWORD *)(v7 + 16);
    if ( v20 + v19 == *(_DWORD *)(v7 + 36) )
      v23 = 0;
    else
      v23 = v20 + v19;
    *(_DWORD *)(v7 + 120) = v23;
    if ( (v21 & 4) != 0 )
    {
      _X23 = v22 + 4LL * v23;
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v85 + 8) + 40LL) + 844LL) & 0x40) == 0 )
        _dma_sync_single_for_cpu();
      __asm { PRFM            #0, [X23] }
    }
    v30 = (unsigned int *)(v22 + 4LL * v19);
    if ( !v30 )
      break;
    if ( (v30[2] & 0x10000) != 0 )
      v31 = *v30 | ((unsigned __int64)v30[1] << 32);
    else
      v31 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 22608) + 24LL * (v30[1] >> 21))
                      + (((unsigned __int64)v30[1] >> 9) & 0xFF8));
    if ( v31 )
    {
      if ( (*(_BYTE *)(v31 + 30) & 1) != 0 )
      {
        if ( (unsigned int)dp_rx_wbm_desc_nbuf_sanity_check(a2, v7, v22 + 4LL * v19, v31) )
        {
          if ( a2 )
            ++*(_DWORD *)(a2 + 14164);
          v76 = jiffies;
          if ( dp_rx_wbm_err_reap_desc_be___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: Rx error Nbuf %pK sanity check failure!",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "dp_rx_wbm_err_reap_desc_be",
              *(_QWORD *)v31);
            dp_rx_wbm_err_reap_desc_be___last_ticks = v76;
          }
          *(_BYTE *)(v31 + 30) |= 4u;
        }
        else
        {
          v40 = *(unsigned __int8 *)(v31 + 28);
          if ( v40 >= 5 )
            goto LABEL_100;
          v41 = *(_QWORD *)v31;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(a2 + 18520);
          }
          else
          {
            raw_spin_lock_bh(a2 + 18520);
            *(_QWORD *)(a2 + 18528) |= 1uLL;
          }
          v42 = a2 + 12416 + 120LL * (unsigned int)v40;
          v45 = *(unsigned __int16 *)(v42 + 74);
          v44 = (unsigned __int16 *)(v42 + 74);
          v43 = v45;
          if ( (*(_BYTE *)(*(_QWORD *)(a2 + 40) + 831LL) & 1) != 0 )
            goto LABEL_35;
          v46 = *(_DWORD *)(v41 + 48);
          if ( *(_DWORD *)(a2 + 20264) )
          {
            if ( (v46 & 0x2000000) == 0 )
            {
              if ( a2 )
                ++*(_DWORD *)(a2 + 14084);
              goto LABEL_35;
            }
          }
          else
          {
            if ( (v46 & 0x2000000) == 0 )
              goto LABEL_35;
            if ( a2 )
            {
              ++*(_DWORD *)(a2 + 14088);
              v46 = *(_DWORD *)(v41 + 48);
            }
          }
          v47 = *(_QWORD *)(v41 + 40);
          *(_DWORD *)(v41 + 48) = v46 & 0xFDFFFFFF;
          pld_audio_smmu_unmap(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 40LL), v47, v43);
          v43 = *v44;
LABEL_35:
          v91 = a4;
          v48 = v18;
          dp_ipa_handle_rx_buf_smmu_mapping(a2, v41, v43, 0, "dp_rx_nbuf_unmap_pool", 3162, 0);
          v49 = *(_QWORD *)(a2 + 24);
          v50 = *v44;
          v51 = *(_QWORD *)(v41 + 40);
          if ( (_qdf_is_pp_nbuf(v41) & 1) != 0 && *(_QWORD *)(v41 + 40) )
          {
            if ( (*(_BYTE *)(*(_QWORD *)(v49 + 40) + 844LL) & 0x40) == 0 )
              _dma_sync_single_for_cpu();
          }
          else if ( v51 )
          {
            v52 = *(int *)(v41 + 212);
            qdf_mem_dp_rx_skb_cnt_dec();
            qdf_mem_dp_rx_skb_dec(v52);
            qdf_mem_skb_total_dec(v52);
            dma_unmap_page_attrs(*(_QWORD *)(v49 + 40), v51, v50, 2, 0);
          }
          *(_BYTE *)(v31 + 30) |= 2u;
          v53 = *(_QWORD *)(a2 + 18528);
          if ( (v53 & 1) != 0 )
          {
            *(_QWORD *)(a2 + 18528) = v53 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 18520);
          }
          else
          {
            raw_spin_unlock(a2 + 18520);
          }
          v54 = v30[2];
          v55 = v54 & 0xFFFF9FFF | ((*(_BYTE *)(v31 + 28) & 3) << 13);
          dp_rx_set_wbm_err_info_in_nbuf(a2, v41, v55);
          v92 = v55;
          if ( (v54 & 0x1C0) != 0 )
          {
            v77 = printk(
                    &unk_AAA255,
                    "expr",
                    "__dp_assert_always_internal",
                    "/proc/self/cwd/vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
            dump_stack(v77);
            v18 = v48;
            a4 = v91;
            v7 = v90;
          }
          else
          {
            v56 = v48;
            if ( *(_BYTE *)(a2 + 18774) != 1 || (dp_rx_is_sg_formation_required(&v92) & 1) == 0 )
            {
              v57 = v91;
              v58 = 0;
              v59 = *(_BYTE *)(v41 + 84) & 0xFD;
              *(_BYTE *)(v41 + 84) = v59;
              goto LABEL_47;
            }
            v78 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 952LL);
            if ( *((_DWORD *)v78 - 1) != -2091637267 )
              __break(0x8228u);
            v57 = v91;
            v89 = v78(v30);
            if ( !v89 )
            {
              v89 = 0;
              v59 = *(_BYTE *)(v41 + 84) | 5;
              *(_BYTE *)(v41 + 84) = v59;
              *(_WORD *)(v41 + 60) = *(_DWORD *)(a2 + 18808);
              v58 = 1;
LABEL_47:
              v7 = v90;
              if ( *(_BYTE *)(v31 + 29) )
                goto LABEL_100;
              goto LABEL_48;
            }
            v7 = v90;
            if ( (*(_BYTE *)(a2 + 18784) & 1) == 0 )
            {
              v79 = *(_QWORD *)(v41 + 224);
              v80 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 1272LL);
              if ( *((_DWORD *)v80 - 1) != 855462014 )
                __break(0x8228u);
              *(_DWORD *)(a2 + 18808) = v80(v79);
              *(_BYTE *)(a2 + 18784) = 1;
            }
            v58 = 0;
            v59 = *(_BYTE *)(v41 + 84) | 2;
            *(_BYTE *)(v41 + 84) = v59;
            *(_WORD *)(v41 + 60) = *(_DWORD *)(a2 + 18808);
            if ( *(_BYTE *)(v31 + 29) )
LABEL_100:
              __break(0x5512u);
LABEL_48:
            if ( *(unsigned __int8 *)(v31 + 28) > 1u )
              goto LABEL_100;
            _ZF = (v59 & 2) == 0;
            v60 = v58 ^ 1;
            if ( !_ZF )
              v60 = 0;
            if ( (v60 & 1) != 0 )
            {
              if ( (((__int64 (__fastcall *)(__int64, __int64))dp_rx_buffer_pool_refill)(a2, v41) & 1) == 0 )
              {
                v66 = v88;
                if ( v88 )
                {
                  *v86 = v41;
                  v67 = *(_QWORD *)(v88 + 72);
                  v68 = v67 + 0x1000000;
                  v69 = v67 & 0xFFFFFFFF00FFFFFFLL;
                  v70 = v68 & 0xFF000000;
                }
                else
                {
                  v69 = 0x1000000;
                  v66 = v41;
                  v70 = *(_QWORD *)(v41 + 72) & 0xFFFFFFFF00FFFFFFLL;
                }
                v88 = v66;
                *(_QWORD *)(v66 + 72) = v70 | v69;
                *(_QWORD *)v41 = 0;
                v86 = (_QWORD *)v41;
              }
            }
            else
            {
              if ( *v84 )
              {
                **(_QWORD **)(a2 + 18800) = v41;
                v61 = *(_QWORD *)(a2 + 18792);
                v63 = *(_QWORD *)(v61 + 72);
                v62 = (unsigned __int64 *)(v61 + 72);
                v64 = v63 & 0xFFFFFFFF00FFFFFFLL;
                v65 = ((_DWORD)v63 + 0x1000000) & 0xFF000000;
              }
              else
              {
                *v84 = v41;
                v64 = 0x1000000;
                v62 = (unsigned __int64 *)(v41 + 72);
                v65 = *(_QWORD *)(v41 + 72) & 0xFFFFFFFF00FFFFFFLL;
              }
              *v62 = v65 | v64;
              *(_QWORD *)(a2 + 18800) = v41;
              *(_QWORD *)v41 = 0;
              if ( v58 )
              {
                if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))dp_rx_buffer_pool_refill)(
                        a2,
                        *(_QWORD *)(a2 + 18792),
                        *(unsigned __int8 *)(v31 + 28))
                    & 1) == 0 )
                {
                  v71 = *v84;
                  if ( v88 )
                  {
                    *v86 = v71;
                    *(_BYTE *)(v88 + 75) = (unsigned int)(*(_DWORD *)(v71 + 72) + (*(unsigned __int8 *)(v88 + 75) << 24)) >> 24;
                  }
                  else
                  {
                    v88 = *v84;
                  }
                  v86 = *(_QWORD **)(a2 + 18800);
                  *v86 = 0;
                }
                dp_rx_wbm_sg_list_last_msdu_war(a2);
                if ( a2 )
                {
                  *(_BYTE *)(a2 + 18784) = 0;
                  *v84 = 0;
                  *(_QWORD *)(a2 + 18800) = 0;
                  *(_DWORD *)(a2 + 18808) = 0;
                }
              }
            }
            if ( *(_BYTE *)(v31 + 29) || *(unsigned __int8 *)(v31 + 28) > 1u )
              goto LABEL_100;
            v72 = v94[0];
            v73 = *(_BYTE *)(v31 + 30);
            *(_QWORD *)v31 = v94[0];
            v74 = v93;
            *(_BYTE *)(v31 + 30) = v73 & 0xFE;
            v94[0] = v31;
            if ( !v74 || !v72 )
              v93 = v31;
            v18 = v56 + 1;
            a4 = v57 - (v89 == 0);
            if ( !a4 )
              break;
          }
        }
      }
      else
      {
        if ( a2 )
          ++*(_DWORD *)(a2 + 14060);
        dp_rx_dump_info_and_assert(a2, v7, v22 + 4LL * v19, v31);
      }
    }
    else
    {
      v75 = printk(
              &unk_AAA255,
              "expr",
              "__dp_assert_always_internal",
              "/proc/self/cwd/vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
      dump_stack(v75);
    }
  }
  dp_srng_access_end(a1, a2, v7);
  if ( v18 )
  {
    _dp_rx_buffers_replenish(a2, 0, a2 + 80, a2 + 12416, v18, v94, &v93, 0, 0, "dp_rx_buffers_replenish_simple");
    *v82 += v18;
  }
LABEL_97:
  _ReadStatusReg(SP_EL0);
  return v88;
}
