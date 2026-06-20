__int64 __fastcall iris_hfi_session_set_buffers(_QWORD *a1, unsigned int a2, unsigned int a3)
{
  _QWORD *v3; // x19
  _QWORD *v7; // x8
  __int64 inst_from_id; // x0
  __int64 v9; // x21
  __int64 v10; // x9
  _DWORD *v11; // x8
  unsigned int v12; // w0
  unsigned int v13; // w22
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  _QWORD v27[3]; // [xsp+8h] [xbp-68h] BYREF
  __int128 v28; // [xsp+20h] [xbp-50h]
  __int64 v29; // [xsp+30h] [xbp-40h]
  __int64 v30; // [xsp+38h] [xbp-38h]
  __int64 v31; // [xsp+40h] [xbp-30h]
  __int64 v32; // [xsp+48h] [xbp-28h]
  __int64 v33; // [xsp+50h] [xbp-20h]
  __int64 v34; // [xsp+58h] [xbp-18h]
  __int64 v35; // [xsp+60h] [xbp-10h]
  __int64 v36; // [xsp+68h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  v28 = 0u;
  memset(v27, 0, sizeof(v27));
  if ( a1 && a3 && a2 && (v3 = (_QWORD *)a1[4]) != nullptr )
  {
    mutex_lock(v3 + 10);
    v7 = v3;
    while ( 1 )
    {
      v7 = (_QWORD *)*v7;
      if ( v7 == v3 )
        break;
      if ( v7 == a1 )
      {
        inst_from_id = cvp_get_inst_from_id(*(_QWORD *)(cvp_driver + 48), HIDWORD(a1) ^ (unsigned int)a1);
        if ( inst_from_id )
        {
          v9 = inst_from_id;
          _X9 = (unsigned __int64 *)(*(_QWORD *)(inst_from_id + 128) + 1296LL);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v25 = __ldxr(_X9);
            v26 = v25 + 1;
          }
          while ( __stlxr(v26, _X9) );
          __dmb(0xBu);
          v10 = v3[302];
          *(_QWORD *)((char *)&v28 + 4) = v26 & 0x7FFFFFFFFFFFFFFFLL;
          if ( !v10 )
            goto LABEL_38;
          v11 = *(_DWORD **)(v10 + 112);
          if ( !v11 )
            goto LABEL_38;
          if ( *(v11 - 1) != -863892245 )
            __break(0x8228u);
          v12 = ((__int64 (__fastcall *)(_QWORD *, _QWORD *, _QWORD, _QWORD))v11)(v27, a1, a2, a3);
          if ( v12 )
          {
            if ( (msm_cvp_debug & 1) != 0 )
            {
              v13 = v12;
              if ( !msm_cvp_debug_out )
              {
                StatusReg = _ReadStatusReg(SP_EL0);
                printk(&unk_82548, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
              }
            }
            else
            {
              v13 = v12;
            }
          }
          else
          {
LABEL_38:
            if ( (unsigned int)_iface_cmdq_write(a1[4], (unsigned int *)v27) )
              v13 = -39;
            else
              v13 = 0;
          }
          cvp_put_inst(v9);
        }
        else
        {
          v13 = -22;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v18 = _ReadStatusReg(SP_EL0);
            printk(&unk_86178, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
          }
        }
        goto LABEL_31;
      }
    }
    v13 = -104;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v17 = _ReadStatusReg(SP_EL0);
      printk(&unk_963E0, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), "warn");
    }
LABEL_31:
    mutex_unlock(v3 + 10);
    result = v13;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v16 = _ReadStatusReg(SP_EL0);
      printk(&unk_920BB, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
