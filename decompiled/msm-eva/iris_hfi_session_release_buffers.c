__int64 __fastcall iris_hfi_session_release_buffers(_QWORD *a1)
{
  _QWORD *v1; // x19
  _QWORD *v3; // x8
  __int64 inst_from_id; // x0
  __int64 v5; // x22
  __int64 v6; // x9
  _DWORD *v7; // x8
  unsigned int v8; // w0
  unsigned int v9; // w21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  _QWORD v23[3]; // [xsp+0h] [xbp-50h] BYREF
  __int128 v24; // [xsp+18h] [xbp-38h]
  __int64 v25; // [xsp+28h] [xbp-28h]
  __int64 v26; // [xsp+30h] [xbp-20h]
  __int64 v27; // [xsp+38h] [xbp-18h]
  int v28; // [xsp+40h] [xbp-10h]
  __int64 v29; // [xsp+48h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v26 = 0;
  v27 = 0;
  v25 = 0;
  v24 = 0u;
  memset(v23, 0, sizeof(v23));
  if ( a1 && (v1 = (_QWORD *)a1[4]) != nullptr )
  {
    mutex_lock(v1 + 10);
    v3 = v1;
    while ( 1 )
    {
      v3 = (_QWORD *)*v3;
      if ( v3 == v1 )
        break;
      if ( v3 == a1 )
      {
        inst_from_id = cvp_get_inst_from_id(*(_QWORD *)(cvp_driver + 48), HIDWORD(a1) ^ (unsigned int)a1);
        if ( inst_from_id )
        {
          v5 = inst_from_id;
          _X9 = (unsigned __int64 *)(*(_QWORD *)(inst_from_id + 128) + 1296LL);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v21 = __ldxr(_X9);
            v22 = v21 + 1;
          }
          while ( __stlxr(v22, _X9) );
          __dmb(0xBu);
          v6 = v1[302];
          *(_QWORD *)((char *)&v24 + 4) = v22 & 0x7FFFFFFFFFFFFFFFLL;
          if ( !v6 )
            goto LABEL_35;
          v7 = *(_DWORD **)(v6 + 120);
          if ( !v7 )
            goto LABEL_35;
          if ( *(v7 - 1) != -1399385932 )
            __break(0x8228u);
          v8 = ((__int64 (__fastcall *)(_QWORD *, _QWORD *))v7)(v23, a1);
          if ( v8 )
          {
            v9 = v8;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              StatusReg = _ReadStatusReg(SP_EL0);
              printk(&unk_8F46E, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            }
          }
          else
          {
LABEL_35:
            if ( (unsigned int)_iface_cmdq_write(a1[4], (unsigned int *)v23) )
              v9 = -39;
            else
              v9 = 0;
          }
          cvp_put_inst(v5);
        }
        else
        {
          v9 = -22;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v14 = _ReadStatusReg(SP_EL0);
            printk(&unk_86178, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
          }
        }
        goto LABEL_29;
      }
    }
    v9 = -104;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      printk(&unk_963E0, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), "warn");
    }
LABEL_29:
    mutex_unlock(v1 + 10);
  }
  else
  {
    v9 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v11 = _ReadStatusReg(SP_EL0);
      printk(&unk_920BB, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
