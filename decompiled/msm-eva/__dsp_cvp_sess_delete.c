__int64 __fastcall _dsp_cvp_sess_delete(__int64 a1)
{
  char v2; // w8
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  _QWORD *v6; // x8
  _QWORD *v7; // x8
  __int64 v8; // x0
  __int64 v9; // x9
  __int64 *v10; // x8
  void (__fastcall *v11)(_QWORD); // x9
  __int64 v12; // x0
  unsigned __int64 v13; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned int v23; // w10

  v2 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(a1 + 4) = 0;
  if ( (v2 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_870A6, "dsp", "__dsp_cvp_sess_delete", (unsigned int)dword_6C7D4);
  result = get_inst_from_dsp((unsigned int)dword_6C7DC, (unsigned int)dword_6C7D8);
  if ( !result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      result = printk(&unk_92722, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    goto LABEL_34;
  }
  v4 = result;
  result = (__int64)cvp_get_fastrpc_node_with_handle((unsigned int)off_6C7E0);
  if ( !result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v16 = _ReadStatusReg(SP_EL0);
      result = printk(&unk_973E3, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
    }
LABEL_34:
    *(_DWORD *)(a1 + 4) = -1;
    return result;
  }
  v5 = result;
  if ( *(int *)(result + 28) >= 1 )
  {
    _X8 = (unsigned int *)(result + 28);
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 - 1, _X8) );
  }
  mutex_lock(result + 312);
  v6 = *(_QWORD **)(v5 + 296);
  if ( v6 )
  {
    while ( v6 != (_QWORD *)(v5 + 296) && *v6 )
    {
      _ZF = v6 - 2 == (_QWORD *)v4;
      v6 = (_QWORD *)*v6;
      if ( _ZF )
      {
        v7 = *(_QWORD **)(v4 + 24);
        v8 = v4 + 16;
        if ( *v7 == v4 + 16 && (v9 = *(_QWORD *)v8, *(_QWORD *)(*(_QWORD *)v8 + 8LL) == v8) )
        {
          *(_QWORD *)(v9 + 8) = v7;
          *v7 = v9;
        }
        else
        {
          _list_del_entry_valid_or_report(v8);
        }
        *(_QWORD *)(v4 + 16) = 0xDEAD000000000100LL;
        *(_QWORD *)(v4 + 24) = 0xDEAD000000000122LL;
        --*(_DWORD *)(v5 + 20);
        mutex_unlock(v5 + 312);
        v10 = *(__int64 **)(*(_QWORD *)(v4 + 128) + 256LL);
        *(_DWORD *)(v4 + 15408) = 0x7FFFFFFF;
        if ( v10 )
        {
          v11 = (void (__fastcall *)(_QWORD))v10[23];
          if ( v11 )
          {
            v12 = *v10;
            if ( *((_DWORD *)v11 - 1) != -1066802076 )
              __break(0x8229u);
            v11(v12);
          }
        }
        result = msm_cvp_close(v4);
        if ( (_DWORD)result )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v13 = _ReadStatusReg(SP_EL0);
            result = printk(&unk_832BF, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
          }
          goto LABEL_34;
        }
        return result;
      }
    }
  }
  result = mutex_unlock(v5 + 312);
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v15 = _ReadStatusReg(SP_EL0);
    return printk(&unk_93E99, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), "warn");
  }
  return result;
}
