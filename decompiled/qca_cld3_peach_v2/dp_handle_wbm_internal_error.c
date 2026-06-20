__int64 __fastcall dp_handle_wbm_internal_error(__int64 result, unsigned int *a2, unsigned int a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 (__fastcall *v5)(unsigned int *, __int64 *); // x8
  __int64 v7; // x21
  __int64 (__fastcall *v8)(unsigned int *, __int64 *); // x8
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x1
  __int64 v11; // x20
  unsigned __int64 v12; // x8
  __int64 v13; // x22
  unsigned __int64 v14; // x8
  unsigned __int8 v15; // w8
  unsigned int v16; // w9
  __int64 v17; // x8
  void (__fastcall *v18)(unsigned int *, unsigned __int64 *); // x8
  unsigned int v19; // w21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x24
  __int64 v29; // x27
  unsigned __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  void (__fastcall *v33)(__int64 *, unsigned __int64, __int64, __int64); // x8
  double (__fastcall *v34)(__int64, unsigned __int64 *); // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w8
  __int64 *v44; // x8
  __int64 v45; // x10
  __int64 v46; // x8
  __int64 v47; // x26
  __int64 v48; // x22
  __int64 (__fastcall *v49)(__int64, __int64); // x8
  __int64 v50; // x1
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned __int64 v59; // x25
  __int64 v60; // x28
  __int64 v61; // x8
  unsigned __int8 v62; // w8
  __int64 v63; // x25
  __int64 v64; // x0
  __int64 v65; // [xsp+10h] [xbp-F0h]
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-E8h]
  __int64 v67; // [xsp+30h] [xbp-D0h] BYREF
  unsigned int *v68; // [xsp+38h] [xbp-C8h] BYREF
  __int64 v69; // [xsp+40h] [xbp-C0h] BYREF
  __int64 v70; // [xsp+48h] [xbp-B8h]
  unsigned __int64 v71; // [xsp+50h] [xbp-B0h] BYREF
  __int64 v72; // [xsp+58h] [xbp-A8h]
  unsigned __int16 v73; // [xsp+64h] [xbp-9Ch] BYREF
  __int64 v74; // [xsp+68h] [xbp-98h] BYREF
  _QWORD v75[6]; // [xsp+70h] [xbp-90h] BYREF
  _QWORD v76[12]; // [xsp+A0h] [xbp-60h] BYREF

  v3 = result;
  v76[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(result + 1128);
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = nullptr;
  v5 = *(__int64 (__fastcall **)(unsigned int *, __int64 *))(*(_QWORD *)(v4 + 74392) + 1464LL);
  if ( !v5 )
    goto LABEL_24;
  v7 = a3;
  if ( *((_DWORD *)v5 - 1) != 1721787685 )
    __break(0x8228u);
  result = v5(a2, &v69);
  if ( v69 )
  {
    v8 = *(__int64 (__fastcall **)(unsigned int *, __int64 *))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL) + 1456LL);
    if ( *((_DWORD *)v8 - 1) != -621572614 )
      __break(0x8228u);
    result = v8(a2, &v69);
    if ( (_DWORD)v7 == 1 )
    {
      v17 = *(_QWORD *)(v3 + 1128);
      memset(v76, 0, 80);
      memset(v75, 0, sizeof(v75));
      v73 = 0;
      v71 = 0;
      v72 = 0;
      v74 = 0;
      v18 = *(void (__fastcall **)(unsigned int *, unsigned __int64 *))(*(_QWORD *)(v17 + 74392) + 1456LL);
      v19 = a2[7] >> 28;
      if ( *((_DWORD *)v18 - 1) != -621572614 )
        __break(0x8228u);
      v18(a2, &v71);
      v71 = *a2 | ((unsigned __int64)*((unsigned __int8 *)a2 + 4) << 32);
      result = qdf_trace_msg(
                 0x45u,
                 8u,
                 "[%s][%d] ReoAddr=%pK, addrInfo=%pK, paddr=0x%llx, loopcnt=%d",
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 "hal_rx_reo_ent_buf_paddr_get",
                 427,
                 a2,
                 a2,
                 v19);
      v28 = 0;
      v7 = 0;
      v11 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v43 = ((unsigned int)v72 >> 5) & 0x3FF;
        if ( v43 >= *(unsigned __int16 *)(v3 + 1914) )
          break;
        v44 = (__int64 *)(*(_QWORD *)(v3 + 1920) + 24LL * v43);
        v45 = v44[2];
        v46 = *v44;
        if ( !(v46 + v71 - v45) )
          break;
        v65 = v46 + v71 - v45;
        hal_rx_msdu_list_get(*(_QWORD *)(v3 + 1128), v65, (__int64)v75, (__int16 *)&v73);
        if ( LODWORD(v76[0]) == 0x1FFFFF || (v12 = v73) == 0 )
        {
          v29 = v7;
        }
        else
        {
          v47 = 4LL * v73;
          v48 = 0;
          do
          {
            if ( v48 == 24 )
              goto LABEL_71;
            v49 = *(__int64 (__fastcall **)(__int64, __int64))(v3 + 1408);
            v50 = *(unsigned int *)((char *)v76 + v48);
            if ( *((_DWORD *)v49 - 1) != 207937137 )
              __break(0x8228u);
            v29 = v49(v3, v50);
            if ( !v29 )
            {
              v64 = printk(
                      &unk_AAA255,
                      "rx_desc",
                      "dp_wbm_int_err_mpdu_pop",
                      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
              dump_stack(v64);
            }
            v59 = *(unsigned __int8 *)(v29 + 28);
            if ( v59 > 4 )
              goto LABEL_71;
            if ( (*(_BYTE *)(v29 + 30) & 1) != 0 && (v60 = *(_QWORD *)v29) != 0 )
            {
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v3 + 18520);
              }
              else
              {
                raw_spin_lock_bh(v3 + 18520);
                *(_QWORD *)(v3 + 18528) |= 1uLL;
              }
              dp_rx_nbuf_unmap_pool(v3, v3 + 12416 + 120LL * (unsigned int)v59, v60);
              *(_BYTE *)(v29 + 30) |= 2u;
              v61 = *(_QWORD *)(v3 + 18528);
              if ( (v61 & 1) != 0 )
              {
                *(_QWORD *)(v3 + 18528) = v61 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v3 + 18520);
              }
              else
              {
                raw_spin_unlock(v3 + 18520);
              }
              dp_rx_buffer_pool_nbuf_free(v3, v60, *(unsigned __int8 *)(v29 + 28));
              v62 = *(_BYTE *)(v29 + 30);
              v11 = (unsigned int)(v11 + 1);
              *(_QWORD *)v29 = v7;
              v68 = (unsigned int *)v29;
              v12 = v62 & 0xFE;
              *(_BYTE *)(v29 + 30) = v12;
              if ( !v28 || !v7 )
              {
                v28 = v29;
                v67 = v29;
              }
            }
            else
            {
              v63 = jiffies;
              v12 = dp_wbm_int_err_mpdu_pop___last_ticks_86 - jiffies;
              if ( dp_wbm_int_err_mpdu_pop___last_ticks_86 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x82u,
                  5u,
                  "%s: Reaping rx_desc not in use!",
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  "dp_wbm_int_err_mpdu_pop");
                dp_wbm_int_err_mpdu_pop___last_ticks_86 = v63;
              }
              v29 = v7;
            }
            v48 += 4;
            v7 = v29;
          }
          while ( v47 != v48 );
        }
        v30 = v71;
        v31 = (unsigned int)v72;
        v32 = BYTE4(v72);
        v33 = *(void (__fastcall **)(__int64 *, unsigned __int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(v3 + 1128)
                                                                                               + 74392LL)
                                                                                   + 1472LL);
        if ( *((_DWORD *)v33 - 1) != -1494657337 )
          __break(0x8228u);
        v33(&v74, v30, v31, v32);
        v34 = *(double (__fastcall **)(__int64, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL)
                                                                   + 1456LL);
        if ( *((_DWORD *)v34 - 1) != -621572614 )
          __break(0x8228u);
        v35 = v34(v65 + 4, &v71);
        v71 = *(unsigned int *)(v65 + 4) | ((unsigned __int64)*(unsigned __int8 *)(v65 + 8) << 32);
        result = dp_rx_link_desc_return_by_addr(v3, (unsigned int *)&v74, 0, v35, v36, v37, v38, v39, v40, v41, v42);
        v7 = v29;
        if ( !v71 )
          goto LABEL_67;
      }
      if ( v3 )
        ++*(_DWORD *)(v3 + 13564);
