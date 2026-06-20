__int64 __fastcall osif_disconnect_handler(__int64 a1, int *a2)
{
  _QWORD *v4; // x21
  unsigned int v5; // w25
  int v6; // w22
  __int64 v7; // x10
  unsigned int v8; // w11
  int v9; // w21
  int v10; // w26
  int v11; // w27
  int v12; // w8
  int v13; // w24
  _DWORD *v14; // x23
  const char *v15; // x8
  __int64 v16; // x28
  const char *v17; // x0
  int v18; // w28
  int v19; // w8
  unsigned int v20; // w21
  __int64 v21; // x2
  unsigned int v23; // w6
  unsigned int v24; // w7
  unsigned int v25; // w5
  __int64 v26; // x0
  __int64 v27; // x23
  __int64 v28; // x0
  unsigned int v29; // w23
  __int64 v30; // x24
  __int64 v31; // x21
  __int64 v32; // x22
  unsigned int v33; // w25
  const char *v34; // [xsp+48h] [xbp-78h]
  int v35; // [xsp+6Ch] [xbp-54h]
  const char *v36; // [xsp+70h] [xbp-50h]
  int v37; // [xsp+7Ch] [xbp-44h]
  __int64 v38; // [xsp+80h] [xbp-40h]
  int v39; // [xsp+8Ch] [xbp-34h]
  int v40; // [xsp+90h] [xbp-30h]
  int v41; // [xsp+94h] [xbp-2Ch]
  int v42; // [xsp+98h] [xbp-28h]
  int v43; // [xsp+9Ch] [xbp-24h]
  _QWORD *v44; // [xsp+A0h] [xbp-20h]
  unsigned int v45; // [xsp+ACh] [xbp-14h] BYREF
  __int64 v46; // [xsp+B0h] [xbp-10h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD **)(a1 + 680);
  v5 = osif_cm_mac_to_qca_reason((unsigned int)a2[3]);
  v6 = a2[2];
  v43 = *((unsigned __int8 *)a2 + 4);
  v7 = *v4;
  v42 = *(unsigned __int8 *)(a1 + 74);
  v8 = (unsigned __int16)a2[3];
  v44 = v4;
  v9 = *((unsigned __int8 *)a2 + 17);
  v10 = *((unsigned __int8 *)a2 + 18);
  v11 = *((unsigned __int8 *)a2 + 21);
  v41 = *(unsigned __int8 *)(a1 + 75);
  if ( v8 >= 0xFFEB )
    v12 = 1;
  else
    v12 = (unsigned __int16)a2[3];
  if ( v8 == 65533 )
    v12 = 0;
  v35 = v12;
  v13 = *a2;
  v38 = *(_QWORD *)(v7 + 32);
  v39 = *(unsigned __int8 *)(a1 + 79);
  v40 = *(unsigned __int8 *)(a1 + 76);
  v14 = a2 + 4;
  v37 = *((unsigned __int8 *)a2 + 16);
  v15 = "locally-generated";
  if ( v6 == 6 )
    v15 = (const char *)&unk_98C763;
  v36 = v15;
  v16 = wlan_cm_reason_code_to_str();
  v17 = (const char *)osif_cm_qca_reason_to_str(v5);
  v34 = (const char *)v16;
  v18 = v6;
  qdf_trace_msg(
    72,
    4,
    "%s(vdevid-%d): %02x:%02x:%02x:**:**:%02x %s disconnect %02x:%02x:%02x:**:**:%02x cmid 0x%x src %d reason:%u %s vendor:%u %s",
    (const char *)(v38 + 296),
    v43,
    v42,
    v41,
    v40,
    v39,
    v36,
    v37,
    v9,
    v10,
    v11,
    v13,
    v6,
    v35,
    v34,
    v5,
    v17);
  if ( (a2[2] & 0xFFFFFFFE) == 6
    || (wlan_scan_is_locally_generated_entry(*(_QWORD *)(a1 + 216), v14) & 1) != 0 && a2[2] != 18 )
  {
    osif_cm_unlink_bss(a1, v14);
  }
  qdf_spinlock_acquire(v44 + 4);
  v19 = a2[2];
  if ( v19 == 9 || v19 == 16 || (ucfg_cm_is_link_switch_disconnect_resp(a2) & 1) != 0 )
  {
    qdf_trace_msg(72, 8, "%s: ignore internal disconnect", "osif_validate_disconnect_and_reset_src_id");
LABEL_16:
    qdf_spinlock_release(v44 + 4);
    v20 = 4;
    v21 = 2;
    goto LABEL_17;
  }
  v24 = *((_DWORD *)v44 + 6);
  v23 = *((_DWORD *)v44 + 7);
  v25 = a2[2];
  if ( __PAIR64__(*a2, v25) != __PAIR64__(v23, v24) )
  {
    qdf_trace_msg(
      72,
      8,
      "%s: Ignore as cm_id(0x%x)/src(%d) didn't match stored cm_id(0x%x)/src(%d)",
      "osif_validate_disconnect_and_reset_src_id",
      *a2,
      v25,
      v23,
      v24);
    goto LABEL_16;
  }
  osif_cm_reset_id_and_src_no_lock(v44);
  qdf_spinlock_release(v44 + 4);
  v26 = _cfg80211_alloc_event_skb(*(_QWORD *)*v44, *v44, 103, 197, 0, 48, 36, 3264);
  if ( v26 )
  {
    v27 = v26;
    v45 = v5;
    if ( (unsigned int)nla_put(v26, 37, 4, &v45) )
    {
      qdf_trace_msg(72, 2, "%s: DISCONNECT_REASON put fail", "osif_cm_indicate_qca_reason");
      sk_skb_reason_drop(0, v27, 2);
    }
    else
    {
      _cfg80211_send_event_skb(v27, 3264);
    }
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: cfg80211_vendor_event_alloc failed", "osif_cm_indicate_qca_reason");
  }
  v28 = osif_cm_disconnect_comp_ind(a1, a2, 1);
  v29 = a2[3];
  v30 = *((_QWORD *)a2 + 4);
  v31 = (unsigned int)a2[6];
  v32 = *(_QWORD *)(*v44 + 32LL);
  v33 = qdf_mem_malloc_flags(v28);
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1) & 1) == 0 || (*(_BYTE *)(a1 + 60) & 2) == 0 )
    cfg80211_disconnected(v32, v29, v30, v31, v18 != 6, v33);
  v21 = 0;
  v20 = 0;
LABEL_17:
  osif_cm_disconnect_comp_ind(a1, a2, v21);
  _ReadStatusReg(SP_EL0);
  return v20;
}
