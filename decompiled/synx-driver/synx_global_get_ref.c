__int64 __fastcall synx_global_get_ref(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x20
  unsigned int v12; // w22
  unsigned int v13; // w20
  __int64 v14; // x5
  __int64 v15; // x8
  __int64 v16; // x0
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  if ( synx_gmem_2 )
  {
    if ( a1 - 1 >= 0xFFF )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_27C7E, &unk_29207, "synx_global_get_ref", 944, a1, a6);
      result = 4294967274LL;
    }
    else
    {
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        result = ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, v17);
        if ( !(_DWORD)result )
        {
          v10 = synx_gmem_2;
          goto LABEL_15;
        }
      }
      else if ( synx_hwlock )
      {
        result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v17);
        if ( !(_DWORD)result )
        {
          v10 = synx_gmem_2;
          *(_WORD *)(synx_gmem_2 + 12) = 0;
LABEL_15:
          v11 = v10 + glcoredata_size * a1;
          synx_global_print_data((_WORD *)v11, (__int64)"synx_global_get_ref");
          if ( *(_DWORD *)(v11 + 4) && *(_WORD *)(v11 + 8) )
          {
            v12 = 0;
            ++*(_WORD *)(v11 + 8);
          }
          else
          {
            v12 = -2;
          }
          if ( (get_ipclite_feature(4) & 1) != 0 )
          {
            ipclite_global_spin_unlock((unsigned __int8)a1, v17);
          }
          else
          {
            v15 = synx_gmem_2;
            if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
            {
              printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v14);
              v15 = synx_gmem_2;
            }
            v16 = synx_hwlock;
            *(_WORD *)(v15 + 12) = 8;
            _hwspin_unlock(v16, 1, v17);
          }
          result = v12;
          goto LABEL_31;
        }
      }
      else
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v7, v8);
        result = 4294967274LL;
      }
      if ( (synx_debug & 1) != 0 )
      {
        v13 = result;
        printk(&unk_2981B, &unk_29207, "synx_global_get_ref", 950, a1, v8);
        result = v13;
      }
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_get_ref", 939, a5, a6);
    result = 4294967284LL;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