LABEL_67:
      if ( (_DWORD)v11 )
        goto LABEL_68;
    }
    else if ( !(_DWORD)v7 )
    {
      if ( v3 )
        ++*(_DWORD *)(v3 + 13568);
      v9 = *(__int64 (__fastcall **)(__int64, __int64))(v3 + 1408);
      v10 = (unsigned int)v70;
      if ( *((_DWORD *)v9 - 1) != 207937137 )
        __break(0x8228u);
      result = v9(v3, v10);
      if ( result )
      {
        v11 = result;
        if ( *(_QWORD *)result )
        {
          v12 = *(unsigned __int8 *)(result + 28);
          if ( v12 > 4 )
            goto LABEL_71;
          v7 = 18520;
          v13 = v3 + 120LL * *(unsigned __int8 *)(result + 28);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (v14 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v14 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v3 + 18520);
          }
          else
          {
            raw_spin_lock_bh(v3 + 18520);
            *(_QWORD *)(v3 + 18528) |= 1uLL;
          }
          dp_rx_nbuf_unmap_pool(v3, v13 + 12416, *(_QWORD *)v11);
          *(_BYTE *)(v11 + 30) |= 2u;
          v12 = *(_QWORD *)(v3 + 18528);
          if ( (v12 & 1) != 0 )
            goto LABEL_72;
          raw_spin_unlock(v3 + 18520);
          while ( 1 )
          {
            dp_rx_buffer_pool_nbuf_free(v3, *(_QWORD *)v11, *(unsigned __int8 *)(v11 + 28));
            v15 = *(_BYTE *)(v11 + 30);
            v16 = *(unsigned __int8 *)(v11 + 28);
            *(_QWORD *)v11 = 0;
            v67 = v11;
            v68 = (unsigned int *)v11;
            v12 = v15 & 0xFE;
            *(_BYTE *)(v11 + 30) = v12;
            if ( v16 < 2 )
              break;
LABEL_71:
            __break(0x5512u);
LABEL_72:
            *(_QWORD *)(v3 + 18528) = v12 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v3 + v7);
          }
          LODWORD(v11) = 1;
LABEL_68:
          if ( v3 )
            ++*(_DWORD *)(v3 + 13572);
          result = _dp_rx_buffers_replenish(v3, 0, (__int64 *)(v3 + 80), v3 + 12416, v11, &v68, (__int64)&v67, 0, 0);
        }
      }
    }
  }
  else
  {
LABEL_24:
    if ( v3 )
      ++*(_DWORD *)(v3 + 13560);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
