__int64 __fastcall hfi_process_session_dump_notify(int a1, unsigned int *a2, __int64 a3)
{
  unsigned int v3; // w5
  unsigned int msg_session_id; // w21
  __int64 *inst_from_id; // x0
  __int64 v9; // x3
  __int64 *v10; // x20
  char v11; // w8
  __int64 v12; // x24
  int v13; // w0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x1
  __int64 v17; // x2
  void *v18; // x0
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  int v22; // w19

  if ( !a2 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(StatusReg + 1800);
    v17 = *(unsigned int *)(StatusReg + 1804);
    v18 = &unk_87782;
    goto LABEL_25;
  }
  v3 = *a2;
  if ( *a2 == 76 )
  {
    msg_session_id = get_msg_session_id((__int64)a2);
    inst_from_id = cvp_get_inst_from_id(*(_QWORD *)(cvp_driver + 48), msg_session_id);
    if ( inst_from_id )
    {
      v10 = inst_from_id;
      *((_DWORD *)inst_from_id + 3747) = a2[17];
      v11 = BYTE1(msm_cvp_debug);
      *((_DWORD *)inst_from_id + 3748) = a2[18];
      if ( (v11 & 0x20) != 0 && !msm_cvp_debug_out )
        printk(&unk_826CC, "sess", msg_session_id, v9);
      v12 = a2[2];
      v13 = hfi_map_err_status(a2[16]);
      if ( v13 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v21 = _ReadStatusReg(SP_EL0);
        v22 = v13;
        printk(&unk_95A25, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
        v13 = v22;
      }
      *(_DWORD *)(a3 + 24) = v13;
      *(_DWORD *)a3 = 28;
      *(_DWORD *)(a3 + 8) = a1;
      *(_DWORD *)(a3 + 12) = 0;
      *(_QWORD *)(a3 + 16) = v12;
      memset((void *)(a3 + 28), 0, 0x2E4u);
      cvp_put_inst(v10);
      return 0;
    }
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v19 = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(v19 + 1800);
    v17 = *(unsigned int *)(v19 + 1804);
    v18 = &unk_86178;
LABEL_25:
    printk(v18, v16, v17, &unk_8E7CE);
    return 4294967274LL;
  }
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v20 = _ReadStatusReg(SP_EL0);
    printk(&unk_88CB5, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
    v3 = *a2;
  }
  if ( v3 <= 0x4C )
    return 4294967274LL;
  else
    return 4294967289LL;
}
