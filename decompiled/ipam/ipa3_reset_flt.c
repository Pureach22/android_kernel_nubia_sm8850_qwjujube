__int64 __fastcall ipa3_reset_flt(unsigned int a1, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v8; // x8
  unsigned __int64 v9; // x20
  unsigned int v10; // w26
  __int64 is_ep_support_flt; // x0
  __int64 v12; // x8
  __int64 *v13; // x21
  __int64 v14; // x27
  __int64 v15; // x8
  __int64 *v16; // x28
  __int64 **v17; // x8
  __int64 *v18; // x9
  __int64 v19; // x9
  __int64 v20; // x23
  unsigned int v21; // w22
  unsigned int (__fastcall *v22)(_QWORD); // x8
  unsigned int (__fastcall *v23)(_QWORD); // x8
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0

  if ( a1 < 2 )
  {
    mutex_lock(ipa3_ctx + 29472);
    v8 = ipa3_ctx;
    if ( *(_DWORD *)(ipa3_ctx + 34308) )
    {
      v9 = 0;
      v10 = a1;
      while ( 1 )
      {
        is_ep_support_flt = ipa_is_ep_support_flt((unsigned int)v9);
        if ( (is_ep_support_flt & 1) != 0 )
        {
          if ( v9 >= 0x24 )
          {
            __break(0x5512u);
            return ipa3_install_dflt_flt_rules(is_ep_support_flt);
          }
          v12 = ipa3_ctx + 304 * v9 + 152LL * v10;
          v13 = *(__int64 **)(v12 + 17640);
          v14 = v12 + 17640;
          if ( v13 != (__int64 *)(v12 + 17640) )
            break;
        }
LABEL_12:
        v8 = ipa3_ctx;
        if ( ++v9 >= *(unsigned int *)(ipa3_ctx + 34308) )
          goto LABEL_33;
      }
      while ( 1 )
      {
        v16 = (__int64 *)*v13;
        if ( !ipa3_id_find(*((unsigned int *)v13 + 103)) )
          break;
        if ( (a2 & 1) == 0 || *((_BYTE *)v13 + 421) == 1 )
        {
          v17 = (__int64 **)v13[1];
          if ( *v17 == v13 && (v18 = (__int64 *)*v13, *(__int64 **)(*v13 + 8) == v13) )
          {
            v18[1] = (__int64)v17;
            *v17 = v18;
          }
          else
          {
            _list_del_entry_valid_or_report(v13);
          }
          v19 = v13[49];
          *v13 = 0xDEAD000000000100LL;
          v13[1] = 0xDEAD000000000122LL;
          --*(_DWORD *)(v19 + 16);
          if ( v13[50] && (ipa3_check_idr_if_freed() & 1) == 0 )
            --*(_DWORD *)(v13[50] + 80);
          v20 = *((unsigned __int16 *)v13 + 209);
          v21 = *((_DWORD *)v13 + 103);
          if ( (unsigned int)((__int64 (*)(void))ipahal_get_rule_id_hi_bit)() > (unsigned int)v20
            && (unsigned int)((__int64 (*)(void))ipahal_get_low_rule_id)() <= (unsigned int)v20 )
          {
            idr_remove(*(_QWORD *)(v13[49] + 136), v20);
          }
          v15 = ipa3_ctx;
          *((_DWORD *)v13 + 4) = 0;
          kmem_cache_free(*(_QWORD *)(v15 + 29376), v13);
          ipa3_id_remove(v21);
        }
        v13 = v16;
        if ( v16 == (__int64 *)v14 )
          goto LABEL_12;
      }
      mutex_unlock(ipa3_ctx + 29472);
      return 4294967282LL;
    }
    else
    {
LABEL_33:
      v22 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(v8 + 34176) + 112LL);
      if ( *((_DWORD *)v22 - 1) != 1856640366 )
        __break(0x8228u);
      if ( v22(0) )
        goto LABEL_40;
      v23 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
      if ( *((_DWORD *)v23 - 1) != 1856640366 )
        __break(0x8228u);
      if ( v23(1) )
      {
LABEL_40:
        printk(&unk_3D86F1, "ipa3_reset_flt");
        v24 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v25 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v25 )
          {
            ipc_log_string(v25, "ipa %s:%d fail to commit flt-rule\n", "ipa3_reset_flt", 1944);
            v24 = ipa3_ctx;
          }
          v26 = *(_QWORD *)(v24 + 34160);
          if ( v26 )
          {
            ipc_log_string(v26, "ipa %s:%d fail to commit flt-rule\n", "ipa3_reset_flt", 1944);
            v24 = ipa3_ctx;
          }
        }
        mutex_unlock(v24 + 29472);
        return 0xFFFFFFFFLL;
      }
      else
      {
        mutex_unlock(ipa3_ctx + 29472);
        return 0;
      }
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_reset_flt__rs, "ipa3_reset_flt") )
      printk(&unk_3FB3F2, "ipa3_reset_flt");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d bad parm\n", "ipa3_reset_flt", 1898);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d bad parm\n", "ipa3_reset_flt", 1898);
    }
    return 4294967274LL;
  }
}
