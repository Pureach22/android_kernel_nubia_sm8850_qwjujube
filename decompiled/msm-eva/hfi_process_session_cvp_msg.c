__int64 __fastcall hfi_process_session_cvp_msg(__int64 a1, __int64 a2, _DWORD *a3)
{
  unsigned int v3; // w19
  __int64 result; // x0
  unsigned __int64 v6; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x1
  __int64 v9; // x2
  void *v10; // x0
  unsigned __int64 v12; // x8
  unsigned int v13; // w19
  unsigned int v14; // w21
  int msg_session_id; // w0
  __int64 v16; // x21
  __int64 *inst_from_id; // x0
  __int64 *v18; // x19
  __int64 v19; // x22
  __int64 v20; // x0
  __int64 *v21; // x23
  unsigned int msg_size; // w0
  size_t v23; // x2
  __int64 *v24; // x22
  unsigned int v25; // w24
  unsigned int v26; // w25
  __int64 pkt_name_from_type; // x0
  unsigned int v28; // w21
  __int64 v29; // x26
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned int v32; // w21
  __int64 msg_errorcode; // x0
  __int64 *v34; // x2
  __int64 **v35; // x1
  __int64 v36; // x0
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x3
  __int64 v40; // x4
  __int64 v41; // x5
  __int64 v42; // x6
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x8
  size_t v45; // x25
  unsigned __int64 aon_time; // [xsp+10h] [xbp-30h]
  __int64 v47; // [xsp+30h] [xbp-10h]
  __int64 v48; // [xsp+38h] [xbp-8h]

  if ( !a2 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v8 = *(unsigned int *)(StatusReg + 1800);
    v9 = *(unsigned int *)(StatusReg + 1804);
    v10 = &unk_87782;
LABEL_9:
    printk(v10, v8, v9, &unk_8E7CE);
    return 4294967274LL;
  }
  if ( *(_DWORD *)a2 >= 0x961u )
  {
    result = 4294967289LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v6 = _ReadStatusReg(SP_EL0);
      printk(&unk_8DD5D, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
      return 4294967289LL;
    }
    return result;
  }
  v3 = *(_DWORD *)a2;
  if ( v3 < (unsigned int)get_msg_size(a2) )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      v13 = *(_DWORD *)(v12 + 1800);
      v14 = *(_DWORD *)(v12 + 1804);
      get_msg_size(a2);
      printk(&unk_922F0, v13, v14, &unk_8E7CE);
      return 4294967274LL;
    }
    return result;
  }
  msg_session_id = get_msg_session_id(a2);
  v16 = *(_QWORD *)(cvp_driver + 48);
  inst_from_id = cvp_get_inst_from_id(v16, msg_session_id);
  if ( !inst_from_id )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v30 = _ReadStatusReg(SP_EL0);
    v8 = *(unsigned int *)(v30 + 1800);
    v9 = *(unsigned int *)(v30 + 1804);
    v10 = &unk_86178;
    goto LABEL_9;
  }
  v18 = inst_from_id;
  v48 = **(_QWORD **)(v16 + 256);
  if ( *(__int64 *)(a2 + 32) >= 0 )
    v19 = 22;
  else
    v19 = 29;
  v20 = cvp_kmem_cache_zalloc(cvp_driver + 72, 3264);
  if ( !v20 )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v31 = _ReadStatusReg(SP_EL0);
      printk(&unk_93129, *(unsigned int *)(v31 + 1800), *(unsigned int *)(v31 + 1804), &unk_8E7CE);
    }
    goto LABEL_42;
  }
  v21 = (__int64 *)v20;
  msg_size = get_msg_size(a2);
  v23 = msg_size;
  if ( msg_size >= 0x13D && (hfi_process_session_cvp_msg___already_done & 1) == 0 )
  {
    hfi_process_session_cvp_msg___already_done = 1;
    v45 = msg_size;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      msg_size,
      "field \"&sess_msg->pkt\" at ../vendor/qcom/opensource/eva-kernel/msm/eva/hfi_response_handler.c:604",
      0x13Cu);
    v23 = v45;
    __break(0x800u);
  }
  v24 = &v18[v19];
  memcpy(v21 + 2, (const void *)a2, v23);
  if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
  {
    v32 = *(_DWORD *)(a2 + 4);
    msg_errorcode = get_msg_errorcode(a2);
    hfi_map_err_status(msg_errorcode);
    printk(&unk_91539, "hfi", "hfi_process_session_cvp_msg", v32);
    if ( (msm_cvp_debug & 0x10000) == 0 )
      goto LABEL_37;
  }
  else if ( (msm_cvp_debug & 0x10000) == 0 )
  {
    goto LABEL_37;
  }
  v25 = *(_DWORD *)(a2 + 4);
  if ( v25 >= 0x4021001 && *(_DWORD *)a2 >= 0x44u )
  {
    v26 = *(_DWORD *)(a2 + 8);
    pkt_name_from_type = get_pkt_name_from_type(v25);
    v28 = *(_DWORD *)(a2 + 56);
    v29 = pkt_name_from_type;
    v47 = *(_QWORD *)(a2 + 40);
    aon_time = get_aon_time();
    trace_tracing_eva_frame_from_sw(aon_time, v26, v28, v25, v29, v47, *(_QWORD *)(a2 + 32) & 0x7FFFFFFFFFFFFFFFLL);
    if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
      printk(&unk_85F5D, "info", aon_time, "EVA_KMD_REV_BEGIN");
  }
LABEL_37:
  raw_spin_lock(v24);
  if ( *((_DWORD *)v24 + 2) >= 0x80u )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v43 = _ReadStatusReg(SP_EL0);
      printk(&unk_88D14, *(unsigned int *)(v43 + 1800), *(unsigned int *)(v43 + 1804), &unk_8E7CE);
    }
    raw_spin_unlock(v24);
    cvp_kmem_cache_free(cvp_driver + 72, v21);
LABEL_42:
    cvp_put_inst(v18);
    return 4294967284LL;
  }
  v34 = v24 + 2;
  v35 = (__int64 **)v24[3];
  if ( v21 == v24 + 2 || v35 == (__int64 **)v21 || *v35 != v34 )
  {
    _list_add_valid_or_report(v21, v35, v34);
  }
  else
  {
    v24[3] = (__int64)v21;
    *v21 = (__int64)v34;
    v21[1] = (__int64)v35;
    *v35 = v21;
  }
  ++*((_DWORD *)v24 + 2);
  raw_spin_unlock(v24);
  if ( (unsigned int)get_msg_errorcode(a2) != 4126 )
    goto LABEL_52;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v44 = _ReadStatusReg(SP_EL0);
    printk(&unk_8D0E3, *(unsigned int *)(v44 + 1800), *(unsigned int *)(v44 + 1804), &unk_8E7CE);
  }
  v36 = cvp_clock_reg_print(v48);
  if ( !msm_cvp_hw_hang_recovery )
  {
    __break(0x800u);
    return trace_tracing_eva_frame_from_sw(v36, v37, v38, v39, v40, v41, v42);
  }
  else
  {
LABEL_52:
    _wake_up(v24 + 4, 3, 0, 0);
    *a3 = 0;
    cvp_put_inst(v18);
    return 0;
  }
}
