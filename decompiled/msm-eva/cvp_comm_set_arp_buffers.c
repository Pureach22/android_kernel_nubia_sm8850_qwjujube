__int64 __fastcall cvp_comm_set_arp_buffers(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w6
  unsigned int v3; // w19
  unsigned __int64 StatusReg; // x8
  __int64 arp_bufs; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x22
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 (__fastcall *v18)(__int64, __int64, __int64); // x8
  __int64 v19; // x0
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned int v23; // w19
  unsigned int v24; // w23
  unsigned __int64 v25; // x9

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 128);
    if ( v1 )
    {
      if ( *(_QWORD *)(v1 + 256) )
      {
        v2 = *(_DWORD *)(a1 + 14848);
        if ( (unsigned int)(v2 - 17) <= 0xFFFFFFEF )
        {
          v3 = -22;
          if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_8F936, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
          }
          return v3;
        }
        arp_bufs = cvp_allocate_arp_bufs((_QWORD *)a1, 204800 * v2);
        if ( !arp_bufs )
          return (unsigned int)-12;
        v11 = *(_QWORD *)(a1 + 128);
        v12 = arp_bufs;
        v13 = a1;
        if ( !v11 || (v14 = *(_QWORD *)(v12 + 56)) == 0 || (v15 = *(_QWORD *)(v11 + 256)) == 0 )
        {
          v3 = -22;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v21 = _ReadStatusReg(SP_EL0);
            printk(&unk_972A8, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
            v13 = a1;
          }
          goto LABEL_36;
        }
        v16 = *(unsigned int *)(v14 + 64);
        v17 = *(unsigned int *)(v14 + 80);
        if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
        {
          v23 = *(_DWORD *)(v14 + 64);
          v24 = *(_DWORD *)(v14 + 80);
          printk(&unk_83DCD, "sess", "set_internal_buf_on_fw", (unsigned int)v16);
          v17 = v24;
          v16 = v23;
          v13 = a1;
          v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v15 + 72);
          if ( !v18 )
            goto LABEL_30;
        }
        else
        {
          v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v15 + 72);
          if ( !v18 )
            goto LABEL_30;
        }
        v19 = *(_QWORD *)(v13 + 320);
        if ( *((_DWORD *)v18 - 1) != -1378032659 )
          __break(0x8228u);
        v3 = v18(v19, v16, v17);
        v13 = a1;
        if ( v3 )
        {
          if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          {
LABEL_35:
            if ( v3 == -12 )
              return v3;
LABEL_36:
            cvp_release_arp_buffers(v13, v8, v9, v10);
            return v3;
          }
          v20 = _ReadStatusReg(SP_EL0);
          printk(&unk_95D58, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
LABEL_34:
          v13 = a1;
          goto LABEL_35;
        }
LABEL_30:
        v3 = wait_for_sess_signal_receipt(v13, 13);
        if ( !v3 )
          return v3;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v25 = _ReadStatusReg(SP_EL0);
          printk(&unk_8EEF8, *(unsigned int *)(v25 + 1800), *(unsigned int *)(v25 + 1804), &unk_8E7CE);
        }
        goto LABEL_34;
      }
    }
  }
  v3 = -22;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v22 = _ReadStatusReg(SP_EL0);
    printk(&unk_83D1E, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), &unk_8E7CE);
  }
  return v3;
}
