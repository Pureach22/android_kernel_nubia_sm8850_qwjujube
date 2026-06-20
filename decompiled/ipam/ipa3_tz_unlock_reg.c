__int64 __fastcall ipa3_tz_unlock_reg(__int64 a1, unsigned __int16 a2)
{
  int v4; // w20
  unsigned __int64 v5; // x21
  __int64 v6; // x19
  unsigned __int64 v7; // x8
  _QWORD *v8; // x10
  unsigned __int64 v9; // x12
  unsigned __int64 v10; // x14
  unsigned __int64 v11; // x13
  __int64 v12; // x8
  unsigned __int64 v13; // x12
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x0
  int v17; // w0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  int v22; // w20
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v27; // x25

  if ( a1 && a2 )
  {
    v4 = 28 * a2;
    v5 = (v4 + 4095) & 0x3FF000;
    v6 = _kmalloc_noprof(v5, 3520);
    if ( v6 )
    {
      while ( 2 )
      {
        v7 = 0;
        v8 = (_QWORD *)(a1 + 8);
        v9 = v5;
        while ( v5 >= v7 )
        {
          if ( v9 < 8 )
            break;
          v10 = *(v8 - 1) & 0xFFFFFFFFFFFFF000LL;
          *(_QWORD *)(v6 + v7) = v10;
          if ( v5 < v7 + 8 )
            break;
          if ( v9 - 8 < 8 )
            break;
          *(_QWORD *)(v6 + v7 + 8) = v10;
          if ( v5 < v7 + 16 )
            break;
          if ( v9 - 16 < 8 )
            break;
          *(_QWORD *)(v6 + v7 + 16) = *v8;
          if ( v5 < v7 + 24 || v9 - 24 < 4 )
            break;
          v11 = v6 + v7;
          v7 += 28LL;
          v9 -= 28LL;
          v8 += 2;
          *(_DWORD *)(v11 + 24) = 787217;
          if ( 28LL * a2 == v7 )
          {
            v12 = v6 << 8 >> 8;
            v13 = (unsigned __int64)(v12 + 0x8000000000LL) >> 38;
            v14 = memstart_addr + v12 + 0x8000000000LL;
            v15 = v12 - kimage_voffset;
            if ( v13 )
              v16 = v15;
            else
              v16 = v14;
            v17 = qcom_scm_mem_protect_region_id(v16, 28 * (unsigned int)a2);
            if ( !v17 )
            {
              kfree(v6);
              return 0;
            }
            v22 = v17;
            printk(&unk_3C8FF5, "ipa3_tz_unlock_reg");
            v23 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v24 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v24 )
              {
                ipc_log_string(v24, "ipa %s:%d scm call SCM_SVC_MP failed: %d\n", "ipa3_tz_unlock_reg", 8821, v22);
                v23 = ipa3_ctx;
              }
              v25 = *(_QWORD *)(v23 + 34160);
              if ( v25 )
                ipc_log_string(v25, "ipa %s:%d scm call SCM_SVC_MP failed: %d\n", "ipa3_tz_unlock_reg", 8821, v22);
            }
            kfree(v6);
            return 4294967282LL;
          }
        }
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v27 = *(_QWORD *)(StatusReg + 80);
        v5 = (v4 + 4095) & 0x3FF000;
        *(_QWORD *)(StatusReg + 80) = &ipa3_tz_unlock_reg__alloc_tag;
        v6 = _kmalloc_noprof(v5, 3520);
        *(_QWORD *)(StatusReg + 80) = v27;
        if ( v6 )
          continue;
        break;
      }
    }
    return 4294967284LL;
  }
  else
  {
    printk(&unk_3A2904, "ipa3_tz_unlock_reg");
    v19 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967282LL;
    v20 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v20 )
    {
      ipc_log_string(v20, "ipa %s:%d Bad parameters\n", "ipa3_tz_unlock_reg", 8794);
      v19 = ipa3_ctx;
    }
    v21 = *(_QWORD *)(v19 + 34160);
    if ( v21 )
    {
      ipc_log_string(v21, "ipa %s:%d Bad parameters\n", "ipa3_tz_unlock_reg", 8794);
      return 4294967282LL;
    }
    else
    {
      return 4294967282LL;
    }
  }
}
