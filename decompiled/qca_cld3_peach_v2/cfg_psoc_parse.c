__int64 __fastcall cfg_psoc_parse(__int64 a1, char *a2)
{
  __int64 result; // x0
  __int64 **comp_private_obj; // x0
  __int64 **v6; // x24
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x22
  __int64 *v9; // x21
  char v10; // w22
  __int64 *v11; // x0
  int v12; // w0
  unsigned int v13; // w20
  unsigned int v20; // w8
  unsigned int v21; // w8
  unsigned int v24; // w9
  __int64 *v25; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(80, 8, "%s: enter", "cfg_psoc_parse");
  if ( !_cfg_global_store )
  {
    result = 4;
    goto LABEL_8;
  }
  result = 4;
  if ( a2 && a1 && _cfg_is_init )
  {
    comp_private_obj = (__int64 **)wlan_objmgr_psoc_get_comp_private_obj(a1, 7);
    if ( *comp_private_obj != (__int64 *)_cfg_global_store )
    {
LABEL_6:
      result = 0;
      goto LABEL_8;
    }
    v6 = comp_private_obj;
    v25 = nullptr;
    v26[0] = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&_cfg_stores_lock);
    }
    else
    {
      raw_spin_lock_bh(&_cfg_stores_lock);
      qword_75CAF0 |= 1uLL;
    }
    if ( (unsigned int)qdf_list_peek_front(&_cfg_stores_list, v26) )
    {
LABEL_16:
      v9 = nullptr;
      v10 = 0;
    }
    else
    {
      while ( 1 )
      {
        v8 = v26[0];
        if ( !strcmp(a2, *(const char **)(v26[0] - 8LL)) )
          break;
        if ( (unsigned int)qdf_list_peek_next(&_cfg_stores_list, v8, v26) )
          goto LABEL_16;
      }
      v9 = (__int64 *)(v8 - 8);
      _X8 = (unsigned int *)(v8 + 16);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 + 1, _X8) );
      v25 = (__int64 *)(v8 - 8);
      v10 = 1;
    }
    if ( (qword_75CAF0 & 1) != 0 )
    {
      qword_75CAF0 &= ~1uLL;
      raw_spin_unlock_bh(&_cfg_stores_lock);
      if ( (v10 & 1) != 0 )
        goto LABEL_19;
    }
    else
    {
      raw_spin_unlock(&_cfg_stores_lock);
      if ( (v10 & 1) != 0 )
      {
LABEL_19:
        *v6 = v9;
        v11 = (__int64 *)_cfg_global_store;
        _X9 = (unsigned int *)(_cfg_global_store + 24);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v20 = __ldxr(_X9);
          v21 = v20 - 1;
        }
        while ( __stlxr(v21, _X9) );
        __dmb(0xBu);
        if ( !v21 )
        {
          cfg_store_free(v11);
          result = 0;
          goto LABEL_8;
        }
        goto LABEL_6;
      }
    }
    result = cfg_store_alloc(a2, (__int64 *)&v25);
    if ( (_DWORD)result )
      goto LABEL_8;
    v9 = v25;
    qdf_mem_copy((_DWORD)v25 + 28, _cfg_global_store + 28, 0x7F68u);
    v12 = qdf_ini_parse(a2);
    if ( v12 )
    {
      v13 = v12;
      qdf_trace_msg(80, 2, "%s: Failed to parse *.ini file @ %s; status:%d", "cfg_ini_parse_to_store", a2, v12);
      cfg_store_put(v9);
      result = v13;
      goto LABEL_8;
    }
    goto LABEL_19;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
