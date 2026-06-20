__int64 __fastcall synx_global_recover_index(
        unsigned int a1,
        char a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 ipclite_feature; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x1
  __int64 result; // x0
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x8
  size_t v21; // x2
  _WORD *v22; // x0
  __int64 v23; // x9
  __int64 v24; // x10
  unsigned int v25; // w21
  int v26; // w23
  __int16 v27; // w8
  unsigned int v28; // w22
  int v29; // w25
  _BOOL4 v30; // w26
  __int64 v31; // x5
  __int64 v32; // x5
  __int64 v33; // x8
  __int64 v34; // x0
  unsigned int v35; // w20
  _QWORD v36[2]; // [xsp+0h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36[0] = 0;
  if ( synx_gmem_2 )
  {
    if ( a1 > 7 || a3 - 1 >= 0xFFF )
    {
      if ( (synx_debug & 1) != 0 )
      {
        printk(&unk_27C7E, &unk_29207, "synx_global_recover_index", 1270, a3, a6);
        result = 4294967274LL;
        goto LABEL_46;
      }
    }
    else
    {
      ipclite_feature = get_ipclite_feature(4);
      if ( (ipclite_feature & 1) != 0 && (a2 & 1) != 0 )
      {
        if ( a1 >= 8 )
        {
          if ( (synx_debug & 1) != 0 )
            printk(&unk_27EB9, &unk_29207, "synx_global_map_core_id", 231, v14, v15);
          v16 = 9;
        }
        else
        {
          v16 = dword_2BF00[a1];
        }
        ipclite_global_spin_bust(a3, v16);
      }
      else if ( (a2 & 1) != 0 && *(unsigned __int16 *)(synx_gmem_2 + 12) == a1 )
      {
        synx_gmem_lock_owner_clear(ipclite_feature, v11, v12, v13, v14, v15);
        _hwspin_unlock(synx_hwlock, 3, 0);
      }
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        result = ipclite_global_spin_lock_timeout((unsigned __int8)a3, 500, v36);
        if ( (_DWORD)result )
          goto LABEL_46;
        v20 = synx_gmem_2;
LABEL_26:
        v21 = (unsigned int)glcoredata_size;
        v22 = (_WORD *)(v20 + glcoredata_size * a3);
        if ( v22[4] && (v23 = (unsigned __int16)v22[6], v24 = 1LL << a1, ((1LL << a1) & v23) != 0) )
        {
          v26 = *(_DWORD *)v22;
          v25 = *((_DWORD *)v22 + 1);
          v27 = v22[4] - 1;
          v28 = *((_DWORD *)v22 + 6);
          v22[6] = v23 & ~(_WORD)v24;
          v22[4] = v27;
          if ( v27 )
          {
            v29 = 0;
            v30 = v26 == 1;
          }
          else
          {
            memset(v22, 0, v21);
            v30 = 0;
            v29 = 1;
          }
        }
        else
        {
          v25 = 0;
          v28 = 0;
          v30 = 0;
          v29 = 0;
        }
        if ( (get_ipclite_feature(4) & 1) != 0 )
        {
          ipclite_global_spin_unlock((unsigned __int8)a3, v36);
          if ( !v30 )
          {
LABEL_35:
            if ( v29 )
            {
              ipclite_global_test_and_clear_bit(a3 & 0x1F, synx_gmem_0 + 4LL * (a3 >> 5));
              if ( (synx_debug & 0x80) != 0 )
                printk(&unk_26815, &unk_25D36, "synx_global_recover_index", 1308, a3, v32);
            }
            result = 0;
            goto LABEL_44;
          }
        }
        else
        {
          v33 = synx_gmem_2;
          if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
          {
            printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v31);
            v33 = synx_gmem_2;
          }
          v34 = synx_hwlock;
          *(_WORD *)(v33 + 12) = 8;
          _hwspin_unlock(v34, 1, v36);
          if ( !v30 )
            goto LABEL_35;
        }
        result = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))synx_global_update_status_core)(a3, a4, 0);
LABEL_44:
        if ( (synx_debug & 8) != 0 )
        {
          v35 = result;
          printk(&unk_2B249, &unk_2A972, "synx_global_recover_index", 1312, v25, v28);
          result = v35;
        }
        goto LABEL_46;
      }
      if ( synx_hwlock )
      {
        result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v36);
        if ( (_DWORD)result )
          goto LABEL_46;
        v20 = synx_gmem_2;
        *(_WORD *)(synx_gmem_2 + 12) = 0;
        goto LABEL_26;
      }
      if ( (synx_debug & 1) != 0 )
      {
        printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v18, v19);
        result = 4294967274LL;
        goto LABEL_46;
      }
    }
    result = 4294967274LL;
    goto LABEL_46;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_267BF, &unk_29207, "synx_global_recover_index", 1265, a5, a6);
  result = 4294967284LL;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
