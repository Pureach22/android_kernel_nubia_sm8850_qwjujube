__int64 __fastcall wlan_mgmt_rx_srng_reap_buf(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x22
  __int64 pdev_wmi_handle; // x0
  __int64 v13; // x21
  unsigned int v14; // w9
  unsigned int v15; // w10
  unsigned int v16; // w8
  unsigned int v17; // w9
  __int64 v18; // x0
  int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w28
  __int64 v29; // x25
  __int64 v30; // x20
  const char *v31; // x27
  const char *v32; // x19
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  unsigned int v42; // w9
  __int64 v43; // x10
  __int64 v44; // x26
  const char *v45; // x23
  const char *v46; // x19
  void (__fastcall *v47)(__int64, __int64 *); // x8
  int v48; // w27
  __int64 v49; // x8
  __int64 v50; // x1
  __int64 v51; // x2
  _DWORD *v52; // x8
  int v53; // w8
  bool v54; // nf
  int v55; // w11
  __int64 v56; // x9
  int v57; // w8
  int v58; // w8
  int v59; // w9
  int v60; // w8
  int v61; // w9
  __int64 *v62; // x23
  __int64 v63; // x0
  __int64 v64; // x10
  int v65; // w8
  __int64 v66; // x9
  __int64 v67; // x9
  int v68; // w8
  unsigned __int64 v69; // x9
  unsigned __int64 v70; // x8
  const char *v71; // x2
  __int64 result; // x0
  __int64 v73; // x19
  __int64 v74; // x8
  unsigned int v75; // w9
  __int64 v76; // x24
  unsigned int v77; // w23
  unsigned int v78; // w8
  __int64 v79; // x8
  int v80; // w9
  int v81; // w9
  int v82; // w10
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // [xsp+0h] [xbp-30h]
  __int64 *v92; // [xsp+8h] [xbp-28h]
  __int64 v93; // [xsp+10h] [xbp-20h] BYREF
  __int64 v94; // [xsp+18h] [xbp-18h] BYREF
  __int64 v95; // [xsp+20h] [xbp-10h]
  __int64 v96; // [xsp+28h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v94 = 0;
  v95 = 0;
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x35u);
  if ( !comp_private_obj )
  {
    v71 = "%s: psoc priv is NULL";
LABEL_36:
    result = qdf_trace_msg(0xA5u, 2u, v71, v3, v4, v5, v6, v7, v8, v9, v10, "wlan_mgmt_rx_srng_reap_buf");
    goto LABEL_37;
  }
  v11 = comp_private_obj;
  pdev_wmi_handle = lmac_get_pdev_wmi_handle(a1, v3, v4, v5, v6, v7, v8, v9, v10);
  if ( !pdev_wmi_handle )
  {
    v71 = "%s: WMI handle is null in mgmt rx srng";
    goto LABEL_36;
  }
  v13 = *(_QWORD *)(v11 + 72);
  v91 = pdev_wmi_handle;
  v14 = *(_DWORD *)(v13 + 120);
  v15 = **(_DWORD **)(v13 + 128);
  v16 = v15 - v14;
  *(_DWORD *)(v13 + 136) = v15;
  if ( v15 <= v14 )
    v16 += *(_DWORD *)(v13 + 36);
  v17 = *(_DWORD *)(v13 + 44);
  v18 = *(_QWORD *)(v11 + 24);
  v93 = 0;
  v19 = v16 / v17;
  hal_srng_access_start_5(v18, v13);
  v28 = v19 - 1;
  if ( v19 - 1 >= 1 )
  {
    v29 = 0;
    v30 = 0;
    v31 = "%s: MGMT RX sring entry NULL";
    v32 = "wlan_mgmt_rx_srng_reap_buf";
    while ( 1 )
    {
      v62 = (__int64 *)v29;
      while ( 1 )
      {
        qdf_mem_set(&v94, 0x10u, 0);
        v41 = *(unsigned int *)(v13 + 120);
        v42 = (unsigned int)(*(_DWORD *)(v13 + 44) + v41) % *(_DWORD *)(v13 + 36);
        if ( v42 == *(_DWORD *)(v13 + 136)
          || (v43 = *(_QWORD *)(v13 + 16),
              *(_DWORD *)(v13 + 120) = v42,
              *(_DWORD *)(v13 + 124) = v42,
              (v44 = v43 + 4 * v41) == 0) )
        {
          qdf_trace_msg(0xA5u, 2u, v31, v33, v34, v35, v36, v37, v38, v39, v40, v32, v91);
          goto LABEL_23;
        }
        if ( (*(_BYTE *)(*(_QWORD *)(v11 + 80) + 24LL * *(int *)(v11 + 88) + 17) & 1) == 0 )
        {
          qdf_trace_msg(0xA5u, 2u, "%s: Received invalid cookie buffer", v33, v34, v35, v36, v37, v38, v39, v40, v32);
          v63 = printk(
                  &unk_9BB309,
                  "0",
                  v32,
                  "../vendor/qcom/opensource/wlan/qcacld-3.0/components/mgmt_rx_srng/core/src/wlan_mgmt_rx_srng.c");
          dump_stack(v63);
          goto LABEL_23;
        }
        v92 = v62;
        v45 = v32;
        v46 = v31;
        v47 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(*(_QWORD *)(v11 + 24) + 74392LL) + 1456LL);
        if ( *((_DWORD *)v47 - 1) != -621572614 )
          __break(0x8228u);
        v47(v44, &v94);
        v48 = wlan_mgmt_rx_srng_alloc_buf(v11, (unsigned int)v95, &v93);
        v49 = *(_QWORD *)(v11 + 80);
        v29 = *(_QWORD *)(v49 + 24LL * *(int *)(v11 + 88));
        if ( v48 )
        {
          v64 = 80;
          if ( (*(_BYTE *)(v29 + 68) & 4) == 0 )
            v64 = 40;
          v50 = *(_QWORD *)(v29 + v64);
          *(_QWORD *)(v49 + 24LL * *(int *)(v11 + 92)) = v29;
          v65 = *(_DWORD *)(v11 + 92);
          v66 = *(_QWORD *)(v11 + 80);
          v93 = v50;
          *(_QWORD *)(v66 + 24LL * v65 + 8) = v50;
          *(_BYTE *)(*(_QWORD *)(v11 + 80) + 24LL * *(int *)(v11 + 92) + 17) = 1;
        }
        else
        {
          _qdf_nbuf_unmap_single(*(_QWORD *)(v11 + 16), *(_QWORD *)(v49 + 24LL * *(int *)(v11 + 88)), 2);
          v50 = v93;
        }
        v51 = *(unsigned __int8 *)(*(_QWORD *)(v11 + 80) + 24LL * *(int *)(v11 + 92) + 16);
        v52 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(v11 + 24) + 74392LL) + 1472LL);
        if ( *(v52 - 1) != -1494657337 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v52)(v44, v50, v51, 0);
        v53 = *(_DWORD *)(v11 + 92) + 1;
        v55 = -v53;
        v54 = -v53 < 0;
        v56 = *(_QWORD *)(v11 + 80) + 24LL * *(int *)(v11 + 88);
        v57 = v53 & 0x7F;
        if ( !v54 )
          v57 = -(v55 & 0x7F);
        *(_DWORD *)(v11 + 92) = v57;
        *(_BYTE *)(v56 + 17) = 0;
        v58 = *(_DWORD *)(v11 + 88) + 1;
        v59 = -v58;
        v54 = -v58 < 0;
        v60 = v58 & 0x7F;
        v61 = v59 & 0x7F;
        if ( !v54 )
          v60 = -v61;
        *(_DWORD *)(v11 + 88) = v60;
        if ( !v48 )
          break;
        v31 = v46;
        v32 = v45;
        v62 = v92;
        ++*(_DWORD *)(v11 + 8);
