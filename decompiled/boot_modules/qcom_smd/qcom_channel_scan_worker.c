__int64 __fastcall qcom_channel_scan_worker(__int64 a1)
{
  __int64 v2; // x27
  __int64 v3; // x26
  char v4; // w8
  unsigned int *v5; // x20
  char v6; // w23
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x28
  __int64 v9; // x21
  unsigned __int64 v16; // x10
  int v17; // w8
  unsigned int v18; // w8
  unsigned int v19; // w25
  int v20; // w22
  unsigned __int64 v21; // x24
  __int64 v22; // x0
  unsigned __int64 v23; // x0
  unsigned __int64 v24; // x25
  __int64 v25; // x8
  unsigned __int64 v26; // x22
  __int64 v27; // x9
  unsigned __int64 v28; // x0
  __int64 v29; // x2
  __int64 v30; // x8
  __int64 result; // x0
  __int64 v32; // [xsp+10h] [xbp-40h]
  __int64 *v33; // [xsp+18h] [xbp-38h]
  __int64 v34; // [xsp+20h] [xbp-30h]
  __int64 v35; // [xsp+28h] [xbp-28h]
  unsigned int v36; // [xsp+34h] [xbp-1Ch]
  size_t v37; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v38[2]; // [xsp+40h] [xbp-10h] BYREF

  v34 = a1 - 56;
  v35 = a1 - 1096;
  v2 = 0;
  v32 = a1 - 24;
  v33 = (__int64 *)(a1 - 72);
  v3 = a1 - 48;
  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _ReadStatusReg(SP_EL0);
  v4 = 1;
  do
  {
    v5 = (unsigned int *)((char *)&smem_items + 12 * v2);
    v6 = v4;
    v7 = qcom_smem_get(*(unsigned int *)(a1 - 164), *v5, 0);
    if ( v7 <= 0xFFFFFFFFFFFFF000LL )
    {
      v8 = v7;
      v9 = 0;
      while ( 1 )
      {
        v17 = *(_DWORD *)(v8 + 24);
        if ( ((*(_QWORD *)(v3 + 8 * v2) >> v9) & 1) != 0 )
          goto LABEL_7;
        if ( !*(_DWORD *)(v8 + 28) )
          goto LABEL_7;
        if ( !*(_BYTE *)v8 )
          goto LABEL_7;
        if ( (v17 & 0x200) == 0 )
          goto LABEL_7;
        if ( *(_DWORD *)(a1 - 168) != (unsigned __int8)v17 )
          goto LABEL_7;
        v19 = v5[1];
        v18 = v5[2];
        v20 = *(_DWORD *)(v8 + 20);
        v37 = 0;
        v38[0] = 0;
        v36 = v18;
        v21 = _kmalloc_cache_noprof(_init_waitqueue_head, 3520, 176);
        if ( !v21 )
          goto LABEL_7;
        *(_QWORD *)v21 = v35;
        v22 = kstrdup(v8, 3264);
        *(_QWORD *)(v21 + 24) = v22;
        if ( !v22 )
          break;
        *(_DWORD *)(v21 + 80) = 0;
        *(_DWORD *)(v21 + 144) = 0;
        _init_waitqueue_head(v21 + 88, "&channel->fblockread_event", &qcom_smd_create_channel___key);
        _init_waitqueue_head(v21 + 40, "&channel->state_change_event", &qcom_smd_create_channel___key_26);
        v23 = qcom_smem_get(*(unsigned int *)(a1 - 164), v19 + v20, &v37);
        LODWORD(v24) = v23;
        if ( v23 >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_22;
        if ( v37 == 88 )
        {
          v25 = 72;
        }
        else
        {
          if ( v37 != 40 )
          {
            dev_err(v35, "channel info of size %zu not supported\n", v37);
            LODWORD(v24) = -22;
LABEL_22:
            kfree(*(_QWORD *)(v21 + 24));
            v26 = (int)v24;
LABEL_23:
            kfree(v21);
            v21 = v26;
            if ( v26 <= 0xFFFFFFFFFFFFF000LL )
              goto LABEL_24;
            goto LABEL_7;
          }
          v25 = 64;
        }
        *(_QWORD *)(v21 + v25) = v23;
        v24 = qcom_smem_get(*(unsigned int *)(a1 - 164), v36 + v20, v38);
        if ( v24 >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_22;
        v38[0] >>= 1;
        v30 = v38[0];
        *(_QWORD *)(v21 + 112) = v24;
        *(_QWORD *)(v21 + 120) = v24 + v30;
        *(_DWORD *)(v21 + 128) = v30;
        qcom_smd_channel_reset(v21);
        if ( v21 <= 0xFFFFFFFFFFFFF000LL )
        {
LABEL_24:
          v27 = raw_spin_lock_irqsave(v34);
          v28 = v21 + 160;
          v29 = *v33;
          if ( *(__int64 **)(*v33 + 8) != v33 || (__int64 *)v28 == v33 || v29 == v28 )
          {
            _list_add_valid_or_report(v28);
          }
          else
          {
            *(_QWORD *)(v29 + 8) = v28;
            *(_QWORD *)(v21 + 160) = v29;
            *(_QWORD *)(v21 + 168) = v33;
            *v33 = v28;
          }
          raw_spin_unlock_irqrestore(v34, v27);
          _X9 = (unsigned __int64 *)(v3 + 8 * v2);
          __asm { PRFM            #0x11, [X9] }
          do
            v16 = __ldxr(_X9);
          while ( __stxr(v16 | (1LL << v9), _X9) );
          _wake_up(v32, 1, 0, 0);
        }
LABEL_7:
        ++v9;
        v8 += 32LL;
        if ( v9 == 64 )
          goto LABEL_2;
      }
      v26 = -12;
      goto LABEL_23;
    }
LABEL_2:
    v4 = 0;
    v2 = 1;
  }
  while ( (v6 & 1) != 0 );
  result = queue_work_on(32, system_wq, a1 + 32);
  _ReadStatusReg(SP_EL0);
  return result;
}
