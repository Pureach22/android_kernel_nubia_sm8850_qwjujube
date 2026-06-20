__int64 __fastcall synx_global_test_status_update_coredata(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        __int64 a5,
        __int64 a6)
{
  char v6; // w20
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 result; // x0
  __int64 v13; // x8
  unsigned int *v14; // x21
  __int16 v15; // w10
  unsigned int v16; // w20
  __int64 v17; // x5
  __int64 v18; // x8
  __int64 v19; // x0
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  if ( synx_gmem_2 )
  {
    v6 = a2;
    if ( a2 > 7 || a1 - 1 >= 0xFFF )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_27C7E, &unk_29207, "synx_global_test_status_update_coredata", 1224, a1, a6);
      result = 4294967274LL;
    }
    else
    {
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        result = ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, v20);
        if ( !(_DWORD)result )
        {
          v13 = synx_gmem_2;
          goto LABEL_16;
        }
      }
      else if ( synx_hwlock )
      {
        result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v20);
        if ( !(_DWORD)result )
        {
          v13 = synx_gmem_2;
          *(_WORD *)(synx_gmem_2 + 12) = 0;
LABEL_16:
          v14 = (unsigned int *)(v13 + glcoredata_size * a1);
          synx_global_print_data(v14, (__int64)"synx_global_test_status_update_coredata");
          if ( *v14 == 1 || *((_WORD *)v14 + 5) )
          {
            v15 = *((_WORD *)v14 + 6);
            ++*((_WORD *)v14 + 4);
            *((_WORD *)v14 + 6) = v15 | (1LL << v6);
            if ( (a4 & 1) != 0 )
              *((_WORD *)v14 + 7) |= 1LL << v6;
            v14[6] = a3;
            v16 = 1;
          }
          else
          {
            v16 = *v14;
            if ( (synx_debug & 8) != 0 )
              printk(&unk_2AE84, &unk_2A972, "synx_global_test_status_update_coredata", 1247, v14[1], *v14);
          }
          if ( (get_ipclite_feature(4) & 1) != 0 )
          {
            ipclite_global_spin_unlock((unsigned __int8)a1, v20);
          }
          else
          {
            v18 = synx_gmem_2;
            if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
            {
              printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v17);
              v18 = synx_gmem_2;
            }
            v19 = synx_hwlock;
            *(_WORD *)(v18 + 12) = 8;
            _hwspin_unlock(v19, 1, v20);
          }
          goto LABEL_32;
        }
      }
      else
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v10, v11);
        result = 4294967274LL;
      }
      if ( (synx_debug & 1) != 0 )
      {
        v16 = result;
        printk(&unk_2981B, &unk_29207, "synx_global_test_status_update_coredata", 1230, a1, v11);
LABEL_32:
        result = v16;
      }
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_test_status_update_coredata", 1219, a5, a6);
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