LABEL_23:
        if ( --v28 <= 0 )
          goto LABEL_39;
      }
      if ( v30 )
      {
        *v92 = v29;
        v67 = *(_QWORD *)(v30 + 72);
        v68 = v67 + 0x1000000;
        v69 = v67 & 0xFFFFFFFF00FFFFFFLL;
        v70 = v68 & 0xFF000000;
      }
      else
      {
        v69 = 0x1000000;
        v30 = v29;
        v70 = *(_QWORD *)(v29 + 72) & 0xFFFFFFFF00FFFFFFLL;
      }
      --v28;
      v31 = v46;
      v32 = v45;
      *(_QWORD *)(v30 + 72) = v70 | v69;
      *(_QWORD *)v29 = 0;
      if ( v28 <= 0 )
        goto LABEL_39;
    }
  }
  v30 = 0;
LABEL_39:
  if ( v13 )
  {
    v73 = v91;
    if ( (*(_DWORD *)(v13 + 76) & 0x80000000) != 0 )
    {
      **(_DWORD **)(v13 + 144) = *(_DWORD *)(v13 + 120);
      v74 = *(_QWORD *)(v13 + 88);
      if ( (v74 & 1) == 0 )
        goto LABEL_42;
    }
    else
    {
      hal_delayed_reg_write(
        *(_QWORD *)(v11 + 24),
        (unsigned __int8 *)v13,
        *(_QWORD *)(v13 + 144),
        *(_DWORD *)(v13 + 120));
      v74 = *(_QWORD *)(v13 + 88);
      if ( (v74 & 1) == 0 )
      {
LABEL_42:
        result = raw_spin_unlock(v13 + 80);
        goto LABEL_43;
      }
    }
    *(_QWORD *)(v13 + 88) = v74 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v13 + 80);
  }
  else
  {
    result = qdf_trace_msg(
               0x38u,
               2u,
               "%s: Error: Invalid hal_ring\n",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "hal_srng_access_end");
    v73 = v91;
  }
