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
  const char *v16; // x28
  const char *v17; // x0
  int v18; // w8
  unsigned int v19; // w21
  __int64 v20; // x2
  unsigned int v22; // w6
  unsigned int v23; // w7
  unsigned int v24; // w5
  __int64 v25; // x0
  __int64 v26; // x23
  __int64 v27; // x0
  unsigned int v28; // w23
  __int64 v29; // x24
  __int64 v30; // x25
  __int64 v31; // x21
  unsigned int v32; // w0
  int v33; // [xsp+6Ch] [xbp-54h]
  const char *v34; // [xsp+70h] [xbp-50h]
  int v35; // [xsp+7Ch] [xbp-44h]
  __int64 v36; // [xsp+80h] [xbp-40h]
  int v37; // [xsp+8Ch] [xbp-34h]
  int v38; // [xsp+90h] [xbp-30h]
  int v39; // [xsp+94h] [xbp-2Ch]
  int v40; // [xsp+98h] [xbp-28h]
  int v41; // [xsp+9Ch] [xbp-24h]
  _QWORD *v42; // [xsp+A0h] [xbp-20h]
  unsigned int v43; // [xsp+ACh] [xbp-14h] BYREF
  __int64 v44; // [xsp+B0h] [xbp-10h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD **)(a1 + 608);
  v5 = osif_cm_mac_to_qca_reason((unsigned int)a2[3]);
  v6 = a2[2];
  v41 = *((unsigned __int8 *)a2 + 4);
  v7 = *v4;
  v40 = *(unsigned __int8 *)(a1 + 74);
  v8 = (unsigned __int16)a2[3];
  v42 = v4;
  v9 = *((unsigned __int8 *)a2 + 17);
  v10 = *((unsigned __int8 *)a2 + 18);
  v11 = *((unsigned __int8 *)a2 + 21);
  v39 = *(unsigned __int8 *)(a1 + 75);
  if ( v8 >= 0xFFEB )
    v12 = 1;
  else
    v12 = (unsigned __int16)a2[3];
  if ( v8 == 65533 )
    v12 = 0;
  v33 = v12;
  v13 = *a2;
  v36 = *(_QWORD *)(v7 + 32);
  v37 = *(unsigned __int8 *)(a1 + 79);
  v38 = *(unsigned __int8 *)(a1 + 76);
  v14 = a2 + 4;
  v35 = *((unsigned __int8 *)a2 + 16);
  v15 = "locally-generated";
  if ( v6 == 6 )
    v15 = (const char *)&unk_8B9E43;
  v34 = v15;
  v16 = (const char *)wlan_cm_reason_code_to_str();
  v17 = (const char *)osif_cm_qca_reason_to_str(v5);
  qdf_trace_msg(
    72,
    4,
    "%s(vdevid-%d): %02x:%02x:%02x:**:**:%02x %s disconnect %02x:%02x:%02x:**:**:%02x cmid 0x%x src %d reason:%u %s vendor:%u %s",
    (const char *)(v36 + 296),
    v41,
    v40,
    v39,
    v38,
    v37,
    v34,
    v35,
    v9,
    v10,
    v11,
    v13,
    v6,
    v33,
    v16,
    v5,
    v17);
  if ( (a2[2] & 0xFFFFFFFE) == 6
    || (wlan_scan_is_locally_generated_entry(*(_QWORD *)(a1 + 152), v14) & 1) != 0 && a2[2] != 18 )
  {
    osif_cm_unlink_bss(a1, v14);
  }
  qdf_spinlock_acquire(v42 + 4);
  v18 = a2[2];
  if ( v18 == 9 || v18 == 16 || (ucfg_cm_is_link_switch_disconnect_resp(a2) & 1) != 0 )
  {
    qdf_trace_msg(72, 8, "%s: ignore internal disconnect", "osif_validate_disconnect_and_reset_src_id");
LABEL_16:
    qdf_spinlock_release(v42 + 4);
    v19 = 4;
    v20 = 2;
    goto LABEL_17;
  }
  v23 = *((_DWORD *)v42 + 6);
  v22 = *((_DWORD *)v42 + 7);
  v24 = a2[2];
  if ( __PAIR64__(*a2, v24) != __PAIR64__(v22, v23) )
  {
    qdf_trace_msg(
      72,
      8,
      "%s: Ignore as cm_id(0x%x)/src(%d) didn't match stored cm_id(0x%x)/src(%d)",
      "osif_validate_disconnect_and_reset_src_id",
      *a2,
      v24,
      v22,
      v23);
    goto LABEL_16;
  }
  osif_cm_reset_id_and_src_no_lock(v42);
  qdf_spinlock_release(v42 + 4);
  v25 = _cfg80211_alloc_event_skb(*(_QWORD *)*v42, *v42, 103, 197, 0, 48, 36, 3264);
  if ( v25 )
  {
    v26 = v25;
    v43 = v5;
    if ( (unsigned int)nla_put(v25, 37, 4, &v43) )
    {
      qdf_trace_msg(72, 2, "%s: DISCONNECT_REASON put fail", "osif_cm_indicate_qca_reason");
      sk_skb_reason_drop(0, v26, 2);
    }
    else
    {
      _cfg80211_send_event_skb(v26, 3264);
    }
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: cfg80211_vendor_event_alloc failed", "osif_cm_indicate_qca_reason");
  }
  v27 = osif_cm_disconnect_comp_ind(a1, a2, 1);
  v28 = a2[3];
  v29 = *((_QWORD *)a2 + 4);
  v30 = (unsigned int)a2[6];
  v31 = *(_QWORD *)(*v42 + 32LL);
  v32 = qdf_mem_malloc_flags(v27);
  cfg80211_disconnected(v31, v28, v29, v30, v6 != 6, v32);
  v20 = 0;
  v19 = 0;
LABEL_17:
  osif_cm_disconnect_comp_ind(a1, a2, v20);
  _ReadStatusReg(SP_EL0);
  return v19;
}
