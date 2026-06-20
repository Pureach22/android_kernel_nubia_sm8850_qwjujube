__int64 __fastcall cvp_dsp_thread(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 *v5; // x8
  unsigned __int64 StatusReg; // x21
  __int64 result; // x0
  __int64 v8; // x1
  int v9; // w25
  unsigned int (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  void *v12; // x0
  unsigned __int64 v13; // x8
  unsigned int v14; // w19
  __int64 *v15; // [xsp+0h] [xbp-80h]
  _DWORD v16[28]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v17; // [xsp+78h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(cvp_driver + 48);
  memset(v16, 0, 108);
  if ( v4 )
  {
    v5 = *(__int64 **)(v4 + 256);
    if ( v5 )
    {
      v15 = v5;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        while ( 1 )
        {
          do
            result = wait_for_completion_interruptible(&dword_6C788);
          while ( dword_6C668 == 1 );
          if ( dword_6C668 != 2 )
            break;
          cvp_dsp_send_hfi_queue(result, v8, a3, a4);
        }
        if ( !dword_6C668 )
          goto LABEL_54;
        memset(&v16[1], 0, 104);
        v16[0] = qword_6C7A8;
        if ( (_DWORD)result == -512 )
          break;
        mutex_lock(&unk_6C600);
        if ( dword_6C668 == 1 )
        {
          mutex_unlock(&unk_6C600);
        }
        else
        {
          switch ( (int)qword_6C7A8 )
          {
            case 11:
              mutex_lock(&gfa_cv);
              v9 = dword_6C668;
              if ( dword_6C668 == 3 )
              {
                v16[1] = 0;
                mutex_unlock(&gfa_cv);
              }
              else
              {
                dword_6C668 = 3;
                v10 = (unsigned int (__fastcall *)(_QWORD))v15[19];
                if ( !v10 )
                  goto LABEL_41;
                v11 = *v15;
                if ( *((_DWORD *)v10 - 1) != -1066802076 )
                  __break(0x8228u);
                if ( v10(v11) )
                {
                  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
                    printk(&unk_88756, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
                  dword_6C668 = v9;
                  mutex_unlock(&gfa_cv);
                  v16[1] = 1;
                }
                else
                {
LABEL_41:
                  mutex_unlock(&gfa_cv);
                  v16[1] = 0;
                }
              }
              break;
            case 12:
              v16[1] = 0;
              dword_6C668 = 4;
              break;
            case 13:
              _dsp_cvp_sess_create((__int64)v16);
              break;
            case 14:
              _dsp_cvp_sess_delete((__int64)v16);
              break;
            case 15:
              _dsp_cvp_power_req((__int64)v16);
              break;
            case 17:
              _dsp_cvp_buf_register(v16);
              break;
            case 18:
              _dsp_cvp_buf_deregister((__int64)v16);
              break;
            case 19:
              _dsp_cvp_mem_alloc((__int64)v16);
              break;
            case 20:
              _dsp_cvp_mem_free((__int64)v16);
              break;
            case 21:
              _dsp_cvp_sess_start((__int64)v16);
              break;
            case 22:
              _dsp_cvp_sess_stop((__int64)v16);
              break;
            case 23:
              _dsp_cvp_set_session_name((__int64)v16);
              break;
            case 24:
              _dsp_cvp_pd_init((__int64)v16);
              break;
            case 25:
              ((void (__fastcall *)(_DWORD *))_dsp_cvp_set_session_configs)(v16);
              break;
            default:
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                printk(&unk_87D06, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
              break;
          }
          dword_6C7B4 = -1159857458;
          dword_6C9D8 = -1159857458;
          LODWORD(qword_6C7A8) = -1159857458;
          mutex_unlock(&unk_6C600);
LABEL_43:
          if ( (unsigned int)cvp_dsp_send_cmd(v16) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            printk(&unk_8CC09, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        }
      }
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        printk(&unk_8671B, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      goto LABEL_43;
    }
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = &unk_83118;
      v13 = _ReadStatusReg(SP_EL0);
      goto LABEL_53;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = &unk_935B7;
      v13 = _ReadStatusReg(SP_EL0);
LABEL_53:
      printk(v12, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
  }
LABEL_54:
  if ( (msm_cvp_debug & 0xEFE8) != 0 && !msm_cvp_debug_out )
  {
    v14 = result;
    printk(&unk_890AC, &unk_94624, a3, a4);
    result = v14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
