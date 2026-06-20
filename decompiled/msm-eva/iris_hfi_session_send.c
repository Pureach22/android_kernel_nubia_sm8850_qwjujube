__int64 __fastcall iris_hfi_session_send(_QWORD *a1, unsigned int *a2)
{
  _QWORD *v2; // x19
  _QWORD *v5; // x8
  __int64 v6; // x3
  __int64 result; // x0
  unsigned __int64 v8; // x8
  int v9; // w0
  unsigned __int64 v10; // x8
  int v11; // w8
  __int64 v12; // x8
  _DWORD *v13; // x8
  unsigned __int64 v14; // x8
  int v15; // w20
  unsigned int v16; // w20
  unsigned __int64 v17; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v19; // x8

  if ( a1 && (v2 = (_QWORD *)a1[4]) != nullptr )
  {
    mutex_lock(v2 + 10);
    v5 = v2;
    while ( 1 )
    {
      v5 = (_QWORD *)*v5;
      if ( v5 == v2 )
        break;
      if ( v5 == a1 )
      {
        if ( a2 )
        {
          if ( (msm_cvp_fw_debug & 0x100) != 0 )
          {
            if ( *a2 >= 4 )
            {
              v17 = 0;
              v6 = 0;
              do
              {
                if ( v17 != 48 )
                  v6 = a2[v17 / 4] + (unsigned int)v6;
                v17 += 4LL;
              }
              while ( (*a2 & 0xFFFFFFFC) != v17 );
            }
            else
            {
              v6 = 0;
            }
            a2[13] = v6;
            if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
              printk(&unk_8D043, &unk_84256, "cvp_add_hfi_crc", v6);
          }
          goto LABEL_24;
        }
        v11 = msm_cvp_debug_out;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          printk(&unk_93050, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          v11 = msm_cvp_debug_out;
          if ( (msm_cvp_debug & 1) != 0 )
          {
LABEL_22:
            if ( !v11 )
            {
              v19 = _ReadStatusReg(SP_EL0);
              printk(&unk_94EDE, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), &unk_8E7CE);
            }
          }
        }
        else if ( (msm_cvp_debug & 1) != 0 )
        {
          goto LABEL_22;
        }
LABEL_24:
        v12 = v2[302];
        if ( !v12 )
          goto LABEL_45;
        v13 = *(_DWORD **)(v12 + 144);
        if ( !v13 )
          goto LABEL_45;
        if ( *(v13 - 1) != -1216049086 )
          __break(0x8228u);
        v9 = ((__int64 (__fastcall *)(_QWORD *, unsigned int *))v13)(a1, a2);
        if ( v9 )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v14 = _ReadStatusReg(SP_EL0);
            v15 = v9;
            printk(&unk_82586, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
            v9 = v15;
          }
        }
        else
        {
LABEL_45:
          if ( (unsigned int)_iface_cmdq_write(a1[4], a2) )
            v9 = -39;
          else
            v9 = 0;
        }
        goto LABEL_35;
      }
    }
    v9 = -104;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v10 = _ReadStatusReg(SP_EL0);
      printk(&unk_963E0, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), "warn");
      v9 = -104;
    }
LABEL_35:
    v16 = v9;
    mutex_unlock(v2 + 10);
    return v16;
  }
  else
  {
    result = 4294967277LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_94EB6, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
      return 4294967277LL;
    }
  }
  return result;
}