LABEL_43:
  if ( v30 )
  {
    while ( 1 )
    {
      v75 = *(_DWORD *)(v30 + 112);
      v76 = *(_QWORD *)v30;
      v77 = **(unsigned __int16 **)(v30 + 224);
      v78 = v77 - v75;
      if ( v77 < v75 )
      {
        skb_trim(v30, **(unsigned __int16 **)(v30 + 224));
        v79 = *(_QWORD *)(v30 + 40);
        if ( !v79 )
          goto LABEL_58;
LABEL_57:
        *(_QWORD *)(v30 + 40) = v79 + 4;
        goto LABEL_58;
      }
      if ( *(_DWORD *)(v30 + 116) )
      {
        v78 = v77 - v75;
        if ( v77 == v75 )
          goto LABEL_56;
        v80 = 0;
      }
      else
      {
        v82 = *(_DWORD *)(v30 + 208);
        v81 = *(_DWORD *)(v30 + 212);
        if ( v81 - v82 >= v78 )
          goto LABEL_56;
        v80 = v82 - v81;
      }
      if ( (unsigned int)pskb_expand_head(v30, 0, v80 + v78, 2080) )
        dev_kfree_skb_any_reason(v30, 1);
LABEL_56:
      skb_put(v30, v77 - *(_DWORD *)(v30 + 112));
      v79 = *(_QWORD *)(v30 + 40);
      if ( v79 )
        goto LABEL_57;
LABEL_58:
      if ( skb_pull(v30, 4) )
      {
        result = wmi_rx_buf_srng(v73, v30);
        v30 = v76;
        if ( !v76 )
          break;
      }
      else
      {
        qdf_trace_msg(
          0xA5u,
          2u,
          "%s: Pkt len insuffficient",
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          "wlan_mgmt_rx_srng_reap_buf");
        result = _qdf_nbuf_free(v30);
        v30 = v76;
        if ( !v76 )
          break;
      }
    }
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
