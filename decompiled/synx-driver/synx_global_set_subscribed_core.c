__int64 __fastcall synx_global_set_subscribed_core(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  char v6; // w20
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x5
  unsigned int v13; // w20
  __int64 v14; // x8
  __int64 v15; // x0
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  if ( synx_gmem_2 )
  {
    v6 = a2;
    if ( a2 > 7 || a1 - 1 >= 0xFFF )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_27C7E, &unk_29207, "synx_global_set_subscribed_core", 509, a1, a6);
      result = 4294967274LL;
    }
    else
    {
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        result = ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, v16);
        if ( !(_DWORD)result )
        {
          v11 = synx_gmem_2;
LABEL_16:
          *(_WORD *)(v11 + glcoredata_size * a1 + 12) |= 1LL << v6;
          if ( (get_ipclite_feature(4) & 1) != 0 )
          {
            ipclite_global_spin_unlock((unsigned __int8)a1, v16);
          }
          else
          {
            v14 = synx_gmem_2;
            if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
            {
              printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v12);
              v14 = synx_gmem_2;
            }
            v15 = synx_hwlock;
            *(_WORD *)(v14 + 12) = 8;
            _hwspin_unlock(v15, 1, v16);
          }
          result = 0;
          goto LABEL_28;
        }
      }
      else if ( synx_hwlock )
      {
        result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v16);
        if ( !(_DWORD)result )
        {
          v11 = synx_gmem_2;
          *(_WORD *)(synx_gmem_2 + 12) = 0;
          goto LABEL_16;
        }
      }
      else
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v8, v9);
        result = 4294967274LL;
      }
      if ( (synx_debug & 1) != 0 )
      {
        v13 = result;
        printk(&unk_2981B, &unk_29207, "synx_global_set_subscribed_core", 515, a1, v9);
        result = v13;
      }
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_set_subscribed_core", 504, a5, a6);
    result = 4294967284LL;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
