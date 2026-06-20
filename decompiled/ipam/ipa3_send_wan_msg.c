__int64 __fastcall ipa3_send_wan_msg(unsigned __int64 a1, char a2, char a3)
{
  __int64 *v6; // x19
  __int64 result; // x0
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x8
  __int64 v14; // x10
  unsigned int v15; // w0
  unsigned int v16; // w20
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  unsigned int v21; // w11
  __int64 v22; // x10
  _QWORD *v23; // x11
  __int64 v24; // x12
  __int64 v25; // x14
  __int64 v26; // x13
  __int64 v27; // x14
  __int64 v28; // x12
  __int64 v29; // x13
  __int64 v30; // x14
  unsigned int v31; // w8
  __int64 v32; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v34; // x24
  __int64 (__fastcall *v35)(_QWORD, _QWORD, _QWORD); // x0
  int v36; // [xsp+Ch] [xbp-64h] BYREF
  __int64 v37; // [xsp+10h] [xbp-60h]
  __int64 v38; // [xsp+18h] [xbp-58h]
  __int64 v39; // [xsp+20h] [xbp-50h]
  __int64 v40; // [xsp+28h] [xbp-48h]
  __int64 v41; // [xsp+30h] [xbp-40h]
  __int64 v42; // [xsp+38h] [xbp-38h]
  __int64 v43; // [xsp+40h] [xbp-30h]
  __int64 v44; // [xsp+48h] [xbp-28h]
  __int64 v45; // [xsp+50h] [xbp-20h]
  __int64 v46; // [xsp+58h] [xbp-18h]
  __int64 v47; // [xsp+60h] [xbp-10h]
  __int64 v48; // [xsp+68h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (__int64 *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  if ( v6 )
  {
    while ( 1 )
    {
      if ( inline_copy_from_user((__int64)v6, a1, 0x58u) )
      {
        kfree(v6);
        result = 4294967282LL;
        goto LABEL_20;
      }
      v8 = v6[9];
      v9 = v6[10];
      v45 = v6[8];
      v46 = v8;
      v10 = v6[4];
      v11 = v6[5];
      v47 = v9;
      v41 = v10;
      v42 = v11;
      v12 = v6[7];
      v43 = v6[6];
      v44 = v12;
      v13 = v6[1];
      v37 = *v6;
      v38 = v13;
      v14 = v6[3];
      v39 = v6[2];
      v40 = v14;
      v36 = 5767168;
      LOBYTE(v36) = a2;
      v15 = ipa_send_msg(&v36, v6, ipa3_wan_msg_free_cb);
      if ( v15 )
        break;
      if ( (a3 & 1) == 0 )
        goto LABEL_17;
      mutex_lock(ipa3_ctx + 44800);
      v20 = ipa3_ctx;
      v21 = *(_DWORD *)(ipa3_ctx + 44792);
      if ( v21 < 0xA )
      {
        v22 = ipa3_ctx + 43872;
        v23 = (_QWORD *)(ipa3_ctx + 43872 + 92LL * v21);
        v24 = v42;
        v23[4] = v41;
        v23[5] = v24;
        v25 = v47;
        v26 = v45;
        v23[9] = v46;
        v23[10] = v25;
        v27 = v43;
        v23[7] = v44;
        v23[8] = v26;
        v29 = v37;
        v28 = v38;
        v23[6] = v27;
        *v23 = v29;
        v23[1] = v28;
        v30 = v40;
        v23[2] = v39;
        v23[3] = v30;
        v31 = *(_DWORD *)(v20 + 44792);
        if ( v31 <= 9 )
        {
          *(_DWORD *)(v22 + 92LL * v31 + 88) = v36;
          v32 = ipa3_ctx;
          *(_DWORD *)(ipa3_ctx + 44792) = (*(_DWORD *)(ipa3_ctx + 44792) + 1) % 10;
          mutex_unlock(v32 + 44800);
LABEL_17:
          result = 0;
          goto LABEL_20;
        }
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v34 = *(_QWORD *)(StatusReg + 80);
      v35 = _kmalloc_cache_noprof;
      *(_QWORD *)(StatusReg + 80) = &ipa3_send_wan_msg__alloc_tag;
      v6 = (__int64 *)_kmalloc_cache_noprof(v35, 3520, 88);
      *(_QWORD *)(StatusReg + 80) = v34;
      if ( !v6 )
        goto LABEL_19;
    }
    v16 = v15;
    if ( (unsigned int)__ratelimit(&ipa3_send_wan_msg__rs, "ipa3_send_wan_msg") )
      printk(&unk_3A28DF, "ipa3_send_wan_msg");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa3_send_wan_msg", 1049, v16);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa3_send_wan_msg", 1049, v16);
    }
    kfree(v6);
    result = v16;
  }
  else
  {
LABEL_19:
    result = 4294967284LL;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
